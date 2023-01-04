#include <tree.cpp>
#include <fstream>

int main()
{
	Tree<int>* tree = new Tree<int>(1);

	TreeNode<int>* node_1 = new TreeNode<int>(2);
	TreeNode<int>* node_2 = new TreeNode<int>(3);
	TreeNode<int>* node_3 = new TreeNode<int>(4);
	TreeNode<int>* node_4 = new TreeNode<int>(5);
	TreeNode<int>* node_5 = new TreeNode<int>(6);
	TreeNode<int>* node_6 = new TreeNode<int>(7);
	TreeNode<int>* node_7 = new TreeNode<int>(8);

	tree->getRoot()->addChild(node_1);
	tree->getRoot()->addChild(node_4);
	tree->getRoot()->addChild(node_5);

	node_1->addChild(node_2);
	node_2->addChild(node_3);

	node_5->addChild(node_6);
	node_5->addChild(node_7);

	std::ofstream dotFile("tree.dot");

	tree->generateDotFile(dotFile);
}