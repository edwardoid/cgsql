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

#ifndef QUERYPRINTER_H
#define QUERYPRINTER_H

#include "CGSQL.h"
#include "Node.h"
#include "Query.h"

#include <ostream>

BEGIN_CGSQL_NS

typedef class RootNode AST;

class QueryPrinter
{
public:
    QueryPrinter(const Query& q);
    QueryPrinter(const AST* ast);
    friend std::ostream operator << (std::ostream&,
                                     const QueryPrinter& p);
private:
    const AST* m_ast;
};

END_CGSQL_NS

#endif // QUERYPRINTER_H
