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

		Iterator(Node<T>* inputNode) : m_iteratedNode(inputNode) {}

		/// <summary>
		/// Overloading the * operator to get the reference
		/// of the node value that the iterator is pointing to.
		/// </summary>
		/// <returns> Iterators node value as reference. </returns>
		T& operator*() { return m_iteratedNode->getNodeDataAsReference(); }

		// Overload the ++ operator to move to the next element.
		Iterator& operator++() {
			if (m_iteratedNode != nullptr)
			{
				m_iteratedNode = m_iteratedNode->getNextNode();
			}

			return *this;
		}

		// Overload the != operator to compare iterators.
		bool operator!=(const Iterator& otherIterator)
		{
			return m_iteratedNode != otherIterator.m_iteratedNode;
		}

	private:

		// Pointer to the currently iterated element.
		Node<T>* m_iteratedNode;
	};

	/// <returns> Iterator pointing to the beginning of the list. </returns>
	LinkedList<T>::Iterator begin() { return Iterator(m_head); }

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
	LinkedList(bool doubleLink = false, Args ... args);

	/// <returns> Amount of nodes that are inside this entire list. </returns>
	int getListSize() const { return m_listSize; };

	// Displays all the node values with std::cout in head to tail order.  
	void printEntireList() const;

	/// <summary>
	/// Adds a new node to the beginning of the list.
	/// </summary>
	/// <param name="NodeValue:"> Value of the newly added node. </param>
	void prependNode(T nodeData);

	/// <summary>
	/// Adds a node to the end of the list.
	/// </summary>
	/// <param name="NodeValue:"> Value of the newly added node. </param>
	void appendNode(T nodeData);

	// Removes the head/first node of the list and moves the head to its next node.
	void removeHeadNode();

	/// <summary>
	/// Removes the tail/last node of the list and re-assigns the tail to the node
	/// that was previously before the tail.
	/// </summary>
	void removeTailNode();

	/// <summary>
	/// Creates a new node and inserts it into the list at the specified
	/// location only if the location of the insert is valid. Adjusts the
	/// newly created order of nodes to follow the singly linked list structure.
	/// </summary>
	/// <param name="NodeValue:"> Value of the node that is going to be inserted. </param>
	/// <param name="InsertPosition:"> Position of where the insertion happens (0 is the starting position).</param>
	void insertNodeAtLocation(T nodeData, int insertPosition);

	/// <summary>
	/// Removes a node at the specified location if that location is valid.
	/// Adjusts the remaining nodes to follow the singly linked list structure.
	/// </summary>
	/// <param name="RemovePosition:"> Position of where the deletion happens. </param>
	void removeNodeAtLocation(int removePosition);

	/// <returns> Head of the linked list. </returns>
	Node<T>* getRootNode() const { return m_head; }

	/// <summary>
	/// Checks whether a linked list is cyclic by using
	/// a slow and fast pointer. Slow one moves one node
	/// at a time, fast one moves two at a time. If they
	/// end up the same the list is cyclic and if any one
	/// of them reaches the end, then the list isn't cyclic.
	/// </summary>
	/// <returns>  Whether a linked list is cyclic. </returns>
	bool isCyclicList();

private:

	// First Node of the linked list.
	Node<T>* m_head;

	// Last Node of the linked list.
	Node<T>* m_tail;

	// Represents the number of Nodes inside the list.
	int m_listSize;

	// Shows if this list is doubly linked or singly linked.
	bool m_isDoublyLinked;
};

template<typename T>
inline void LinkedList<T>::prependNode(T nodeData)
{
	Node<T>* newNode = new Node<T>(nodeData);

	newNode->setNextNode(m_head);

	if (m_isDoublyLinked == true) { m_head->setPreviousNode(newNode); }

	m_head = newNode;
}

template<typename T>
inline void LinkedList<T>::appendNode(T nodeData)
{
	if (m_isDoublyLinked == true) 
	{ 
		m_tail->setNextNode(new Node<T>(nodeData, nullptr, m_tail));
	}
	else { m_tail->setNextNode(new Node<T>(nodeData));	}

	m_tail = m_tail->getNextNode();
	m_listSize++;
}

template<typename T>
inline void LinkedList<T>::removeHeadNode()
{
	Node<T>* nodeToRemove = m_head;

	m_head = m_head->getNextNode();

	if (m_isDoublyLinked == true) { m_head->setPreviousNode(nullptr); }

	delete nodeToRemove;
	m_listSize--;
}

template<typename T>
inline void LinkedList<T>::removeTailNode()
{
	Node<T>* currentNode = m_head;

	while (currentNode->getNextNode() != m_tail)
	{
		currentNode = currentNode->getNextNode();
	}

	delete currentNode->getNextNode();

	currentNode->setNextNode(nullptr);

	m_tail = currentNode;

	m_listSize--;
}
