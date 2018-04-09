//g++ ./notNote-cli.cpp -o notNote-cli -l sqlite3
// #include <iostream>
#include "ClassSqlite3.h"

int main(int argc, char* argv[]) {
// or /* char const *argv[] */ - зачем const?

	char *db_name = "5b5-auto.db"; //имееться ввиде что файл должен лежать в директории совпадающей с директорией в консоли
	ClassSqlite3 notes_db(db_name);

	// Create SQL statement
	char *sql = "SELECT _id, CONTENT from NOTE";

	char *data = "Запись: \n";

	if( ! notes_db.exec(sql, (void*)data) )
	{
		//онет!! ОШИБКА!!!
	}
	
	return 0;
}