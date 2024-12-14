#include "CardNine.h"

void CardNine::ReadCardParameters(Grid* pGrid) 
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pGrid->PrintErrorMessage("Please, input the number of cells you want the player to be moved...");

	CelltoBeMovedTo = pIn->GetInteger(pOut);
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer) 
{
	pPlayer->Move(pGrid, CelltoBeMovedTo);
}