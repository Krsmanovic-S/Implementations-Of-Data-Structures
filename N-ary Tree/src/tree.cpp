#include <tree.h>
#include <iostream>

template<typename T>
void TreeNode<T>::removeChild(int pos)
{
	if (pos > m_children.size() - 1)
	{
		std::cerr << "Child index out of bounds.";
		return;
	}

	m_children.erase(m_children.begin() + pos);
}

template<typename T>
void Tree<T>::preorderTraversal(TreeNode<T>* root) const
{
    if (root == nullptr) { return; }

    std::cout << root->getData() << " ";

    for (auto* child : root->getChildren()) 
    {
        this->preorderTraversal(child);
    }
}

template<typename T>
void Tree<T>::postorderTraversal(TreeNode<T>* root) const
{
    if (root == nullptr) { return; }

    for (auto* child : root->getChildren())
    {
        this->postorderTraversal(child);
    }

    std::cout << root->getData() << " ";
}

template<typename T>
int Tree<T>::getTreeSize(TreeNode<T>* root)
{
    if (root == nullptr) { return 0; }

    int treeSize = 1;

    for (auto* child : root->getChildren())
    {
        treeSize += this->getTreeSize(child);
    }

    return treeSize;
}