#pragma once

#include <iostream>
#include <initializer_list>
#include <type_traits>
#include <Node.h>

/// <summary>
/// Class for a singly linked list,
/// contains methods for adding, deleting,
/// inserting and printing the list.
/// </summary>
template <typename T>
class List
{

public:

	/// <summary>
	/// Takes in an initializer list, builds the class instance with it 
	/// and assigns the head and tail nodes.
	/// </summary>
	/// <param name="args:"> Initializer list of a certain type (i.e. int, string ecc..). </param>
	template <typename ... Args>
	List(Args ... args);

	/// <returns> Amount of nodes that are inside this entire list. </returns>
	constexpr int GetListSize() const { return m_ListSize; };

	/// <summary>
	/// Displays all the node values with std::cout in head to tail order.  
	/// </summary>
	void PrintEntireList() const;

	/// <summary>
	/// Adds a node to the end of the list.
	/// </summary>
	/// <param name="NodeValue:"> Value of the newly added node. </param>
	void AppendNode(T NodeValue);

	/// <summary>
	/// Removes the head/first node of the list and moves the head to its next node.
	/// </summary>
	void RemoveHeadNode();

	/// <summary>
	/// Removes the tail/last node of the list and re-assigns the tail to the node
	/// that was previously before the tail.
	/// </summary>
	void RemoveTailNode();

	/// <summary>
	/// Creates a new node and inserts it into the list at the specified
	/// location only if the location of the insert is valid. Adjusts the
	/// newly created order of nodes to follow the singly linked list structure.
	/// </summary>
	/// <param name="NodeValue:"> Value of the node that is going to be inserted. </param>
	/// <param name="InsertPosition:"> Position of where the insertion happens (0 is the starting position).</param>
	void InsertNodeAtLocation(T NodeValue, int InsertPosition);

	/// <summary>
	/// Removes a node at the specified location if that location is valid.
	/// Adjusts the remaining nodes to follow the singly linked list structure.
	/// </summary>
	/// <param name="RemovePosition:"> Position of where the deletion happens. </param>
	void RemoveNodeAtLocation(int RemovePosition);

private:

	/// <summary>
	/// First Node of the linked list.
	/// </summary>
	Node<T>* m_Head;

	/// <summary>
	/// Last Node of the linked list.
	/// </summary>
	Node<T>* m_Tail;

	/// <summary>
	/// Represents the number of Nodes inside the list.
	/// </summary>
	int m_ListSize;
};

template<typename T>
template<typename ...Args>
inline List<T>::List(Args ... args)
{
	std::initializer_list<T> InputList{ args... };

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
inline void List<T>::PrintEntireList() const
{
	Node<T>* CurrentNode = m_Head;

	std::cout << "List node values in Head to Tail order: ";

	for (int i = 0; i < m_ListSize; i++)
	{
		std::cout << CurrentNode->GetNodeValue();

		if (i != m_ListSize - 1) { std::cout << ", "; }
		else { std::cout << "." << '\n'; };

		CurrentNode = CurrentNode->GetNextNode();
	}
}

template<typename T>
inline void List<T>::AppendNode(T NodeValue)
{
	m_Tail->SetNextNode(new Node<T>(NodeValue));

	m_Tail = m_Tail->GetNextNode();

	m_ListSize++;
}

template<typename T>
inline void List<T>::RemoveHeadNode()
{
	Node<T>* NodeToRemove = m_Head;

	m_Head = m_Head->GetNextNode();

	delete NodeToRemove;
	m_ListSize--;
}

template<typename T>
inline void List<T>::RemoveTailNode()
{
	Node<T>* CurrentNode = m_Head;

	while (CurrentNode->GetNextNode() != m_Tail)
	{
		CurrentNode = CurrentNode->GetNextNode();
	}

	delete CurrentNode->GetNextNode();

	CurrentNode->SetNextNode(nullptr);

	m_Tail = CurrentNode;

	m_ListSize--;
}

template<typename T>
inline void List<T>::InsertNodeAtLocation(T NodeValue, int InsertPosition)
{
	if (InsertPosition < 0 || InsertPosition > m_ListSize - 1)
	{
		std::cerr << "Insert position is out of bounds, please enter a valid position.";
		return;
	}

	if (InsertPosition == m_ListSize - 1) { return this->AppendNode(NodeValue); }
	
	Node<T>* InsertNode = new Node<T>(NodeValue);

	if (InsertPosition == 0) 
	{
		InsertNode->SetNextNode(m_Head);

		m_Head = InsertNode;

		return;
	}

	Node<T>* CurrentNode = m_Head;
	Node<T>* NextNode = CurrentNode->GetNextNode();

	for (int i = 1; i < InsertPosition - 1; i++)
	{
		CurrentNode = NextNode;

		NextNode = CurrentNode->GetNextNode();
	}

	CurrentNode->SetNextNode(InsertNode);
	InsertNode->SetNextNode(NextNode);

	return;
}

template<typename T>
inline void List<T>::RemoveNodeAtLocation(int RemovePosition)
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

	delete CurrentNode->GetNextNode();

	CurrentNode->SetNextNode(SecondNextNode);

	m_ListSize--;
}
