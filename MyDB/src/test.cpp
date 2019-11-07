/**
 *FileName:             test.cpp
 *Auther:               Jerry
 *Create Time:          2019.6.6
 *Latest Update Time:   2019.6.6
 * */

#include <iostream>
#include <cstdlib>
#include "MyDB.h"
using namespace std;

int main(int argc,char *argv[])
{
    MyDB db;
    bool bRet = db.InitDB(db.m_mysql,"localhost","root","123456","secu");
    if(!bRet)
    {
        cout << "InitDB Error:" << mysql_error(db.m_mysql) << endl;
        exit(0);
    }
    /*bRet = db.execSQL(db.mysql,"insert into tdac_yc values('0','grp_pcs1bat','grp_pcs1bat_1_zzt','grp_pcs1bat_1状态','-1','-1','-1','0','-1','-1','1','0','0','9999999','-9999999','0','0','-1','batgrp1');");
    if(!bRet)
    {
        cout << "execError1:" << mysql_error(db.mysql) << endl;
        exit(0);
    }
    bRet = db.execSQL(db.mysql,"insert into tdac_yc values('1','grp_pcs1bat','grp_pcs1bat_1_jy','grp_pcs1bat_1绝缘','-1','-1','-1','0','-1','-1','1','0','0','9999999','-9999999','0','0','-1','batgrp1');");
    if(!bRet)
    {
        cout << "execError2:" << mysql_error(db.mysql) << endl;
        exit(0);
    }*/
    bRet = db.execSQL(db.m_mysql,"select * from tdac_pcs");
    if(!bRet)
    {
        cout << "select Error:" << mysql_error(db.m_mysql) << endl;
        exit(0);
    }
    return 0;
}
