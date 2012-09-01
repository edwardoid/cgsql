/* Copyright (C) 
* 2012 - Edward Sarkisyan <me@edwardsarkisyan.com>
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
* 
*/

#ifndef STRINNGUTILS_H
#define STRINNGUTILS_H

#include "CGSQL.h"
#include <string>
#include <list>

BEGIN_CGSQL_NS

typedef std::list<std::string> StringList;

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
		std::string& ltrim(std::string &s);

		static
		std::string& rtrim(std::string &s);
        
		static
        std::string& trim(std::string& s);
        
        static
        StringList split(const std::string& str,
                         const std::string& sep);
};

END_CGSQL_NS

#endif // STRINNGUTILS_H