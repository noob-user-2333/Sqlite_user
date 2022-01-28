//
// Created by user on 2022/1/26.
//

#ifndef WEBSPIDER_SQLITE_H
#define WEBSPIDER_SQLITE_H

#include <string>
#include <utility>
#include <stdexcept>
#include "sqlite3.h"


struct SqliteData final {
    int depth = 0;
    int col_count = 0;
    char** field_name = nullptr;
    char** values = nullptr;
    SqliteData() = default;
    ~SqliteData(){

    }
};


class Sqlite final{
private:
    std::string _path;
    sqlite3 *_pDb = nullptr;
    sqlite3_stmt * stmt = nullptr;
    char *error_message;

    static int _callback(void *para, int col_count, char** col_values, char** col_name){
        printf("col_count:%d\n",col_count);
        for(int i=0;i<col_count;i++){
            printf("dataName(0x%x):%s data(0x%x):%s\n",col_name[i],col_name[i],col_values[i],col_values[i]);
        }
        return  0;
    }

public:
    constexpr const static char*  DEFAULT_PATH = "/dev/shm/test.db";
    explicit Sqlite(std::string path = DEFAULT_PATH){
        _path = std::move(path);
        sqlite3_open(_path.c_str(),&_pDb);
        if (_pDb == nullptr)
            throw std::invalid_argument(_path);
    }
    ~Sqlite(){
        sqlite3_close(_pDb);
    }




    void create_table(std::string table_name,std::string field_name[]);
    void query(std::string table_name, std::string& field_name = (std::string &) "*", std::string* where = nullptr, std::string* order_by = nullptr,
               std::string* group_by = nullptr, int limit = 128);




};
#endif //WEBSPIDER_SQLITE_H
