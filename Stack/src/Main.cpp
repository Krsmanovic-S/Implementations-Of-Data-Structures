#include <Stack.cpp>

int main()
{
	Stack<int>* MyStack = new Stack<int>();

	MyStack->Push(5);
	MyStack->Push(7);
	MyStack->Push(10);

	MyStack->PrintStack();

	MyStack->Pop();

	std::cout << "Stack top: " << MyStack->Top() << '\n';

	delete MyStack;
}