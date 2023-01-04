#include <stack.cpp>

int main()
{
	Stack<int>* intStack = new Stack<int>();

	intStack->push(5);
	intStack->push(7);
	intStack->push(10);

	for (Stack<int>::Iterator it = intStack->begin(); it != intStack->end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << '\n' << '\n';

	intStack->pop();

	std::cout << "Stack top: " << intStack->top() << '\n';

	delete intStack;

	return 0;
}