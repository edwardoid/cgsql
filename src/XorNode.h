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

#ifndef XORNODE_H
#define XORNODE_H

#include "LogicalBase.h"

BEGIN_CGSQL_NS

class XorNode: public LogicalBase
{
public:
    XorNode(Node* parent = 0);
    virtual ~XorNode();
	virtual bool accept(const pgn::Game* game) const;
protected:
    virtual std::string toString() const;
};

END_CGSQL_NS

#endif // XORNODE_H
