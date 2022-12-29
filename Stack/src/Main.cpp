#include <stack.cpp>

int main()
{
	Stack<int>* intStack = new Stack<int>();

	intStack->Push(5);
	intStack->Push(7);
	intStack->Push(10);

	for (Stack<int>::Iterator it = intStack->begin(); it != intStack->end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << '\n' << '\n';

	intStack->Pop();

	std::cout << "Stack top: " << intStack->Top() << '\n';

	delete intStack;

	return 0;
}