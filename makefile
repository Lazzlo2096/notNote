.PHONY: all run cli

PROJECT_NAME = notNote
MKDIR_P = mkdir -p
BIN_DIR = bin

EXEC_PROG = $(BIN_DIR)/$(PROJECT_NAME)

all: cli

$(BIN_DIR):
	$(MKDIR_P) $(BIN_DIR)

$(EXEC_PROG): notNote.cpp notNoteForm.cpp $(BIN_DIR)
	g++ notNote.cpp notNoteForm.cpp `wx-config --libs --cxxflags` -l sqlite3 -o $(EXEC_PROG)

sqlTest: sqlTest.cpp $(BIN_DIR)
	g++ -g sqlTest.cpp -o $(BIN_DIR)/sqlTest -l sqlite3

run: $(EXEC_PROG)
	$(EXEC_PROG)

cli: notNote-cli.cpp ClassSqlite3.cpp
	g++ notNote-cli.cpp ClassSqlite3.cpp -o $(BIN_DIR)/notNote-cli -l sqlite3