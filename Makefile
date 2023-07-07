SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

OUT	:= bf
EXE := $(BIN_DIR)/$(OUT)
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BFFILE ?= $(shell bash -c 'read -p "BF File: " bffile; echo $$bffile')

CFLAGS   := -Werror -g
LDLIBS   := -lm

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC)  $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC)  $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)
clean_web:
	$(RM) index.html
-include $(OBJ:.o=.d)

run: $(EXE)
	$(EXE) $(BFFILE)
	
web: 
	emcc -o index.html $(SRC_DIR)/interpreter.c -O3 --shell-file $(SRC_DIR)/template.html -s MINIFY_HTML=0 -s NO_EXIT_RUNTIME=1 -s "EXPORTED_RUNTIME_METHODS=['ccall']"