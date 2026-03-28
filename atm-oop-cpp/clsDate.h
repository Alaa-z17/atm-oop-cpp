#pragma once

#include <string>
#include <vector>
#include "clsString.h"

using namespace std;

class clsDate
{
private:
    short _Day, _Month, _Year;

public:
    clsDate() : _Day(0), _Month(0), _Year(0) {}

    clsDate(short day, short month, short year) : _Day(day), _Month(month), _Year(year) {}

    clsDate(string sDate)
    {
        vector<string> v = clsString::Split(sDate, "/");
        _Day = stoi(v[0]);
        _Month = stoi(v[1]);
        _Year = stoi(v[2]);
    }

    short GetDay() { return _Day; }
    short GetMonth() { return _Month; }
    short GetYear() { return _Year; }

    static bool IsValidDate(clsDate d)
    {
        if (d._Day < 1 || d._Day > 31) return false;
        if (d._Month < 1 || d._Month > 12) return false;
        if (d._Month == 2)
        {
            bool leap = (d._Year % 4 == 0 && d._Year % 100 != 0) || (d._Year % 400 == 0);
            if (leap)
                return d._Day <= 29;
            else
                return d._Day <= 28;
        }
        short daysInMonth = 31;
        if (d._Month == 4 || d._Month == 6 || d._Month == 9 || d._Month == 11)
            daysInMonth = 30;
        return d._Day <= daysInMonth;
    }

    static bool IsValidDate(string sDate)
    {
        clsDate d(sDate);
        return IsValidDate(d);
    }
};

