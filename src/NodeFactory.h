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

#ifndef NODEFACTORY_H
#define NODEFACTORY_H

#include "CGSQL.h"


BEGIN_CGSQL_NS

class Node;

class NodeFactory
{
public:
    static
    Node* nodeFromString(const std::string& str);

private:
    static
    Node* strContainsColorInformation(const std::string& str);

    static
    bool strIsPlayerName(const std::string& str);

    static 
    bool strIsConcept(const std::string& str);

    static 
    bool strIsLogic(const std::string& str);

    static
    Node* logicNodeByStr(const std::string& str);
};

END_CGSQL_NS

#endif // NODEFACTORY_H
