#include <iostream>
#include <stdexcept>
class Test {
public:
	Test(char id) : id_(id) {}
	~Test() {
		std::cout << "Destructor execution: "
			<< id_ << std::endl;
	}
private:
	char id_;
};
int funcB() {
	Test r('B');
	 throw std::runtime_error("Exception from funcB!\n");
	std::cout << "Executed in B" << std::endl;
	return 0;
}
int funcA() {
	Test r('A');
	funcB();
	std::cout << "Executed in A" << std::endl;
	return 0;
}
int main() {
	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what();
	}
}
/* (실습 1-1) 분석결과 : */
/* 결과 : 
Executed in B
Destructor execution: B
Executed in A
Destructor execution: A 
설명: main()에서 try{}의 funcA()을 실행한다. funcA()에서는 Test r(A) 생성하고(객체 생성=>id:A) funcB()을 실행한다.
funcB()에서 Test r(B) 생성하고(객체 생성=>id:B) Executed in B을 출력한다. 그다음 Test 소멸자(id:B)에서 Destructor execution: B를 출력한다.
그다음 funcA()의 Executed in A를 출력하고 Test 소멸자(id:A)에서 Destructor execution: A를 출력한다. */
/* (실습 1-2) 분석결과 : */
/* 결과 :
Destructor execution : B
Destructor execution : A
Exception : Exception from funcB!
설명:  main()에서 try{}의 funcA()을 실행한다. funcA()에서는 Test r(A) 생성하고(객체 생성=>id:A) funcB()을 실행한다.
funcB()에서 Test r(B) 생성하고(객체 생성=>id:B) throw가 있으므로 funcB()를 종료 후 Test 소멸자(id:B)에서 Destructor execution: B를 출력한다.
funcA() 종료 후 Test 소멸자(id:A)에서 Destructor execution: A를 출력한다. 
그 다음 main()의 catch으로 가서  Exception : Exception from funcB!를 출력한다.
*/