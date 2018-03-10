//g++ ./sqlTest.cpp -l sqlite3 -o sqlTest

#include "mySqlLite.h"

int main(int argc, char* argv[]) {

	mySqlLite mySqlNotes;

	/* Create SQL statement */
	char *sql = "SELECT _id, CONTENT from NOTE";


	if( mySqlNotes.open("5b5-auto.db") ){		
		mySqlNotes.exec(sql);
	}
	
	return 0;
}