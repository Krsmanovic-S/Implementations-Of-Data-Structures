#include <Queue.cpp>

int main()
{
	Queue<int>* IntQueue = new Queue<int>();
	Queue<char>* CharQueue = new Queue<char>();

	IntQueue->Push(2);
	IntQueue->Push(8);
	IntQueue->Push(44);
	IntQueue->Push(10);

	IntQueue->PrintQueue();

	IntQueue->Pop();

	std::cout << '\n' << IntQueue->Front() << '\n' << '\n';

	CharQueue->Push('a');
	CharQueue->Push('C');
	CharQueue->Push('d');
	CharQueue->Push('h');

	CharQueue->PrintQueue();

	CharQueue->Pop();

	std::cout << '\n' << CharQueue->Front() << '\n' << '\n';

	CharQueue->PrintQueue();
}