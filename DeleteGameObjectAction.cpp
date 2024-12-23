
#include "DeleteGameObjectAction.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"
//#include "EditCardAction.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{

	// Initializes the pManager pointer of Action with the passed pointer
}

DeleteGameObjectAction::~DeleteGameObjectAction()
{

}

void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("click on the source to edit");
	cellPos = pIn->GetCellClicked();
	//if (!cellPos.IsValidCell())
	pOut->ClearStatusBar();
}

void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	bool hasgameObject = pGrid->HasGameObject(cellPos);
	if (!hasgameObject)
	{
		pGrid->PrintErrorMessage("Invalid Game Object Cell position.Click anywhere to continue...");
		return;
	}
	else
		pGrid->RemoveObjectFromCell(cellPos);
	
}
