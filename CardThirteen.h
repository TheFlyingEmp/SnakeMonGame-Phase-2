#pragma once
#include "Card.h"
#include "Cell.h"

class CardThirteen : public Card
{
	int CardPrice;
	int FeestoPay;
	static bool IsBought;

public:
	CardThirteen(const CellPosition& pos);

	void ReadCardParameters(Grid* pGrid);

	void Apply(Grid* pGrid, Player* pPlayer);
};

