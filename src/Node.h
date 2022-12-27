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
		m_NodeValue(NodeValue), m_NextNode(nullptr) {};

	/// <summary>
	/// Constructor for setting both the value  
	/// and the next node for the created one.
	/// </summary>
	/// <param name="NodeValue:"> Templated parameter for the value of the node. </param>
	/// <param name="NextNode:"> Node to which this one is pointing to. </param>
	Node(T NodeValue, Node* NextNode) :
		m_NodeValue(NodeValue), m_NextNode(NextNode) {};
	
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

	/// <returns> Member variable for the node value. </returns>
	T GetNodeValue() const { return m_NodeValue; }

	/// <returns> Member variable for the next node pointer. </returns>
	Node<T>* GetNextNode() const { return m_NextNode; };

private:

	/// <summary>
	/// Templated value that this node contains.
	/// </summary>
	T m_NodeValue;

	/// <summary>
	/// Pointer to the next node in the linked list structure.
	/// </summary>
	Node* m_NextNode;
};