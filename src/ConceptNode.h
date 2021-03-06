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

#ifndef CONCEPTNODE_H
#define CONCEPTNODE_H

#include "Node.h"
#include <string>


BEGIN_CGSQL_NS

class ConceptNode: public Node
{
public:
    ConceptNode(Node* parent = 0,
            const std::string& name = std::string());
    virtual ~ConceptNode();
    virtual Node::Type type() const;
    virtual bool canAdd(const Node::Type type) const;
    virtual void setName(const std::string& name);
    std::string name() const;
    void setRequieredValue(const std::string& value);
    std::string requieredValue() const;
    virtual void setLeft(Node*);
    virtual void setRight(Node*);
	virtual bool accept(AbstractCalculationData* data) const;
protected:
    virtual std::string toString() const;
	CE::piece_color color(bool* ok) const;
private:
    std::string m_requieredValue;
    std::string m_name;
};

END_CGSQL_NS

#endif // CONCEPTNODE_H 
