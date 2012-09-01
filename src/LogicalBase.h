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

#ifndef LOGICALBASE_H
#define LOGICALBASE_H

#include "Node.h"

BEGIN_CGSQL_NS

class LogicalBase: public Node
{
public:
    LogicalBase(Node* parent);
    virtual ~LogicalBase();
    virtual Node::Type type() const;
    virtual bool canAdd(const Node::Type type) const;
};

END_CGSQL_NS

#endif // LOGICALBASE_H
