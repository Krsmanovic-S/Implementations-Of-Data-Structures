#include <LinkedList.h>

template<typename T>
template<typename ...Args>
LinkedList<T>::LinkedList(bool DoubleLink, Args ... args)
{
	std::initializer_list<T> InputList{ args... };

	m_IsDoublyLinked = DoubleLink;

	m_ListSize = InputList.size();

	m_Head = new Node<T>(*(InputList.begin()));

	if (m_ListSize == 1)
	{
		m_Tail = m_Head;
		return;
	}

	Node<T>* CurrentNode = m_Head;
	Node<T>* NextNode;

	for (auto it = InputList.begin() + 1; it < InputList.end(); ++it)
	{
		NextNode = new Node<T>(*it);

		CurrentNode->SetNextNode(NextNode);

		CurrentNode = NextNode;
	}

	m_Tail = CurrentNode;
}

template<typename T>
void LinkedList<T>::PrintEntireList() const
{
	Node<T>* CurrentNode = m_Head;

	std::cout << "List node values in Head to Tail order: ";

	for (int i = 0; i < m_ListSize; i++)
	{
		std::cout << CurrentNode->GetNodeValue();

		if (i != m_ListSize - 1)
		{
			if (m_IsDoublyLinked == true) { std::cout << " <-> "; }
			else { std::cout << " -> "; }
		}
		else { std::cout << "." << '\n' << '\n'; };

		CurrentNode = CurrentNode->GetNextNode();
	}
}

template<typename T>
bool LinkedList<T>::IsCyclicList()
{
	if (m_Head == nullptr) { return false; }

	Node<T>* SlowPointer = m_Head;
	Node<T>* FastPointer = m_Head;

	while (SlowPointer != nullptr && FastPointer != nullptr)
	{
		SlowPointer = SlowPointer->GetNextNode();

		FastPointer = FastPointer->GetNextNode();

		if (FastPointer != nullptr)
		{
			FastPointer = FastPointer->GetNextNode();
		}

		if (SlowPointer == FastPointer) { return true; }
	}

	return false;
}

template<typename T>
void LinkedList<T>::InsertNodeAtLocation(T NodeValue, int InsertPosition)
{
	if (InsertPosition < 0 || InsertPosition > m_ListSize - 1)
	{
		std::cerr << "Insert position is out of bounds, please enter a valid position.";
		return;
	}

	if (InsertPosition == m_ListSize - 1) { return this->AppendNode(NodeValue); }
	if (InsertPosition == 0) { return this->PrependNode(NodeValue); }

	Node<T>* InsertNode = new Node<T>(NodeValue);
	Node<T>* CurrentNode = m_Head;
	Node<T>* NextNode = CurrentNode->GetNextNode();

	for (int i = 1; i < InsertPosition - 1; i++)
	{
		CurrentNode = NextNode;

		NextNode = CurrentNode->GetNextNode();
	}

	CurrentNode->SetNextNode(InsertNode);

	if (m_IsDoublyLinked == true)
	{
		InsertNode->SetPreviousNode(CurrentNode);
		NextNode->SetPreviousNode(InsertNode);
	}

	InsertNode->SetNextNode(NextNode);

	return;
}

template<typename T>
void LinkedList<T>::RemoveNodeAtLocation(int RemovePosition)
{
	if (RemovePosition < 0 || RemovePosition > m_ListSize - 1)
	{
		std::cerr << "Insert position is out of bounds, please enter a valid position.";
		return;
	}

	if (RemovePosition == m_ListSize - 1) { return this->RemoveTailNode(); }
	if (RemovePosition == 0) { return this->RemoveHeadNode(); }

	Node<T>* CurrentNode = m_Head;
	Node<T>* SecondNextNode = CurrentNode->GetNextNode()->GetNextNode();

	for (int i = 1; i < RemovePosition; i++)
	{
		CurrentNode = CurrentNode->GetNextNode();

		SecondNextNode = SecondNextNode->GetNextNode();
	}

	if (m_IsDoublyLinked == true) { SecondNextNode->SetPreviousNode(CurrentNode); }

	delete CurrentNode->GetNextNode();

	CurrentNode->SetNextNode(SecondNextNode);

	m_ListSize--;
}