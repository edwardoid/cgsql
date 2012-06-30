#include "StringUtils.h"
#include <sstream>

BEGIN_CGSQL_NS

std::string StringUtils::extract(const std::string& str,
                                 size_t& begin,
                                 size_t& end,
                                 const char delimeter1,
                                 const char delimeter2)
{
    begin = str.find_first_of(delimeter1);
    end = str.size();
    int openedDelmsCount = 1;
    if(begin == std::string::npos)
    {
        end = str.find_first_of(delimeter2);
        if(end == std::string::npos)
        {
            return str;
        }
        end = begin;
        return std::string();
    }
    for(size_t i = begin+1;
        i < end;
        ++i)
    {
        const char c = str[i];
        if(c == delimeter1)
            ++openedDelmsCount;
        else if(c == delimeter2)
            --openedDelmsCount;
        if(0 == openedDelmsCount)
        {
            end = i;
            return str.substr(begin + 1, end++ - begin - 1);
        }
    }
    return std::string();
}

std::string StringUtils::trim(const std::string& str)
{
    return str;
    std::stringstream ss;
    ss << str;
    std::string res;
    ss >> res;
    return res;
}

StringList StringUtils::split(const std::string& str,
                             const std::string& sep)
{
    StringList res;
    size_t beg = 0,
           end = 0;
    while(beg != std::string::npos)
    {
        beg = str.find_first_not_of(sep, end);
        if(beg == std::string::npos)
            break;
        end = str.find_first_of(sep, beg);
        size_t strLen = end;
        if(end != std::string::npos)
            strLen = end - beg;
        res.push_back(str.substr(beg, strLen));
    }

    return res;
}

END_CGSQL_NS
