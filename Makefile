# COMPILER CONFIG
CC := clang
STD := -std=c23
STRICT_FLAGS := -Wall -Wextra -Werror \
	-Wshadow -Wpedantic -Wconversion -Wsign-conversion \
	-Wstrict-prototypes -Wmissing-prototypes \
	-Wold-style-definition -Wfloat-equal -Wundef -Wcast-align \
	-Wbad-function-cast -Winline -Wmissing-declarations
SANITIZE_FLAGS := # -fsanitize=address,integer,undefined
LINK_FLAGS := -lncurses
DIAG_FLAGS := -ferror-limit=0 -fdiagnostics-color=always
CC_FLAGS := $(STRICT_FLAGS) $(STD) $(SANITIZE_FLAGS) $(DIAG_FLAGS)
LD_FLAGS := $(STRICT_FLAGS) $(LINK_FLAGS)

# PROJECT CONFIG
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
TARGET := $(BIN_DIR)/lownoisegame

# FILES
SRC_FILES := $(shell find $(SRC_DIR) -name '*.c')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# DEFAULT TARGET
all: $(TARGET)

# BUILD TARGET
$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
	@echo "[$(CC)] Linking $@"
	$(CC) $(OBJ_FILES) -o $@ $(LD_FLAGS)

# COMPILE MAIN SOURCES
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@echo "[$(CC)] Compiling $<"
	$(CC) -c $< -o $@ $(CC_FLAGS)

# CREATE DIRECTORIES
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# CLEAN TARGET
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean
