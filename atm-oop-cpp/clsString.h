#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class clsString
{
public:
    static vector<string> Split(string s, string delim)
    {
        vector<string> v;
        size_t pos = 0;
        string token;
        while ((pos = s.find(delim)) != string::npos)
        {
            token = s.substr(0, pos);
            if (token != "")
                v.push_back(token);
            s.erase(0, pos + delim.length());
        }
        if (s != "")
            v.push_back(s);
        return v;
    }

    static string Join(vector<string> v, string delim)
    {
        string result;
        for (size_t i = 0; i < v.size(); i++)
        {
            result += v[i];
            if (i != v.size() - 1)
                result += delim;
        }
        return result;
    }

    static string TrimLeft(string s)
    {
        s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); }));
        return s;
    }

    static string TrimRight(string s)
    {
        s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end());
        return s;
    }

    static string Trim(string s)
    {
        return TrimLeft(TrimRight(s));
    }

    static string ToUpper(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    }

    static string ToLower(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }
};
