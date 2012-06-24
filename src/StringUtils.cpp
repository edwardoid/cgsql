#include "StringUtils.h"

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

END_CGSQL_NS
