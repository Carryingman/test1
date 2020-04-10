// MyTestProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <type_traits>

//template<class T,class = void>
//struct add_pointer_array
//{
//	using type = T;
//};
//
//template<class T,size_t s>
//struct add_pointer_array<T, std::void_t<std::remove_reference<T>*[s]>>
//{
//	using type = std::remove_reference<T>*[s];
//};

template<class T, class = void>
struct add_T_function_pointer_T
{
	using type = T;
};

template<class T>
struct add_T_function_pointer_T<T, std::void_t<T (*)(T)>>
{
	using type = T (*)(T);
};

template<class C, class X, class Y>
struct replace_type
{
	using type = void;
};

template<class T,class Y>
struct replace_type<typename std::add_pointer<T>::type, T,Y>
{
	using type = typename std::add_pointer<Y>::type;
};

template<class T, class Y,size_t s>
struct replace_type<T*[s], T, Y>
{
	using type = Y * [s];
};

template<class T, class Y>
struct replace_type<typename add_T_function_pointer_T<T>::type, T, Y>
{
	using type = typename add_T_function_pointer_T<Y>::type;
};
//////////////////////////////////////////////////////////////////////////
template<long v>
struct is_binary
{
	static const bool value = (v % 10 > 1 ? false : true) && is_binary<v / 10>::value;
};

template<>
struct is_binary<0>
{
	static const bool value = true;
};

template<long b>
struct binary_function
{
	static const long value = binary_function<b / 10>::value * 2 + b % 10;
};

template<>
struct binary_function<0>
{
	static const long value = 0;
};

template<long v, bool b>
struct decision
{
	static_assert(b, "is not binary number!");//使用静态断言，输出报错信息
	static const long value = v;
};

template<long v>
struct decision<v, true>
{
	static const long value = binary_function<v>::value;
};

template<long b>
struct binary
{
	static const long value = decision<b, is_binary<b>::value>::value;
};

template<class T,size_t s, int I = 0>
struct for_each
{
	//static const int value = I < N ? for_each<N,I+1>::value
};

constexpr int flag(int);

template<class Tag>
struct writer
{
	friend constexpr int flag(Tag) { return 0; }
};

template<bool B,class Tag = int>
struct dependent_writer:writer<Tag>{};

template<bool B = noexcept(flag(0)),int = sizeof(dependent_writer<B>)>
constexpr int f() { return B; }

template<class T>
class polymorphic_downcast
{
public:
	template<class T1>
	polymorphic_downcast(T1){}

	operator T() { return nullptr; }
};

template<class T>
class polymorphic_downcast<T&>
{
public:
	template<class T1>
	polymorphic_downcast(T1& t):_t(static_cast<T&>(t)) {}

	operator T&() { return _t; }
private:
	T _t;
};

template<class T>
class polymorphic_downcast<T*>
{
public:
	template<class T1>
	polymorphic_downcast(T1* t):_t(static_cast<T*>(t)) {}

	operator T*() { return _t; }

private:
	T* _t;
};

struct A {};
struct B : A {};


// template<class T>
// std::ostream& operator<<(std::ostream& os, T t)
// {
// 
// }

int main()
{
	/*constexpr int a = f();
	constexpr int b = f();
	static_assert(a != b, "fail");*/
	//std::cout << 42;
	int tmp = 0;
	std::size_t n = sizeof(std::cout << 42);

	B b;
	A* a_ptr = &b;
	B* b_ptr = polymorphic_downcast<B*>(a_ptr);

	A* a = new A;
	B* c = polymorphic_downcast<B*>(a);

	A& a_ref = b;
	B& b_ref = polymorphic_downcast<B&>(a_ref);

    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
