#pragma once
#include "Card.h"
#include "Cell.h"

class CardEleven : public Card
{
	int CardPrice;
	int FeestoPay;
	static bool IsBought;

public:
	CardEleven(const CellPosition& pos);
  
	void ReadCardParameters(Grid* pGrid);

	void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& InFile);
};