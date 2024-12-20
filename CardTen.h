#pragma once
#include "Card.h"
#include "Cell.h"
#include <fstream>

class CardTen : public Card
{
	int CardPrice;
	int FeestoPay;
	static bool IsBought;
	static bool PlayerHasCard;

public:
	CardTen(const CellPosition& pos);

	void ReadCardParameters(Grid* pGrid);

	void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& InFile);
};

