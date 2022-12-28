#include <LinkedList.cpp>

int main() 
{
	LinkedList<int>* integerList = new LinkedList<int>(true, 2, 3, 5, 7, 10);

	LinkedList<char>* charList = new LinkedList<char>(false, 'A', 'b', 'c', 'd');

	LinkedList<float>* floatList = new LinkedList<float>(true, 2.2f, 3.55f, 6.56f);

	integerList->insertNodeAtLocation(22, 1);
	charList->removeNodeAtLocation(2);
	floatList->removeHeadNode();

	for (LinkedList<int>::Iterator it = integerList->begin(); it != integerList->end(); ++it)
	{
		std::cout << *it << " ";;
	}

	std::cout << '\n' << '\n';

	charList->printEntireList();
	floatList->printEntireList();

	delete integerList;
	delete charList;
	delete floatList;

	return 0;
}