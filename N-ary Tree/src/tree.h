#pragma once

#include <vector>

template<typename T>
class TreeNode
{

public:

	TreeNode(T data) : m_nodeData(data) {};

	std::vector<TreeNode<T>*>& getChildren() { return m_children; }

	/// <returns> Data that this node contains. </returns>
	inline T getData() const { return m_nodeData; }

	/// <summary>
	/// Sets the data of this node to a new value.
	/// </summary>
	/// <param name="data"> Data to be set. </param>
	inline void setData(T data) { m_nodeData = data; }

	/// <summary>
	/// Adds a child node to the farthest right of this node.
	/// </summary>
	/// <param name="child"> Child node to be added. </param>
	inline void addChild(TreeNode<T>* child) { m_children.push_back(child); }

	/// <summary>
	/// Removes a child at a specified location
	/// where 0 is farthest left child and the
	/// size of the child vector is the farthest right.
	/// </summary>
	/// <param name="pos"> Position in the children vector where we erase. </param>
	void removeChild(int pos);

private:

	T m_nodeData;

	std::vector<TreeNode<T>*> m_children;
};

template<typename T>
class Tree
{

public:

	Tree(T rootData) : m_root(new TreeNode<T>(rootData)) {};

	/// <returns> Root node of this tree. </returns>
	TreeNode<T>* getRoot() const { return m_root; };

	// Prints the values in the tree with a preorder (left->right) traversal.
	void preorderTraversal(TreeNode<T>* root) const;

	// Prints the values in the tree with a postorder (right->left) traversal.
	void postorderTraversal(TreeNode<T>* root) const;

	/// <summary>
	/// Performs a preorder traversal to count the total nodes.
	/// </summary>
	/// <returns> Number of nodes in the tree. </returns>
	int getTreeSize(TreeNode<T>* root);

private:

	TreeNode<T>* m_root;
};

