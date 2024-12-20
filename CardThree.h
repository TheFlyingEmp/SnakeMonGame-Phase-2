#pragma once

#include"Card.h"

class CardThree :public Card
{
public:
	CardThree(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CopyCard on the passed Player
	// by moving  the player to the next Ladder

<<<<<<< HEAD
	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& InFile);

=======
>>>>>>> 4897b028f2cd117db7bf6b02f7f799ccb08e6643
	virtual ~CardThree(); // A Virtual Destructor
};
