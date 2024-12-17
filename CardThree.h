#pragma once

#include"Card.h"

class CardThree :public Card
{
public:
	CardThree(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CopyCard on the passed Player
	// by moving  the player to the next Ladder

	virtual ~CardThree(); // A Virtual Destructor
};
