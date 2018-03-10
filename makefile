.PHONY: all sql run

all: bin/notNote

bin/notNote: notNote.cpp notNoteForm.cpp
	g++ notNote.cpp notNoteForm.cpp `wx-config --libs --cxxflags` -l sqlite3 -o bin/notNote

sql: sqlTest.cpp
	g++ sqlTest.cpp -l sqlite3 -o bin/sqlTest

run:
	bin/notNote