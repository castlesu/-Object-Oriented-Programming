#include <iostream>
#include <string>

template<typename T, typename...Args>
auto sum(T x, Args... args) {
	return x + sum(args...);
}

template<typename T>
auto sum(T x) {
	return x ;
}

auto sum() {
	return 0;
}

int main() {
	auto x = sum(42.5, 10, 11.1f);
	std::cout << x;
	char c = getchar();
}

/* sum()의 파라미터가 1개, 0인 것을 선언한다. */