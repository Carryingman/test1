#pragma once
#include "ICalcState.h"

class EqualsState : public ICalcState
{
public:
	EqualsState() :ICalcState(StateName::STATE_EQUALS) {}

	virtual bool changeState(const std::shared_ptr<ICalcState>& oldState)
	{
		switch (oldState->getStateName())
		{
		case StateName::STATE_NUM:
			return true;
		default:
			return false;
		}
	}
};