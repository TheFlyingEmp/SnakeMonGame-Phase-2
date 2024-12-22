#include "PasteCardAction.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void PasteCardAction::ReadActionParameters()
{
}

void PasteCardAction::Execute() 
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Please, click on the destination cell");
	CellPosition TargetCellPos = pIn->GetCellClicked();
	if (TargetCellPos.IsValidCell()) {
		Card* CardtoBePasted = pGrid->GetClipboard();
		CardtoBePasted->SetPosition(TargetCellPos);
		pGrid->AddObjectToCell(CardtoBePasted);
	}
	else {
		pGrid->PrintErrorMessage("Invalid, the clicked cell does not exist");
		return;
	}
}

PasteCardAction::~PasteCardAction()
{
}