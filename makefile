.PHONY: all sql run cli

all: bin/notNote

bin/notNote: notNote.cpp notNoteForm.cpp
	g++ notNote.cpp notNoteForm.cpp `wx-config --libs --cxxflags` -l sqlite3 -o bin/notNote

sql: sqlTest.cpp
	g++ -g sqlTest.cpp -o bin/sqlTest -l sqlite3

run:
	bin/notNote

cli: notNote-cli.cpp
	g++ notNote-cli.cpp -o bin/notNote-cli -l sqlite3