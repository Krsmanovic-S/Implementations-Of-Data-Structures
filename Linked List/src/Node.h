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
	/// <param name="NodeValue:"> Templated parameter for the value of the node. </param>
	Node(T NodeValue) :
		m_NodeValue(NodeValue), m_NextNode(nullptr), m_PreviousNode(nullptr) {};

	/// <summary>
	/// Constructor for setting both the value  
	/// and the next node for the created one.
	/// </summary>
	/// <param name="NodeValue:"> Templated parameter for the value of the node. </param>
	/// <param name="NextNode:"> Node to which this one is pointing to. </param>
	Node(T NodeValue, Node* NextNode) :
		m_NodeValue(NodeValue), m_NextNode(NextNode), m_PreviousNode(nullptr) {};

	/// <summary>
	/// Constructor for setting the value, the next node 
	/// and the previous node for the created one.
	/// </summary>
	/// <param name="NodeValue:"> Templated parameter for the value of the node. </param>
	/// <param name="NextNode:"> Node to which this one is pointing to. </param>
	/// <param name="PrevNode:"> Previous node to which this one is pointing to. </param>
	Node(T NodeValue, Node* NextNode, Node* PrevNode) :
		m_NodeValue(NodeValue), m_NextNode(NextNode), m_PreviousNode(PrevNode) {};
	
	/// <summary>
	/// Setter for the member m_NodeValue.
	/// </summary>
	/// <param name="InputValue:"> New value for the m_NodeValue. </param>
	void SetNodeValue(T InputValue) { m_NodeValue = InputValue; }

	/// <summary>
	/// Setter for the member m_NextNode.
	/// </summary>
	/// <param name="InputValue:"> New Node to which the m_NextNode will point to. </param>
	void SetNextNode(Node* NodeToSet) { m_NextNode = NodeToSet; }

	/// <summary>
	/// Setter for the member m_PreviousNode.
	/// </summary>
	/// <param name="NodeToSet:"> New node that the previous pointer of the current node will point to. </param>
	void SetPreviousNode(Node* NodeToSet) { m_PreviousNode = NodeToSet; }

	/// <returns> Member variable representing the node value. </returns>
	T GetNodeValue() const { return m_NodeValue; }

	/// <returns> Member variable representing the next node pointer. </returns>
	Node<T>* GetNextNode() const { return m_NextNode; };

	/// <returns> Member variable representing the previous node pointer. </returns>
	Node<T>* GetPreviousNode() const { return m_PreviousNode; };

private:

	/// <summary>
	/// Templated value that this node contains.
	/// </summary>
	T m_NodeValue;

	/// <summary>
	/// Pointer to the next node in the linked list structure.
	/// </summary>
	Node* m_NextNode;

	/// <summary>
	/// Pointer to the previous node in the linked list 
	/// structure. Only used for doubly linked lists.
	/// </summary>
	Node* m_PreviousNode;
};