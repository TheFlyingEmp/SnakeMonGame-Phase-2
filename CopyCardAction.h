#pragma once
#include "Action.h"
#include "Card.h"

class CopyCardAction : public Action
{
	Card* CardtoBeCopied;

public:
	CopyCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters(Card* Card);

	virtual void Execute(Card* Card);

	virtual ~CopyCardAction();
};

