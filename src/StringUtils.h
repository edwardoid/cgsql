#ifndef STRINNGUTILS_H
#define STRINNGUTILS_H

#include "CGSQL.h"
#include <string>

BEGIN_CGSQL_NS


class StringUtils
{
    public:
        static
        std::string extract(const std::string& str,
                            size_t& begin,
                            size_t& end,
                            const char delimeter1,
                            const char delimeter2);
        static
        std::string trim(const std::string& str);
};

END_CGSQL_NS

#endif // STRINNGUTILS_H
