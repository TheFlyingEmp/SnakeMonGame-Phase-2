#pragma once
#include "Card.h"
#include "Cell.h"

class CardEleven : public Card
{
	int CardPrice;
	int FeestoPay;

public:
	CardEleven(const CellPosition& pos);

	void ReadCardParameters(Grid* pGrid);

	void Apply(Grid* pGrid, Player* pPlayer);
};