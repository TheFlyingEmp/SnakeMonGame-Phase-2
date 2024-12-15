#pragma once
#include "Action.h"
#include "Card.h"

class PasteCardAction : public Action
{
	Card* CardtoBePasted;

public:
	PasteCardAction(ApplicationManager* pApp);

	virtual void Execute();

	virtual ~PasteCardAction();
};

