//по сути это повторка mySqlLite.h
// но я не заменил потому что боюсь сломать GUI версию

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

class ClassSqlite3{

	sqlite3 *db;

	ClassSqlite3() /*= default*/;
	bool open(char *dbName);
	bool close();

public:
	ClassSqlite3(char *dbName);
	~ClassSqlite3();

	bool exec(char *sql, void* data);
};