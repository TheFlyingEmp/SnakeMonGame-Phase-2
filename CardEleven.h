#pragma once
#include "Card.h"
#include "Cell.h"

class CardTen : public Card
{
	int CardPrice;
	int FeestoPay;

public:

	void ReadCardParameters(Grid* pGrid);

	void Apply(Grid* pGrid, Player* pPlayer);
};
