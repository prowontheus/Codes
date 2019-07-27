/*
 * FileName:            MyDB.cpp
 * Auther:              Jerry
 * CreateTime:          2019.6.6
 * Latest Update Time:  2019.6.6
 **/

#include <iostream>
#include <string>
#include "string.h"
#include "MyDB.h"
#include <cstdlib>
using namespace std;

/**
 *Function
 **/
MyDB::MyDB()
{
   m_mysql = mysql_init(NULL);
   if(m_mysql == NULL)
   {
       cout << "Error:" <<mysql_error(m_mysql) << endl;
       exit(0);
   }
}

MyDB::~MyDB()
{
    if(m_mysql !=NULL)
    {
        mysql_close(m_mysql);
    }
}

bool MyDB::InitDB(MYSQL *mysql,const char *host,const char* user,const char*password,const char *Db)
{
   /* if(mysql != NULL)
    {
        return true;
    }*/
    m_mysql = mysql_real_connect(mysql,host,user,password,Db,0,NULL,0);
    if(m_mysql)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool MyDB::execSQL(MYSQL *mysql,const char *SqlString)
{
    int bRet = mysql_query(mysql,SqlString);
    if(bRet)
    {
        cout << "Error:" << mysql_error(mysql) << endl;
        return false;
    }
    m_mysqlres = mysql_store_result(mysql);
    if(m_mysqlres != NULL)
    {
        int rows = mysql_num_rows(m_mysqlres);
        int fields = mysql_num_fields(m_mysqlres);
        int i = 0,j = 0;
       // cout << "rows = " << rows << endl << "fields = " << fields << endl;
        MYSQL_FIELD *fd;
        for(i = 0;i < fields;i++)
        {
            m_mysqlrow = mysql_fetch_row(m_mysqlres);
            fd = mysql_fetch_field(m_mysqlres);
            //if (!strcmp(fd->name,"bsegcode"))
                cout << fd->name << ","<< endl;
  //          cout << mysqlrow[1] << endl;
        //    if(!strcmp(mysqlrow[0],"gcc_sta1"))
            {
                /*for(j = 0;j < fields;j++)
                {
                    cout << mysqlrow[j] << "    ";
                }
                cout << endl;
                continue;*/
            }
        }
        mysql_free_result(m_mysqlres);
    }
    return true;
}
