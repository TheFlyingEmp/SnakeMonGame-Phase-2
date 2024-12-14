#pragma once
#include "Card.h"
#include "Cell.h"

class CardThirteen : public Card
{
	int CardPrice;
	int FeestoPay;

public:

	void ReadCardParameters(Grid* pGrid);

	void Apply(Grid* pGrid, Player* pPlayer);
};

