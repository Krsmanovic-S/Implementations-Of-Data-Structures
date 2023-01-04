#include <queue.cpp>

int main()
{
	Queue<int>* intQueue = new Queue<int>();
	Queue<char>* charQueue = new Queue<char>();

	intQueue->push(2);
	intQueue->push(8);
	intQueue->push(44);
	intQueue->push(10);

	for (Queue<int>::Iterator it = intQueue->begin(); it != intQueue->end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << '\n';

	intQueue->pop();

	std::cout << '\n' << '\n';

	charQueue->push('a');
	charQueue->push('C');
	charQueue->push('d');
	charQueue->push('h');

	charQueue->printQueue();

	charQueue->pop();

	return 0;
}