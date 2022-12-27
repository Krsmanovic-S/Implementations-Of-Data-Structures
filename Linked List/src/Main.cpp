#include <LinkedList.cpp>

int main() 
{
	LinkedList<int>* IntegerList = new LinkedList<int>(true, 2, 3, 5, 7, 10);

	LinkedList<char>* CharList = new LinkedList<char>(false, 'A', 'b', 'c', 'd');

	LinkedList<float>* FloatList = new LinkedList<float>(true, 2.2f, 3.55f, 6.56f);

	IntegerList->InsertNodeAtLocation(22, 1);
	CharList->RemoveNodeAtLocation(2);
	FloatList->RemoveHeadNode();

	IntegerList->PrintEntireList();
	CharList->PrintEntireList();
	FloatList->PrintEntireList();

	delete IntegerList;
	delete CharList;
	delete FloatList;
}