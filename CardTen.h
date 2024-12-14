#pragma once
#include "Card.h"
#include "Cell.h"

class CardTen : public Card
{
	int CardPrice;
	int FeestoPay;

public:
	CardTen(const CellPosition& pos);

	void ReadCardParameters(Grid* pGrid);

	void Apply(Grid* pGrid, Player* pPlayer);
};

