#pragma once
#include "ICalcState.h"


class NumState : public ICalcState
{
public:
	NumState():ICalcState(StateName::STATE_NUM){}

	virtual bool changeState(const std::shared_ptr<ICalcState>& oldState)
	{
		switch (oldState->getStateName())
		{
		case StateName::STATE_OP:
		case StateName::STATE_NUM:
		case StateName::STATE_DOT:
			return true;
		default:
			return false;
		}
	}
};