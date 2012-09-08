#include "AbstractCalculationData.h"
#include "Debug.h"
#include <PGNGame.h>

BEGIN_CGSQL_NS

AbstractCalculationData::AbstractCalculationData(const pgn::Game* game)
	: m_game(game)
{
	ASSERT(game != NULL);
}

END_CGSQL_NS