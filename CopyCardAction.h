#pragma once
#include "Action.h"
#include "Card.h"

class CopyCardAction : public Action
{
public:
	CopyCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CopyCardAction();
};

