#include  "ThreadPool.h"
#include <iostream>

int fun1(int a)
{
	return a;
}

std::string fun2(std::string str1, std::string str2)
{
	return str1 + str2;
}

int main()
{
	ThreadPool tp;;
	std::future<int> ft=tp.post(std::bind(fun1, 5));
	std::future<std::string> ft2 = tp.post(std::bind(fun2, "thread", "pool"));
	tp.start(2);
	auto i=ft.get();
	auto s = ft2.get();
	std::cout << i;
	std::cout << s.data();
	getchar();
}