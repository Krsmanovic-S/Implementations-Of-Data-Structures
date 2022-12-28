#include <Stack.cpp>

int main()
{
	Stack<int>* IntStack = new Stack<int>();

	IntStack->Push(5);
	IntStack->Push(7);
	IntStack->Push(10);

	for (Stack<int>::Iterator it = IntStack->begin(); it != IntStack->end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << '\n' << '\n';

	IntStack->Pop();

	std::cout << "Stack top: " << IntStack->Top() << '\n';

	delete IntStack;
}