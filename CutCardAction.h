#pragma once
#include "Action.h"
#include "Card.h"

class CutCardAction : public Action
{
public:
	CutCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CutCardAction();
};