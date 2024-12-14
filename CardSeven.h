#pragma once
#include "Card.h"
class CardSeven : public Card
{
public:
	CardSeven(const CellPosition& pos);

	void Apply(Grid* pGrid, Player* pPlayer);

};

