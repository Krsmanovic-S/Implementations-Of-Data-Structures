#include <tree.cpp>

int main()
{
	Tree<int>* tree = new Tree<int>(1);

	TreeNode<int>* node_1 = new TreeNode<int>(2);
	TreeNode<int>* node_2 = new TreeNode<int>(3);
	TreeNode<int>* node_3 = new TreeNode<int>(4);

	TreeNode<int>* node_4 = new TreeNode<int>(5);
	TreeNode<int>* node_5 = new TreeNode<int>(6);

	tree->getRoot()->addChild(node_1);
	tree->getRoot()->addChild(node_2);
	tree->getRoot()->addChild(node_3);

	node_3->addChild(node_4);
	node_3->addChild(node_5);

	tree->preorderTraversal(tree->getRoot());
	
	std::cout << '\n';

	tree->postorderTraversal(tree->getRoot());

	std::cout << '\n' << '\n';
	
	std::cout << tree->getTreeSize(tree->getRoot());
}