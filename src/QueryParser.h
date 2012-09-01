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

#ifndef QUERYPARSER_H
#define QUERYPARSER_H

#include "CGSQL.h"
#include "RootNode.h"
#include <string>

BEGIN_CGSQL_NS

typedef RootNode AST;

class CGSQL_EXPORT QueryParser
{
public:
    QueryParser(const std::string& str = std::string(),
                AST* root = new AST());
    ~QueryParser();
    static
    AST* parse(std::string str,
               AST* root = new AST(),
               const int level = 0);
    AST* ast() const;
private:
    static
    Node* subParse(const std::string& str,
                   const int level);
	static
	void removeComments(std::string& str);

    #ifdef DEBUG_PARSING_LEVELS
    static
    void printLevelOffset(const int level);
    #endif
private:
    AST* m_root;
    std::string m_q;
};

END_CGSQL_NS


#endif // QUERYPARSER_H
