#pragma once

#include"Card.h"

class CardFour :public Card
{
public:
	CardFour(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
	// by moving  the player to the next Ladder

	virtual ~CardFour(); // A Virtual Destructor
};