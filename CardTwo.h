#pragma once

#include "Card.h"

class CardTwo : public Card
{
	int walletAmount; // the wallet value to increase to the player
public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTwo which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
	// by incrementing the player's wallet by the walletAmount data member

<<<<<<< HEAD
	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& InFile);

=======
>>>>>>> 4897b028f2cd117db7bf6b02f7f799ccb08e6643
	virtual ~CardTwo(); // A Virtual Destructor
};
