//
// Created by user on 2022/1/26.
//

#include "Sqlite.h"

void Sqlite::create_table(std::string table_name,std::string field_name[])
{



}
void Sqlite::query(std::string table_name, std::string& field_name , std::string* where,
                   std::string* order_by,std::string* group_by, int limit){
    std::string SQL = "SELECT " + field_name + " FROM " + table_name;
    const void *temp;
    if(where)
        SQL += " WHERE " + *where;
    if(order_by)
        SQL += " ORDER BY " + *order_by;
    if(group_by)
        SQL += " GROUP BY " + *group_by;
    SQL += " LIMIT " + std::to_string(limit) + ";";

    sqlite3_prepare16_v2(_pDb,SQL.c_str(),SQL.size(),&stmt,&temp);

}