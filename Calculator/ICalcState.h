#pragma once
#include <memory>

enum class StateName
{
	STATE_NUM,
	STATE_SIGN,
	STATE_DOT,
	STATE_OP,
	STATE_EQUALS
};

class ICalcState
{
public:
	virtual ~ICalcState(){}

	virtual bool changeState(const std::shared_ptr<ICalcState>& oldState) = 0;

	auto getStateName() const { return _stateName; }
protected:
	ICalcState(const StateName sn):_stateName(sn){}

	StateName _stateName;
};
