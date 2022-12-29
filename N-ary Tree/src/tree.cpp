#include <tree.h>
#include <unordered_map>
#include <functional>

// Graphviz library
#include <gvc.h>  

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

template<typename T>
void Tree<T>::generateDotFile(std::ostream& out)
{
    /**
    * Commands that tell Graphviz to generate
    * a node as a circle and the edges as non-directional.
    * Must start with the digraph statement first.
    */
    out << "digraph {" << '\n';
    out << "  node [shape=circle]" << '\n';
    out << "  edge [dir=none]" << '\n';

    /**
    * Map for storing individual node values
    * to a unique integer value.
    */
    std::unordered_map<TreeNode<T>*, int> nodeMap;
    int nextNodeId = 0;

    std::function<void(TreeNode<T>*)> generateDotFileRecursive;

    /**
    * Assings a unique intiger identifier to the input
    * node and adds the value of that nodes data into
    * the map by mapping it to the unique integer.
    */
    generateDotFileRecursive = [&](TreeNode<T>* node) {
        
        if (node == nullptr) { return; }

        int nodeId = nextNodeId++;
        nodeMap[node] = nodeId;

        /**
        * Send the unique id to the command string first,
        * follow it up with the actual value of the node.
        */
        out << "  node" << nodeId << " [label=\"" << node->getData() << "\"]" << std::endl;

        for (auto* child : node->getChildren()) 
        {
            generateDotFileRecursive(child);

            out << "  node" << nodeId << " -> node" << nodeMap[child] << std::endl;
        }
    };

    generateDotFileRecursive(this->getRoot());

    // Adding a closing bracked to the digraph statement
    // at the beginning of the function to complete it.
    out << "}" << std::endl;
}