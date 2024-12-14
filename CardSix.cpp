#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos)
{
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
	pGrid->UpdatePlayerCell(pPlayer, PlayerNewCellNum); // Move the player to the old cell
}
