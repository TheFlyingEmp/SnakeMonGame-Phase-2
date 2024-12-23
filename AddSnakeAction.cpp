#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"


AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell...");
	CellPosition TempstartPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	CellPosition TempendPos = pIn->GetCellClicked();

	if ((TempendPos.VCell() <= TempstartPos.VCell()) || (TempendPos.HCell() != TempendPos.HCell()))
	{
		pGrid->PrintErrorMessage("Invalid input detected, Click anywhere to continue ");
		return;
	}
	else
	{
		startPos = TempstartPos;
		endPos = TempendPos;
	}

	///TODO: Make the needed validations on the read parameters



	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Create a Snake object with the parameters read from the user
	if (startPos.IsValidCell() && endPos.IsValidCell())
	{
		Snake* pSnake = new Snake(startPos, endPos);

		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pSnake);

		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Could not add GameObject to the desired cell! Click to continue ...");
		}
	}
	else pGrid->PrintErrorMessage("Error: Could not add GameObject to the desired cell! Click to continue ...");
	// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction
}