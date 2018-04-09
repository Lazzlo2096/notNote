//по сути это повторка mySqlLite.h
#include "ClassSqlite3.h"

static int callback(void *data, int argc, char **argv, char **azColName){
	//Зачем тут статик?

	int i;
	// fprintf(stderr, "%s: ", (const char*)data); // РАЗОБРАТЬСЯ (БАГ):почему то выводить не своевременно в win!
	printf("%s", (const char*)data);
	
	for(i = 0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	
	printf("\n");
	return 0;
}

ClassSqlite3::ClassSqlite3(char *dbName){
	open(dbName);
};

ClassSqlite3::~ClassSqlite3(){
	close();
};

bool ClassSqlite3::open(char *dbName){
	/* Open database */
	if( sqlite3_open(dbName, &db) )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(false);
	} else {
		fprintf(stderr, "Opened database successfully\n");
		return(true);
	}
};

bool ClassSqlite3::close(){
	sqlite3_close(db);
};

bool ClassSqlite3::exec(char *sql, void* data){
	//выполнить функцию callback() над каждым row, результата sql запроса

	/* Execute SQL statement */
	int rc;
	char *zErrMsg = 0;
	//const char* data = "Callback function called";
	// rc = sqlite3_exec(db, sql, callback_wx, /*(void*)*/data, &zErrMsg);
	rc = sqlite3_exec(db, sql, callback, /*(void*)*/data, &zErrMsg);
	if( rc != SQLITE_OK ) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Operation done successfully\n");
	}

	return true; //пока нет обработки ошибок. Всё плохо
};


