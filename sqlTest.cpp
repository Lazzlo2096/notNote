//g++ ./sqlTest.cpp -o sqlTest -l sqlite3
// #include <iostream>
#include "mySqlLite.h"

int main(int argc, char* argv[]) {

	mySqlLite mySqlNotes;

	/* Create SQL statement */
	char *sql = "SELECT _id, CONTENT from NOTE";


	char *db_name = "5b5-auto.db"; //имееться ввиде что файл должен лежать в директории совпадающей с директорией в консоли
	char *data = "Запись";

	if( mySqlNotes.open(db_name) ){
		mySqlNotes.exec(sql, (void*)data);
	}
	
	return 0;
}