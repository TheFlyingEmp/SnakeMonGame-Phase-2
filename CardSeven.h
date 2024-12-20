#pragma once
#include "Card.h"
#include "ApplicationManager.h"
class CardSeven : public Card
{
public:
	CardSeven(const CellPosition& pos);

	void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& InFile);
};

