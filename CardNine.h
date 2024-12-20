#pragma once
#include "Card.h"
class CardNine : public Card
{
	int CelltoBeMovedTo;

public:
	CardNine(const CellPosition& pos);

	void ReadCardParameters(Grid* pGrid);

	void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& InFile);
};

