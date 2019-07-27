/***
 * FileName:            MyDB.h
 * Auther:              Jerry
 * Create Time:         2019.6.6
 * Latest Update Time:  2019.6.6
 **/

#ifndef _MYDB_H
#define _MYDB_H

#include <mysql.h>
#include <iostream>
#include <string>
using namespace std;
class MyDB{
    public:
    MyDB();
    ~MyDB();
    bool InitDB(MYSQL *mysql,const char *host,const char *user,const char *password,const char *Db);
    bool execSQL(MYSQL *mysql,const char *SqlString);
    MYSQL *m_mysql;
    //vector<vector<std::string> > m_vecResultList;
private:
    MYSQL_RES *m_mysqlres;
    MYSQL_ROW m_mysqlrow;
};
#endif
