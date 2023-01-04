#pragma once

/// <summary>
/// Class for individual nodes for the linked list,
/// contains the node value and the next node pointer.
/// </summary>
template <typename T>
class Node
{

public:

	/// <summary>
	/// Constructor that just sets the value of the node 
	/// while the next Node is explicitly set to nullptr.
	/// </summary>
	/// <param name="inputData:"> Templated parameter for the value of the node. </param>
	Node(T inputData) :
		m_nodeData(inputData), m_nextNode(nullptr), m_previousNode(nullptr) {}

	/// <summary>
	/// Constructor for setting both the value  
	/// and the next node for the created one.
	/// </summary>
	/// <param name="inputData:"> Templated parameter for the value of the node. </param>
	/// <param name="nextNode:"> Node to which this one is pointing to. </param>
	Node(T inputData, Node* nextNode) :
		m_nodeData(inputData), m_nextNode(nextNode), m_previousNode(nullptr) {}

	/// <summary>
	/// Constructor for setting the value, the next node 
	/// and the previous node for the created one.
	/// </summary>
	/// <param name="inputData:"> Templated parameter for the value of the node. </param>
	/// <param name="nextNode:"> Node to which this one is pointing to. </param>
	/// <param name="nextNode:"> Previous node to which this one is pointing to. </param>
	Node(T inputData, Node* nextNode, Node* prevNode) :
		m_nodeData(inputData), m_nextNode(nextNode), m_previousNode(prevNode) {}
	
	/// <summary>
	/// Setter for the member m_nodeData.
	/// </summary>
	/// <param name="inputData:"> New value for the m_NodeValue. </param>
	void setNodeData(T inputData) { m_nodeData = inputData; }

	/// <summary>
	/// Setter for the member m_nextNode.
	/// </summary>
	/// <param name="nodeToSet:"> New Node to which the m_NextNode will point to. </param>
	void setNextNode(Node* nodeToSet) { m_nextNode = nodeToSet; }

	/// <summary>
	/// Setter for the member m_previousNode.
	/// </summary>
	/// <param name="nodeToSet:"> New node that the previous pointer of the current node will point to. </param>
	void setPreviousNode(Node* nodeToSet) { m_previousNode = nodeToSet; }

	/// <returns> Node value by value. </returns>
	T getNodeData() const { return m_nodeData; }

	/// <returns> Node value by value. </returns>
	T& getNodeDataAsReference() { return m_nodeData; }

	/// <returns> Member variable representing the next node pointer. </returns>
	Node<T>* getNextNode() const { return m_nextNode; }

	/// <returns> Member variable representing the previous node pointer. </returns>
	Node<T>* getPreviousNode() const { return m_previousNode; }

private:

	// Templated value that this node contains.
	T m_nodeData;

	// Pointer to the next node in the linked list structure.
	Node* m_nextNode;

	/// <summary>
	/// Pointer to the previous node in the linked list 
	/// structure. Only used for doubly linked lists.
	/// </summary>
	Node* m_previousNode;
};