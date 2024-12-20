#pragma once
#include "Card.h"

class CardFive : public Card
{
public:
	CardFive(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& InFile);
};