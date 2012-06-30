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

#ifndef KEYWORDS_H
#define KEYWORDS_H
#include "CGSQL.h"

BEGIN_CGSQL_NS

#define WHITES            "WHITES"
#define BLACKS            "BLACKS"
#define WINS              "WINS"
#define TIE               "TIE"  

#define HAS               "HAS"
#define HASNT             "HASNT"
#define CONCEPT_DELIMETER "."
#define HEADER_BEGIN      '['
#define HEADER_END        ']'
#define BEGIN             '('
#define END               ')'
#define PLAYER_NAME_QTT   '"'
#define AND_K             "AND"
#define OR_K              "OR"
#define XOR_K             "XOR"
#define COMMENT           '#'


END_CGSQL_NS

#endif // KEYWORDS_H
