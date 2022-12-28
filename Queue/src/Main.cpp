#include <Queue.cpp>

int main()
{
	Queue<int>* IntQueue = new Queue<int>();
	Queue<char>* CharQueue = new Queue<char>();

	IntQueue->Push(2);
	IntQueue->Push(8);
	IntQueue->Push(44);
	IntQueue->Push(10);

	IntQueue->Pop();

	for (Queue<int>::Iterator it = IntQueue->begin(); it != IntQueue->end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << '\n' << '\n';

	CharQueue->Push('a');
	CharQueue->Push('C');
	CharQueue->Push('d');
	CharQueue->Push('h');

	CharQueue->PrintQueue();

	CharQueue->Pop();

	std::cout << '\n' << CharQueue->Front() << '\n' << '\n';

	CharQueue->PrintQueue();
}