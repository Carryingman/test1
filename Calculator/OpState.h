#pragma once
#include "ICalcState.h"

class OpState : public ICalcState
{
public:
	OpState() :ICalcState(StateName::STATE_OP) {}

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
