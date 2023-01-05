#include <linked-list.cpp>

int main() 
{
	LinkedList<int>* integerList = new LinkedList<int>(true, 2, 3, 5, 7, 10);
	LinkedList<char>* charList = new LinkedList<char>(false, 'A', 'b', 'c', 'd');

	integerList->insertNodeAtLocation(22, 1);
	charList->removeNodeAtLocation(2);

	for (LinkedList<int>::Iterator it = integerList->begin(); it != integerList->end(); ++it)
	{
		std::cout << *it << " <-> ";
	}

	std::cout << '\n' << '\n';

	charList->printEntireList();

	delete integerList;
	delete charList;

	return 0;
}