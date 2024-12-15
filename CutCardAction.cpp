#include "CutCardAction.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void CutCardAction::ReadActionParameters(Card* Card)
{
	CardtoBeCut = Card;
}

void CutCardAction::Execute(Card* Card)
{
	ReadActionParameters(Card);

	Grid* pGrid = pManager->GetGrid();

	CellPosition PreviousPosition = CardtoBeCut->GetPosition();

	pGrid->SetClipboard(CardtoBeCut);

	pGrid->RemoveObjectFromCell(PreviousPosition);
}

CutCardAction::~CutCardAction()
{
}