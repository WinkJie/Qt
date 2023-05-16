#ifndef STRUCTMAIN_H
#define STRUCTMAIN_H

//#pragma once
#include <debugapi.h>

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <time.h>

#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
//#include <Windows.h>
#include <io.h>
#include <iostream>
#include <direct.h>

#include <direct.h>
#include <stdio.h>

using namespace std;


class StructMain
{
public:
    StructMain();

    bool Open(string strFileName);
    void Close();

    bool CommonLogInit(string name); //打开默认的log 文件
    bool CommonLogInit(string name, string dir);

    void Enable();
    void Disable();
    bool FilePathExisit(string filepath);
    LPCWSTR s2ws(string& str);
    static string Getstr();
    static string GetstrStdio();


    string GetTimeStr();
    //string StrName;

    template <typename T> void LogOut(const T& value)
    {
        if (m_bEnabled)
        {
            m_tOLogFile << value;
        }
    }

    template <typename T> void LogOutLn(const T& value)
    {
        if (m_bEnabled)
        {
            m_tOLogFile << GetTimeStr() << value << endl;
        }
    }

    void LogOutLn()
    {
        if (m_bEnabled)
        {
            m_tOLogFile << endl;
        }
    }
    /*
         *
         *操作符重写
         */
    template <typename T> StructMain& operator<<(const T& value)
    {
        if (m_bEnabled)
        {
            m_tOLogFile << GetTimeStr().c_str() << value;
            cout << GetTimeStr().c_str() << ":" << value << endl;
        }
        return (*this);
    }

    StructMain& operator<<(ostream& (*_Pfn)(ostream&))
    {
        if (m_bEnabled)
        {
            (*_Pfn)(m_tOLogFile);
        }
        return (*this);
    }

private:
    template<typename T> string ValueToStr(T value)
    {
        ostringstream ost;
        ost << value;
        return ost.str();
    }
private:
    ofstream m_tOLogFile;

    bool m_bEnabled;







};

#endif // STRUCTMAIN_H
