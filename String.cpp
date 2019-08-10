#include <iostream>
#include <string.h>

class string
{
    public:
        string()//default constructor
        {
            m_len = 0;
            m_str = new char[1];
            *m_str = '\0';
        }
        string(const char *str)//convert constructor
        {
            if(str != nullptr)
            {
                m_len = strlen(str);
                m_str = new char[m_len+1];
                strcpy(m_str,str);
                *m_str = '\0';
            }
            else
            {
                m_len = 0;
                m_str = new char[1];
                *m_str = '\0';
            }
        }
        string(const string &str)//copy constructor
        {
            m_len = strlen(str.m_str);
            m_str = new char[m_len+1];
            strcpy(m_str,str.m_str);
            *m_str = '\0';
        }
        string &operator =(const string &str)//copy assignment
        {
            if(this == &str)
            {
                return *this;
            }
            else
            {
                delete []m_str;
                m_len = strlen(str.m_str);
                m_str = new char[m_len+1];
                strcpy(m_str,str.m_str);
                *m_str = '\0';
            }
            return *this;
        }
        ~string()//destructor
        {
            if(m_len > 0)
            {
                delete []m_str;
                m_str = NULL;
            }
        }
    private:
        char *m_str;
        int m_len;
};
int main()
{
    return 0;
}
