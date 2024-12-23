#include "CardNine.h"

CardNine::CardNine(const CellPosition& pos) : Card(pos)
{
	cardNumber = 9;
}

void CardNine::ReadCardParameters(Grid* pGrid) 
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Please, input the number of cells you want the player to be moved...");

	CelltoBeMovedTo = pIn->GetInteger(pOut);
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer) 
{
	Card::Apply(pGrid, pPlayer);

	pGrid->PrintErrorMessage("The player: " + to_string(pPlayer->GetPlayerNum()) + " will be moved to cell " + to_string(CelltoBeMovedTo));

	pPlayer->Move(pGrid, CelltoBeMovedTo);
}

void CardNine::Save(ofstream& OutFile)
{
	OutFile << cardNumber << " " << position.GetCellNum() << " " << CelltoBeMovedTo << endl;
}

void CardNine::Load(ifstream& InFile)
{
	InFile >> CelltoBeMovedTo;
}