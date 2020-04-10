#pragma once
#include "ICalcState.h"

class DotState : public ICalcState
{
public:
	DotState() :ICalcState(StateName::STATE_DOT) {}

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
