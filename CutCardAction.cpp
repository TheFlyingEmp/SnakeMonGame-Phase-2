#include "CutCardAction.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void CutCardAction::ReadActionParameters()
{
}

void CutCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Please, click on the source cell");
	CellPosition TargetCellPos = pIn->GetCellClicked();
	if (TargetCellPos.IsValidCell()) {
		if (pGrid->HasGameObject(TargetCellPos))
		{
			Card* pCard = dynamic_cast<Card*>(pGrid->GetGameObjectfromCell(TargetCellPos));
			pGrid->SetClipboard(pCard);
			pGrid->RemoveObjectFromCell(TargetCellPos);
		}
		else {
			pGrid->PrintErrorMessage("Invalid, the clicked cell does not have a card in it");
			return;
		}
	}
	else {
		pGrid->PrintErrorMessage("Invalid, the clicked cell does not exist");
		return;
	}
}

CutCardAction::~CutCardAction()
{
}