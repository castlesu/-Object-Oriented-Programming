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

/* sum()�� �Ķ���Ͱ� 1��, 0�� ���� �����Ѵ�. */