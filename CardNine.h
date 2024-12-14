#pragma once
#include "Card.h"
class CardNine : public Card
{
	void ReadCardParameters(Grid* pGrid);

	void Apply(Grid* pGrid, Player* pPlayer);

};

