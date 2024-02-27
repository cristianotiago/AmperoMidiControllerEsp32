#define FORMAT_SPIFFS_IF_FAILED true
const char* data = "Callback function called";
static int callback(void *data, int argc, char **argv, char **azColName) {
   int i;
   Serial.printf("%s: ", (const char*)data);
   for (i = 0; i<argc; i++){
       Serial.printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   Serial.printf("\n");
   return 0;
}

int openDb(const char *filename, sqlite3 **db) {
   int rc = sqlite3_open(filename, db);
   if (rc) {
       Serial.printf("Can't open database: %s\n", sqlite3_errmsg(*db));
       return rc;
   } else {
       Serial.printf("Opened database successfully\n");
   }
   return rc;
}

char *zErrMsg = 0;
int db_exec(sqlite3 *db, const char *sql) {
   Serial.println(sql);
   long start = micros();
   int rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   if (rc != SQLITE_OK) {
       Serial.printf("SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
   } else {
       Serial.printf("Operation done successfully\n");
   }
   Serial.print(F("Time taken:"));
   Serial.println(micros()-start);
   return rc;
}

int db_open(const char *filename, sqlite3 **db) {
   int rc = sqlite3_open(filename, db);
   if (rc) {
       Serial.printf("Can't open database: %s\n", sqlite3_errmsg(*db));
       return rc;
   } else {
       Serial.printf("Opened database successfully\n");
   }
   return rc;
}

void montarBanco(){
  Serial.begin(115200);
   sqlite3 *db1;
   int rc;

   if (!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)) {
       Serial.println("Failed to mount file system");
       return;
   }

   // list SPIFFS contents
   File root = SPIFFS.open("/");
   if (!root) {
       Serial.println("- failed to open directory");
       return;
   }
   if (!root.isDirectory()) {
       Serial.println(" - not a directory");
       return;
   }
   File file = root.openNextFile();
   while (file) {
       if (file.isDirectory()) {
           Serial.print("  DIR : ");
           Serial.println(file.name());
       } else {
           Serial.print("  FILE: ");
           Serial.print(file.name());
           Serial.print("\tSIZE: ");
           Serial.println(file.size());
       }
       file = root.openNextFile();
   }

   //remove existing file
   //SPIFFS.remove("/test1.db");
  //SPIFFS.remove("/test2.db");

   sqlite3_initialize();

   if (db_open("/spiffs/amperosc.db", &db1))
       return;
 

   rc = db_exec(db1, "CREATE TABLE amperosc (id INTEGER,a1 INTEGER,a2 INTEGER,a3 INTEGER,a4 INTEGER,a5 INTEGER,a6 INTEGER,b1 INTEGER,b2 INTEGER,b3 INTEGER,b4 INTEGER,b5 INTEGER,b6 INTEGER);");
   if (rc != SQLITE_OK) {
       sqlite3_close(db1);
    
       return;
   }

  for (int i = 1; i < 11; i++) {
    sqlite3_stmt *res;
  rc = db_exec(db1, "INSERT INTO amperosc VALUES (?, 0,0,0,0,0,0,0,0,0,0,0,0,0);");
  sqlite3_bind_int  (res, 1, i);
   if (rc != SQLITE_OK) {
       sqlite3_close(db1);
     
       return;
   }
}


   sqlite3_close(db1);

}