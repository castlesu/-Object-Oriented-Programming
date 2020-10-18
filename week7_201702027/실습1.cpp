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
/* (�ǽ� 1-1) �м���� : */
/* ��� : 
Executed in B
Destructor execution: B
Executed in A
Destructor execution: A 
����: main()���� try{}�� funcA()�� �����Ѵ�. funcA()������ Test r(A) �����ϰ�(��ü ����=>id:A) funcB()�� �����Ѵ�.
funcB()���� Test r(B) �����ϰ�(��ü ����=>id:B) Executed in B�� ����Ѵ�. �״��� Test �Ҹ���(id:B)���� Destructor execution: B�� ����Ѵ�.
�״��� funcA()�� Executed in A�� ����ϰ� Test �Ҹ���(id:A)���� Destructor execution: A�� ����Ѵ�. */
/* (�ǽ� 1-2) �м���� : */
/* ��� :
Destructor execution : B
Destructor execution : A
Exception : Exception from funcB!
����:  main()���� try{}�� funcA()�� �����Ѵ�. funcA()������ Test r(A) �����ϰ�(��ü ����=>id:A) funcB()�� �����Ѵ�.
funcB()���� Test r(B) �����ϰ�(��ü ����=>id:B) throw�� �����Ƿ� funcB()�� ���� �� Test �Ҹ���(id:B)���� Destructor execution: B�� ����Ѵ�.
funcA() ���� �� Test �Ҹ���(id:A)���� Destructor execution: A�� ����Ѵ�. 
�� ���� main()�� catch���� ����  Exception : Exception from funcB!�� ����Ѵ�.
*/