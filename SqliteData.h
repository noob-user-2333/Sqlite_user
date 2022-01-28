//
// Created by user on 2022/1/28.
//

#ifndef SQLITE_USE_SQLITEDATA_H
#define SQLITE_USE_SQLITEDATA_H

#include <string>
#include <utility>
#include <stdexcept>
#include <vector>
#include <map>
#include "sqlite3.h"

struct SqliteData final {
    static const int INTEGER   = SQLITE_INTEGER;
    static const int FLOAT     = SQLITE_FLOAT;
    static const int TEXT      = SQLITE_TEXT;
    static const int BLOB      = SQLITE_BLOB;
    static const int Null      = SQLITE_NULL;
    int depth = 0;
    int col_count = 0;
    int* col_type = nullptr;
    std::string* field_name = nullptr;
    void **col_values = nullptr;
    SqliteData(sqlite3_stmt *pStmt){
        if(pStmt == nullptr)
            throw std::invalid_argument("pStmt");
        col_count = sqlite3_column_count(pStmt);
        col_type = new int[col_count];
        field_name = new std::string[col_count];
        col_values = new void*[col_count];
        for(int i = 0; i < col_count; i++) {
            col_type[i] = sqlite3_column_type(pStmt, i);
            field_name[i] = sqlite3_column_name(pStmt,i);
            switch(col_type[i]){
                case INTEGER:{
                    col_values[i] = new std::vector<long>();
                    break;
                }
                case FLOAT:{
                    col_values[i] = new std::vector<double>();
                    break;
                }
                case TEXT:
                case BLOB:{
                    col_values[i] = new std::vector<std::string>();
                    break;
                }
                case Null:
                    col_values[i] = nullptr;
                    break;
                default:
                    throw std::bad_typeid();
            }
        }
        while(sqlite3_step(pStmt) == SQLITE_ROW){
            for(int col = 0;col < col_count;col++){
                switch(col_type[col]){



                }
            }
            depth++;
        }

        sqlite3_finalize(pStmt);
    }
    ~SqliteData(){




    }
};


#endif //SQLITE_USE_SQLITEDATA_H
