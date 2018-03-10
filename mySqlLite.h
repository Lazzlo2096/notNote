#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

static int callback(void *data, int argc, char **argv, char **azColName){

	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	
	for(i = 0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	
	printf("\n");
	return 0;
}

class mySqlLite
{
private:
	sqlite3 *db;

public:
	mySqlLite() = default;
	~mySqlLite(){
		sqlite3_close(db);
	};

	bool open(char *dbName){
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
	
	void exec(char *sql, void* data){
		/* Execute SQL statement */
		int rc;
		char *zErrMsg = 0;
		//const char* data = "Callback function called";
		rc = sqlite3_exec(db, sql, callback_wx, /*(void*)*/data, &zErrMsg);
		if( rc != SQLITE_OK ) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
	};


};