#pragma once
#include "Card.h"
class CardNine : public Card
{
	int CelltoBeMovedTo;

public:
	void ReadCardParameters(Grid* pGrid);

	void Apply(Grid* pGrid, Player* pPlayer);

};

