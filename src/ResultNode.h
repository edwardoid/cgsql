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

#ifndef RESULTNODE_H
#define RESULTNODE_H

#include "Node.h"

namespace pgn
{
	class Game;
}

BEGIN_CGSQL_NS

class ResultNode: public Node
{
public:
    ResultNode(Node* parent = 0);
    virtual Type type() const;
    virtual bool canAdd(const Type type) const;
    void setResult(GameResult result);
    GameResult result() const;
	bool accept(const pgn::Game* game) const;
protected:
    virtual std::string toString() const;
private:
    GameResult m_result;
};

END_CGSQL_NS

#endif // RESULTNODE_H
