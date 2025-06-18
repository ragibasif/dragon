# Makefile

RESET=\033[0m
BOLD=\033[1m
GREEN=\033[0;92m
RED=\033[0;91m
MAGENTA=\033[0;95m
CYAN=\033[0;96m

ERROR=$(BOLD)$(RED)
SUCCESS=$(BOLD)$(GREEN)
INFO=$(BOLD)$(CYAN)

CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -Weverything -Wvla -O1 -g3 -pedantic -v -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
DBG = gdb
LDFLAGS := -v -lc

BUILD_DIRECTORY := build

EXECUTABLE := dragon
EXEC_PATH := $(BUILD_DIRECTORY)/$(EXECUTABLE)

SRCS := $(wildcard *.c) $(wildcard */*.c)
HDRS := $(wildcard *.h) $(wildcard */*.h)
OBJS := $(patsubst %.c, $(BUILD_DIRECTORY)/%.o, $(SRCS))


.PHONY: all clean help run test check debug

all: $(EXEC_PATH)

check:
	@which $(CC) > /dev/null && echo "$(SUCCESS)✅ SUCCESS:$(RESET) $(CC) is installed" || echo "$(ERROR)❌ ERROR:$(RESET) $(CC) not found, please install $(CC)"
	@which $(DBG) > /dev/null && echo "$(SUCCESS)✅ SUCCESS:$(RESET) $(DBG) is installed" || echo "$(ERROR)❌ ERROR:$(RESET) $(DBG) not found, please install $(DBG)"

$(EXEC_PATH): $(OBJS)
	@echo "🔧 Linking $(INFO)$@$(RESET) ..."
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) && \
		echo "$(SUCCESS)✅ Build successful:$(RESET) $@" || \
		(echo "$(ERROR)❌ Linking failed:$(RESET) $@" && exit 1)

$(BUILD_DIRECTORY)/%.o: %.c
	@echo "🔧 Compiling $(INFO)$<$(RESET) ..."
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ && \
		echo "$(SUCCESS)✅ Compiled:$(RESET) $<" || \
		(echo "$(ERROR)❌ Compile failed:$(RESET) $<" && exit 1)


debug: $(EXEC_PATH)
	@$(DBG) ./$(EXEC_PATH)

clean:
	@echo "$(INFO)make clean$(RESET) $(RM) -r $(EXEC_PATH) $(OBJS) $(BUILD_DIRECTORY) *~ *.bak *.dSYM *.out .*.un~"
	@$(RM) -r $(EXEC_PATH) $(OBJS) $(BUILD_DIRECTORY) *~ *.bak *.dSYM *.out .*.un~


run: $(EXEC_PATH)
	@echo "$(INFO)make run$(RESET)"
	@make clean
	@make all
	@./$(EXEC_PATH)
	@make clean


help:
	@echo "$(INFO)make help$(RESET)"
	@echo "Makefile for Building $(INFO)$(EXECUTABLE)$(RESET)."
	@echo "Usage:"
	@echo "  $(MAGENTA)make$(RESET)             — build $(INFO)$(EXECUTABLE)$(RESET)"
	@echo "  $(MAGENTA)make all$(RESET)         — build $(INFO)$(EXECUTABLE)$(RESET)"
	@echo "  $(MAGENTA)make check$(RESET)       — dependency check for $(INFO)$(CC)$(RESET) and $(INFO)$(DBG)$(RESET)"
	@echo "  $(MAGENTA)make clean$(RESET)       — remove $(INFO)$(BUILD_DIRECTORY)$(RESET) files"
	@echo "  $(MAGENTA)make debug$(RESET)       — run $(INFO)$(EXECUTABLE)$(RESET) with $(INFO)$(DBG)$(RESET)"
	@echo "  $(MAGENTA)make run$(RESET)         — run $(INFO)$(EXECUTABLE)$(RESET)"

