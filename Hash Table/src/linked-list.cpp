#include <linked-list.h>
#include <iostream>

LinkedList::~LinkedList()
{
	Node* currentNode = m_head;
	Node* nextNode;

	while (currentNode != nullptr)
	{
		nextNode = currentNode->getNextNode();

		delete currentNode;

		currentNode = nextNode;
	}
}

void LinkedList::printEntireList() const
{
	if (m_head == nullptr) { return; }

	Node* currentNode = m_head;

	for (int i = 0; i < m_listSize; i++)
	{
		std::cout << currentNode->getNodeData();

		if (i != m_listSize - 1) { std::cout << " -> "; }

		currentNode = currentNode->getNextNode();
	}
}

inline void LinkedList::appendNode(std::string nodeData)
{
	if (m_head == m_tail)
	{
		Node* inputNode = new Node(nodeData);

		m_head->setNextNode(inputNode);
		m_tail = inputNode;
	}
	else
	{
		m_tail->setNextNode(new Node(nodeData));

		m_tail = m_tail->getNextNode();
	}

	m_listSize++;
}

inline void LinkedList::removeHeadNode()
{
	if (m_head == nullptr) { return; }

	Node* nodeToRemove = m_head;

	m_head = m_head->getNextNode();

	delete nodeToRemove;
	m_listSize--;
}

inline void LinkedList::removeTailNode()
{
	if (m_head == nullptr) { return; }

	if (m_listSize == 1)
	{
		m_head = nullptr;
		return;
	}

	Node* currentNode = m_head;


	while (currentNode->getNextNode() != m_tail)
	{
		currentNode = currentNode->getNextNode();
	}

	delete currentNode->getNextNode();

	currentNode->setNextNode(nullptr);

	m_tail = currentNode;

	m_listSize--;
}

void LinkedList::removeNodeAtLocation(int removePosition)
{
	if (removePosition < 0 || removePosition > m_listSize - 1)
	{
		std::cerr << "Insert position is out of bounds, please enter a valid position.";
		return;
	}

	if (removePosition == 0) { return this->removeHeadNode(); }
	else if (removePosition == m_listSize - 1) { return this->removeTailNode(); }

	Node* currentNode = m_head;
	Node* secondNextNode = currentNode->getNextNode()->getNextNode();

	for (int i = 1; i < removePosition; i++)
	{
		currentNode = currentNode->getNextNode();

		secondNextNode = secondNextNode->getNextNode();
	}

	delete currentNode->getNextNode();

	currentNode->setNextNode(secondNextNode);

	m_listSize--;
}