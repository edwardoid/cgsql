SRC_DIR := ./src/
OBJ_DIR := ./obj/
BIN_DIR := ./bin/
DEP_DIR := ./dep/
LIB_DIR := ./lib/
INC_DIR := $(SRC_DIR)
DOC_DIR := ./doc/
TST_DIR := ./tests/
DBG_DIR := ./debug/
CC:= g++
X64_FLAGS := -fPIC
MAKE:= make
DEB_FLAGS:= -g3
SRC_FILES:=$(wildcard $(SRC_DIR)*.cpp)
OBJ_FILES:=$(patsubst $(SRC_DIR), $(OBJ_DIR),$(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRC_FILES)))
DEFILES:=$(patsubst $(SRC_DIR), $(DEP_DIR),$(patsubst $(SRC_DIR)%.cpp,$(DEP_DIR)%.o,$(SRC_FILES)))
LIBRARY_TARGET := cgsql
TST_SRC_FILES:=$(wildcard $(SRC_DIR)*.cpp)
TST_OBJ_FILES:=$(patsubst $(SRC_DIR), $(OBJ_DIR),$(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRC_FILES)))
TST_DEFILES:=$(patsubst $(SRC_DIR), $(DEP_DIR),$(patsubst $(SRC_DIR)%.cpp,$(DEP_DIR)%.o,$(SRC_FILES)))

.PHONY: all
all: prepare library

.PHONY: library
library: static shared

.PHONY: static
static: prepare $(OBJ_FILES)
	ar -r $(LIB_DIR)lib$(LIBRARY_TARGET).a $(OBJ_FILES)

.PHONY: shared
shared: $(OBJ_FILES)
	$(CC) $(DEB_FLAGS)  $(OBJ_FILES) -shared -o $(LIB_DIR)lib$(LIBRARY_TARGET).so

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(X64_FLAGS) $(DEB_FLAGS) -c $< -I$(INC_DIR) -o $@

$(DEP_DIR)%.dep: prepare $(SRC_DIR)%.cpp
	$(CC) -MM $< -MT "$@ $(patsubst $(DEP_DIR)%.dep,$(OBJ_DIR)%o,$@)" -I$(INC_DIR) -o $@

-include $(DEP_FILES)

.PHONY: prepare
prepare: check
	mkdir -p $(DEP_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)
	mkdir -p $(LIB_DIR)

.PHONY: doc
doc: check
	doxygen

.PHONY: clean
clean: check
	rm -rf $(BIN_DIR)*
	rm -rf $(LIB_DIR)*
	rm -rf $(OBJ_DIR)*
	rm -rf $(DEP_DIR)*
	$(MAKE) --directory=$(TST_DIR) clean
.PHONY: test
test: all
	$(MAKE) --directory=$(TST_DIR) run

.PHONY: debug
debug: all
	$(MAKE) --directory=$(DBG_DIR) clean all debug

.PHONY: install
install: static shared doc
	cp $(LIB_DIR)* /usr/local/lib
	cp $(SRC_DIR)*.h /usr/local/include
	cp -rf $(DOC_DIR)man/man3 /usr/local/man
	rm -rf /usr/local/man/man3/README*
	rm -rf /usr/local/man/man3/.svn
.PHONY: check
check:
	@echo "Checking for $(MAKE)"
	@whereis $(MAKE)
	@echo "Checking for $(CC)"
	@whereis $(CC)
	@echo "Checking for Doxygen"
	@whereis doxygen
	@echo "Checking for cp"
	@whereis cp
	@echo "Checking for rm"
	@whereis rm
	@echo "Checking for mkdir"
	@whereis mkdir
