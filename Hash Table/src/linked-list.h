#pragma once

#include <string>


/// <summary>
/// Class for individual nodes for the linked list,
/// contains the node value and the next node pointer.
/// </summary>
class Node
{

public:

	/// <summary>
	/// Constructor that just sets the value of the node 
	/// while the next Node is explicitly set to nullptr.
	/// </summary>
	/// <param name="inputData:"> Parameter for the value of the node. </param>
	Node(std::string inputData) :
		m_nodeData(inputData), m_nextNode(nullptr) {}

	/// <summary>
	/// Setter for the member m_nextNode.
	/// </summary>
	/// <param name="nodeToSet:"> New Node to which the m_NextNode will point to. </param>
	void setNextNode(Node* nodeToSet) { m_nextNode = nodeToSet; }

	/// <returns> Node value by value. </returns>
	inline std::string getNodeData() const { return m_nodeData; }

	/// <returns> Node value by value. </returns>
	inline std::string& getNodeDataAsReference() { return m_nodeData; }

	/// <returns> Member variable representing the next node pointer. </returns>
	inline Node* getNextNode() const { return m_nextNode; }

private:

	// Data contained in this node.
	std::string m_nodeData;

	// Pointer to the next node in the linked list structure.
	Node* m_nextNode;
};


/// <summary>
/// Class representing a linked list, contains methods
/// for adding, deleting, inserting and printing the list.
/// </summary>
class LinkedList
{

public:

	class Iterator
	{
	public:

		Iterator(Node* inputNode) : m_iteratedNode(inputNode), m_iteratorPosition(0) {}

		/// <summary>
		/// Overloading the * operator to get the reference
		/// of the node value that the iterator is pointing to.
		/// </summary>
		/// <returns> Iterators node value as reference. </returns>
		std::string& operator*() { return m_iteratedNode->getNodeDataAsReference(); }

		// Overload the ++ operator to move to the next element.
		Iterator& operator++() {
			if (m_iteratedNode != nullptr)
			{
				m_iteratedNode = m_iteratedNode->getNextNode();
			}

			m_iteratorPosition++;

			return *this;
		}

		// Overload the != operator to compare iterators.
		bool operator!=(const Iterator& otherIterator)
		{
			return m_iteratedNode != otherIterator.m_iteratedNode;
		}

		/// <returns> Position of the iterator relative to the beginning of the list.</returns>
		int getIteratorPosition() const { return m_iteratorPosition; }

	private:

		// Pointer to the currently iterated element.
		Node* m_iteratedNode;

		// Position of the iterator inside the list.
		int m_iteratorPosition;
	};

	/// <returns> Iterator pointing to the beginning of the list. </returns>
	LinkedList::Iterator begin() { return Iterator(m_head); }

	/// <returns> Iterator pointing to the end of the list. </returns>
	LinkedList::Iterator end() { return Iterator(nullptr); }

public:

	LinkedList() : m_head(nullptr), m_tail(nullptr), m_listSize(1) {}

	// Deletes all the nodes in the list from head to tail.
	~LinkedList();

	// Displays all the node values with std::cout in head to tail order.  
	void printEntireList() const;

	/// <returns> Head node of the linked list. </returns>
	Node* getHeadPointer() const { return m_head; }

	/// <summary>
	/// Sets the value of the head node to a new node.
	/// </summary>
	/// <param name="node:"> New node that is assigned to the head. </param>
	void setHeadData(Node* node) { m_head = node; }

	/// <summary>
	/// Sets the value of the tail node to a new node.
	/// </summary>
	/// <param name="node:"> New node that is assigned to the tail. </param>
	void setTailData(Node* node) { m_tail = node; }

	/// <summary>
	/// Adds a node to the end of the list.
	/// </summary>
	/// <param name="nodeData:"> Value of the newly added node. </param>
	void appendNode(std::string nodeData);

	// Removes the head/first node of the list and moves the head to its next node.
	void removeHeadNode();

	/// <summary>
	/// Removes the tail/last node of the list and re-assigns the tail to the node
	/// that was previously before the tail.
	/// </summary>
	void removeTailNode();

	/// <summary>
	/// Removes a node at the specified location if that location is valid.
	/// Adjusts the remaining nodes to follow the singly linked list structure.
	/// </summary>
	/// <param name="RemovePosition:"> Position of where the deletion happens. </param>
	void removeNodeAtLocation(int removePosition);

private:

	// First Node of the linked list.
	Node* m_head;

	// Last Node of the linked list.
	Node* m_tail;

	// Represents the number of Nodes inside the list.
	int m_listSize;
};