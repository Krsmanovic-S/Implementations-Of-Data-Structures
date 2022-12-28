#include <LinkedList.h>
#include <iostream>

template<typename T>
template<typename ...Args>
LinkedList<T>::LinkedList(bool doubleLink, Args ... args)
{
	std::initializer_list<T> inputList{ args... };

	m_isDoublyLinked = doubleLink;

	m_listSize = inputList.size();

	m_head = new Node<T>(*(inputList.begin()));

	if (m_listSize == 1)
	{
		m_tail = m_head;
		return;
	}

	Node<T>* currentNode = m_head;
	Node<T>* nextNode;

	for (auto it = inputList.begin() + 1; it < inputList.end(); ++it)
	{
		nextNode = new Node<T>(*it);

		currentNode->setNextNode(nextNode);

		currentNode = nextNode;
	}

	m_tail = currentNode;
}

template<typename T>
void LinkedList<T>::printEntireList() const
{
	Node<T>* currentNode = m_head;

	std::cout << "List node values in Head to Tail order: ";

	for (int i = 0; i < m_listSize; i++)
	{
		std::cout << currentNode->getNodeData();

		if (i != m_listSize - 1)
		{
			if (m_isDoublyLinked == true) { std::cout << " <-> "; }
			else { std::cout << " -> "; }
		}
		else { std::cout << "." << '\n' << '\n'; };

		currentNode = currentNode->getNextNode();
	}
}

template<typename T>
bool LinkedList<T>::isCyclicList()
{
	if (m_head == nullptr) { return false; }

	Node<T>* slowPointer = m_head;
	Node<T>* fastPointer = m_head;

	while (slowPointer != nullptr && fastPointer != nullptr)
	{
		slowPointer = slowPointer->getNextNode();

		fastPointer = fastPointer->getNextNode();

		if (fastPointer != nullptr)
		{
			fastPointer = fastPointer->getNextNode();
		}

		if (slowPointer == fastPointer) { return true; }
	}

	return false;
}

template<typename T>
void LinkedList<T>::insertNodeAtLocation(T nodeData, int insertPosition)
{
	if (insertPosition < 0 || insertPosition > m_listSize - 1)
	{
		std::cerr << "Insert position is out of bounds, please enter a valid position.";
		return;
	}

	if (insertPosition == m_listSize - 1) { return this->appendNode(nodeData); }
	if (insertPosition == 0) { return this->prependNode(nodeData); }

	Node<T>* insertNode = new Node<T>(nodeData);
	Node<T>* currentNode = m_head;
	Node<T>* nextNode = currentNode->getNextNode();

	for (int i = 1; i < insertPosition - 1; i++)
	{
		currentNode = nextNode;

		nextNode = currentNode->getNextNode();
	}

	currentNode->setNextNode(insertNode);

	if (m_isDoublyLinked == true)
	{
		insertNode->setPreviousNode(currentNode);
		nextNode->setPreviousNode(insertNode);
	}

	insertNode->setNextNode(nextNode);

	return;
}

template<typename T>
void LinkedList<T>::removeNodeAtLocation(int removePosition)
{
	if (removePosition < 0 || removePosition > m_listSize - 1)
	{
		std::cerr << "Insert position is out of bounds, please enter a valid position.";
		return;
	}

	if (removePosition == m_listSize - 1) { return this->removeTailNode(); }
	if (removePosition == 0) { return this->removeHeadNode(); }

	Node<T>* currentNode = m_head;
	Node<T>* secondNextNode = currentNode->getNextNode()->getNextNode();

	for (int i = 1; i < removePosition; i++)
	{
		currentNode = currentNode->getNextNode();

		secondNextNode = secondNextNode->getNextNode();
	}

	if (m_isDoublyLinked == true) { secondNextNode->setPreviousNode(currentNode); }

	delete currentNode->getNextNode();

	currentNode->setNextNode(secondNextNode);

	m_listSize--;
}