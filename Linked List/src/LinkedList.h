#pragma once

#include <initializer_list>
#include <Node.h>

/// <summary>
/// Class representing a linked list, contains methods
/// for adding, deleting, inserting and printing the list.
/// </summary>
template <typename T>
class LinkedList
{

public:

	class Iterator
	{
	public:

		Iterator(Node<T>* Input) : IteratedNode(Input) {}

		/// <summary>
		/// Overloading the * operator to get the reference
		/// of the node value that the iterator is pointing to.
		/// </summary>
		/// <returns> Iterators node value as reference. </returns>
		T& operator*() { return IteratedNode->GetNodeValueAsReference(); }

		// Overload the ++ operator to move to the next element.
		Iterator& operator++() {
			if (IteratedNode != nullptr)
			{
				IteratedNode = IteratedNode->GetNextNode();
			}

			return *this;
		}

		// Overload the != operator to compare iterators.
		bool operator!=(const Iterator& OtherIterator)
		{
			return IteratedNode != OtherIterator.IteratedNode;
		}

	private:

		// Pointer to the currently iterated element.
		Node<T>* IteratedNode;
	};

	/// <returns> Iterator pointing to the beginning of the list. </returns>
	LinkedList<T>::Iterator begin() { return Iterator(m_Head); }

	/// <returns> Iterator pointing to the end of the list. </returns>
	LinkedList<T>::Iterator end() { return Iterator(nullptr); }

public:

	/// <summary>
	/// Takes in an initializer list, builds the class instance with it 
	/// and assigns the head and tail nodes.
	/// </summary>
	/// <param name="DoubleLink:"> Detemines if this list is singly or doubly linked. </param>
	/// <param name="args:"> Initializer list of a certain type (int, string ecc..). </param>
	template <typename ... Args>
	LinkedList(bool DoubleLink = false, Args ... args);

	/// <returns> Amount of nodes that are inside this entire list. </returns>
	int GetListSize() const { return m_ListSize; };

	// Displays all the node values with std::cout in head to tail order.  
	void PrintEntireList() const;

	/// <summary>
	/// Adds a new node to the beginning of the list.
	/// </summary>
	/// <param name="NodeValue:"> Value of the newly added node. </param>
	void PrependNode(T NodeValue);

	/// <summary>
	/// Adds a node to the end of the list.
	/// </summary>
	/// <param name="NodeValue:"> Value of the newly added node. </param>
	void AppendNode(T NodeValue);

	// Removes the head/first node of the list and moves the head to its next node.
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

	/// <returns> Head of the linked list. </returns>
	Node<T>* GetRootNode() const { return m_Head; }

	/// <summary>
	/// Checks whether a linked list is cyclic by using
	/// a slow and fast pointer. Slow one moves one node
	/// at a time, fast one moves two at a time. If they
	/// end up the same the list is cyclic and if any one
	/// of them reaches the end, then the list isn't cyclic.
	/// </summary>
	/// <returns>  Whether a linked list is cyclic. </returns>
	bool IsCyclicList();

private:

	// First Node of the linked list.
	Node<T>* m_Head;

	// Last Node of the linked list.
	Node<T>* m_Tail;

	// Represents the number of Nodes inside the list.
	int m_ListSize;

	// Shows if this list is doubly linked or singly linked.
	bool m_IsDoublyLinked;
};

template<typename T>
inline void LinkedList<T>::PrependNode(T NodeValue)
{
	Node<T>* NewNode = new Node<T>(NodeValue);

	NewNode->SetNextNode(m_Head);

	if (m_IsDoublyLinked == true) { m_Head->SetPreviousNode(NewNode); }

	m_Head = NewNode;
}

template<typename T>
inline void LinkedList<T>::AppendNode(T NodeValue)
{
	if (m_IsDoublyLinked == true) 
	{ 
		m_Tail->SetNextNode(new Node<T>(NodeValue, nullptr, m_Tail));
	}
	else { m_Tail->SetNextNode(new Node<T>(NodeValue));	}

	m_Tail = m_Tail->GetNextNode();
	m_ListSize++;
}

template<typename T>
inline void LinkedList<T>::RemoveHeadNode()
{
	Node<T>* NodeToRemove = m_Head;

	m_Head = m_Head->GetNextNode();

	if (m_IsDoublyLinked == true) { m_Head->SetPreviousNode(nullptr); }

	delete NodeToRemove;
	m_ListSize--;
}

template<typename T>
inline void LinkedList<T>::RemoveTailNode()
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
