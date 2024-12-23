#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) : Card(pos)
{
	cardNumber = 6;
}

void CardSix::ReadCardParameters(Grid* pGrid)
{
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);											
	int DiceValue = pPlayer->GetjustRolledDiceNum();			// Get the dice value 
	CellPosition PlayerNewCellNum = pPlayer->GetCell()->GetCellPosition(); // Get the cell position of the current cell
	PlayerNewCellNum.AddCellNum(-1 * DiceValue); // Get the cell position of the previous cell
	pPlayer->Move(pGrid, CellPosition::GetCellNumFromPosition(PlayerNewCellNum) - DiceValue - 1); // Move the player to the old cell
	pPlayer->SetTurncount(pPlayer->GetTurnCount() - 1);
}

void CardSix::Save(ofstream& OutFile)
{
	OutFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardSix::Load(ifstream& InFile)
{
}