#include <iostream>
#include <List.h>

int main() 
{
	List<int> IntegerList(2, 3, 5, 7, 10);

	List<char> CharList('A', 'b', 'c', 'd');

	IntegerList.InsertNodeAtLocation(22, 1);
	
	CharList.RemoveNodeAtLocation(2);

	IntegerList.PrintEntireList();
	CharList.PrintEntireList();
}