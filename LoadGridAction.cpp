#include "LoadGridAction.h"

LoadGridAction::LoadGridAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void LoadGridAction::ReadActionParameters()
{
}

void LoadGridAction::Execute()
{
	ifstream InFile;

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Please, enter the name of the file you want your grid to load... (CaseSensitive)");
	string FileName = pIn->GetString(pOut);

	pGrid->LoadGrid(InFile, FileName);
}

LoadGridAction::~LoadGridAction()
{
}