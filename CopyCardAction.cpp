#include "CopyCardAction.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void CopyCardAction::ReadActionParameters(Card* Card)
{
	CardtoBeCopied = Card;
}

void CopyCardAction::Execute(Card* Card)
{
	ReadActionParameters(Card);

	Grid* pGrid = pManager->GetGrid();

	pGrid->SetClipboard(CardtoBeCopied);
}

CopyCardAction::~CopyCardAction()
{
}