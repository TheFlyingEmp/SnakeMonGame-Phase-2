#include "CardFive.h"

using namespace std;

CardFive::CardFive(const CellPosition& pos) : Card(pos)
{
	cardNumber = 5;
}

void CardFive::ReadCardParameters(Grid* pGrid)
{
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int DiceValue = pPlayer->GetjustRolledDiceNum();			// Get the dice value 
	CellPosition PlayerNewCellNum = pPlayer->GetCell()->GetCellPosition(); // Get the cell position of the current cell
	PlayerNewCellNum.AddCellNum(DiceValue); // Get the cell position of the next cell
	pGrid->UpdatePlayerCell(pPlayer, PlayerNewCellNum); // Move the player to the next cell
}

void CardFive::Save(ofstream& OutFile)
{
	OutFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardFive::Load(ifstream& InFile)
{
}
