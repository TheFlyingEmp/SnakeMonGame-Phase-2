#pragma once
#include "Card.h"
#include "Cell.h"

class CardTwelve : public Card
{
	int CardPrice;
	int FeestoPay;

public:
	CardTwelve(const CellPosition& pos);

	void ReadCardParameters(Grid* pGrid);

	void Apply(Grid* pGrid, Player* pPlayer);
};

