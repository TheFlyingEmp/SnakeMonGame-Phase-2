#include "InputDiceValueAction.h"
#include "Player.h"

#include "Grid.h"

InputDiceValue::InputDiceValue(ApplicationManager* pApp) : Action(pApp)
{
}

InputDiceValue::~InputDiceValue()
{
}

void InputDiceValue::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("please enter a dice value between 1 - 6.");
	dicenumber = pIn->GetInteger(pOut);
	while (!(dicenumber >= 1 && dicenumber <= 6))
	{
		pGrid->PrintErrorMessage("Invalid Dice Value.Please put a valid value");
		dicenumber = pIn->GetInteger(pOut);
	}
}
void InputDiceValue::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	if (pGrid->GetEndGame())
		pGrid->PrintErrorMessage("test.");
	Player* pPlayer = pGrid->GetCurrentPlayer();
	pPlayer->Move(pGrid, dicenumber);
	pGrid->AdvanceCurrentPlayer();

	pOut->ClearStatusBar();
}
