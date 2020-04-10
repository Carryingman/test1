#pragma once

template<long num>
struct is_binary
{
	static const bool value = ((num % 10 == 0 || num % 10 == 1) ? true : false) && is_binary<num / 10>::value;
};
template<>
struct is_binary<0>
{
	static const bool value = true;
};

template<bool result> struct process;

template<> struct
process<true>
{
};

template<> struct
process<false>
{
};

template<bool result> struct process;

template<long binNum>
struct Bin2Dec
{
	static const long value = Bin2Dec<binNum / 10>::value * 2 + binNum % 10;
};


template<>
struct Bin2Dec<0>
{
	static const long value = 0;
};