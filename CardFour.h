#pragma once

#include"Card.h"

class CardFour :public Card
{
public:
	CardFour(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
<<<<<<< HEAD
	// by moving  the player to the next Ladder
	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& InFile);
=======
	// by moving the player to the next Ladder
>>>>>>> 4897b028f2cd117db7bf6b02f7f799ccb08e6643

	virtual ~CardFour(); // A Virtual Destructor
};