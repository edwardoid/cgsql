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

#ifndef ABSTRACTCALCULATIONDATA_H
#define ABSTRACTCALCULATIONDATA_H

#include "CGSQL.h"
#include <CEPiece.h>

namespace pgn
{
	class Game;
}

BEGIN_CGSQL_NS

	class Concept;

	class CGSQL_EXPORT AbstractCalculationData
	{
	public:
		AbstractCalculationData(const pgn::Game* game);
		virtual bool calculate(const char* concept, const char* requieredValue, CE::piece_color color) const = 0;
		inline const pgn::Game* game() const { return m_game; }
	protected:
		const pgn::Game* m_game;
	};
END_CGSQL_NS

#endif // ABSTRACTCALCULATIONDATA_H