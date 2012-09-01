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

#ifndef ROOTNODE_H
#define ROOTNODE_H

#include "CGSQL.h"
#include "Node.h"

BEGIN_CGSQL_NS

typedef Node Header;
typedef Node Body;

class CGSQL_EXPORT RootNode: public Node
{
public:
    RootNode();
    virtual ~RootNode();
    virtual Node::Type type() const;
    virtual bool canAdd(const Node::Type) const;
    void setHeader(Header* header);
    void setBody(Body* body); 
    Header* header() const;
    Body* body() const;
    virtual std::string toString() const;
};

END_CGSQL_NS

#endif // ROOTNODE_H
