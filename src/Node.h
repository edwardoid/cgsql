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

#ifndef NODE_H
#define NODE_H

#include "CGSQL.h"
#include "AbstractCalculationData.h"
#include <list>
#include <ostream>

BEGIN_CGSQL_NS

class CGSQL_EXPORT Node
{
public:
    typedef enum
    {
        Root = 1,
        Player,
        Color,
        Result,
        Has,
        Logical,
        Concept
    } Type;

    typedef enum
    {
        Whites = 0,
        Blacks
    } NodeColor;

    typedef enum
    {
        WhitesWins = 0,
        BlacksWins,
        Tie
    } GameResult;

    typedef enum
    {
        Yes = 0,
        No
    } HasAbility;

public:
    Node(Node* parent = 0);
    virtual void setParent(Node* parent);
    virtual Node* parent() const;
    virtual Type type() const = 0;
    virtual void setLeft(Node* left);
    virtual void setRight(Node* right);
    virtual Node* left() const;
    virtual Node* right() const;
    virtual bool canAdd(const Type type) const = 0;
    virtual ~Node();
    virtual std::string toString() const = 0;
	virtual bool accept(AbstractCalculationData* data) const;
    static std::string toString(const HasAbility ability);
    static std::string toString(const NodeColor color);
    static std::string toString(const GameResult result);
	std::list<Node*> childListByType(Type type, std::list<Node*>& list = std::list<Node*>());
private:
    Node* m_parent;
    Node* m_left;
    Node* m_right;
};

typedef std::list<Node*> NodeList;

END_CGSQL_NS

#endif // NODE_H
