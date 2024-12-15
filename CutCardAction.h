#pragma once
#include "Action.h"
#include "Card.h"

class CutCardAction : public Action
{
	Card* CardtoBeCut;

public:
	CutCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters(Card* Card);

	virtual void Execute(Card* Card);

	virtual ~CutCardAction();
};

