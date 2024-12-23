#include "SaveGridAction.h"

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp) 
{
	pManager = pApp;
}

void SaveGridAction::ReadActionParameters()
{
}

void SaveGridAction::Execute()
{
	ofstream OutFile;

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Please, enter the name of the file you want your grid to be saved as... (CaseSensitive)");
	string FileName = pIn->GetString(pOut);

	pGrid->SaveGrid(OutFile, FileName);
}

SaveGridAction::~SaveGridAction()
{
}