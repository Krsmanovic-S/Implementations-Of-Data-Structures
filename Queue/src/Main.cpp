#include <queue.cpp>

int main()
{
	Queue<int>* intQueue = new Queue<int>();
	Queue<char>* charQueue = new Queue<char>();

	intQueue->push(2);
	intQueue->push(8);
	intQueue->push(44);
	intQueue->push(10);

	intQueue->pop();

	for (Queue<int>::Iterator it = intQueue->begin(); it != intQueue->end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << '\n' << '\n';

	charQueue->push('a');
	charQueue->push('C');
	charQueue->push('d');
	charQueue->push('h');

	charQueue->printQueue();

	charQueue->pop();

	std::cout << '\n' << charQueue->front() << '\n' << '\n';

	charQueue->printQueue();

	return 0;
}