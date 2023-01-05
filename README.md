![title](https://user-images.githubusercontent.com/103185975/210466763-68bda1d3-de95-4385-a395-d8fc930f8ef9.png)

- - - -

:wave: Welcome to the "Implementations of Data Structures" repository! This repository contains various implementations of common data structures in C++. These data structures include:

&nbsp;&nbsp;:small_blue_diamond: Linked lists

&nbsp;&nbsp;:small_blue_diamond: Stacks

&nbsp;&nbsp;:small_blue_diamond: Queues

&nbsp;&nbsp;:small_blue_diamond: Trees

Each data structure is implemented as a standalone class, with member functions for common operations such as ___insertion, deletion, printing and searching___. The implementation is designed to be easy to understand and use, with well-documented code and clear function names. The different structures are all ___templated___, currently supporting the following types: ___integer, float, double, char and std::string___.

This repository is a great resource for anyone looking to learn about data structures or brush up on their skills. Whether you are a beginner or an experienced programmer, you will find something of value here. I hope you enjoy and let's dive straight into it!

- - - -

## Hash Table

A hash table is a data structure that stores a set of key-value pairs and uses a ___hash function___ to map keys to indices in an array. When a key-value pair is inserted into the hash table, the hash function is used to determine the index in the array where the value should be stored. If the index is already occupied by another value, then the hash table uses a collision resolution strategy to find an alternative location for the value.

With this implementation, we are handling collisions with a closed addressing method utilizing linked lists. To put it simply, whenever a value needs to go into a space where we already have something, we will just attach it to the end of the linked list there. The table that is implemented here is using integers as keys and linked lists as values. The nodes in these lists are storing strings.

  * The hash method that we are using is the ___FNV-1a algorithm___, this method does not have to be used but has been proven to produce good hash values

Implementation currently supports the following methods:

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Calculate a hash key for any given string value

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Insert a value (no duplicates allowed)

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Remove a value

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Check if the table is empty

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Print all key/value pairs

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Use iterators to traverse the table

## Linked List

This is a data structure consists of two parts - individual nodes and a class for the list itself. ___Nodes___ are very simple, each has these key elements:
  * **Data** represented in that node
  * Pointer to the **next node** in the chain
  * Pointer to the **previous node** in the chain

We only use the ___previous node___ pointer when we are dealing with doubly linked lists, in singly linked ones this information is not needed. Lists themselves have just the information about the first node in that list, called the ___head___, which is used for traversal alongside the entire list. This is done by utilizing the 'next node' pointer when assembling the list. The end of the list is called the ___tail___, this is the node that has the next pointer set to nullptr, which means the list is null-terminated.

Implementation currently supports singly and doubly linked lists that are implemented with the following features:

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Append/Prepend a node
  
&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Remove head/tail node
  
&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Insert/delete a node in a desired position
  
&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Print all node values in the list
  
&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Use iterators for traversing from one node to the next
  
## N-ary Trees

An n-ary tree is a tree data structure in which each node has at most ___n___ children. N-ary trees are a generalization of binary trees, which are trees in which each node has at most two children. Each node has two parts:
  * ___Data___ that is stored inside the node
  * ___An array___ of all the children of that node

The class for the tree itself just stores the information about the first node in the tree, called the ___root___ node. Every other node is accessed by traversing the tree using this root node. Common traversals include:

:small_blue_diamond: ___Pre-order traversal___: In a pre-order traversal, the root node is visited first, followed by the subtrees of the left child, then the subtrees of the right child.

:small_blue_diamond: ___In-order traversal___: In an in-order traversal, the left subtree of the root node is visited first, followed by the root node itself, then the right subtree.

:small_blue_diamond: ___Post-order traversal___: In a post-order traversal, the subtrees of the left child are visited first, followed by the subtrees of the right child, and finally the root node is visited.

:small_blue_diamond: ___Level-order traversal___: In a level-order traversal, the nodes of the tree are visited level by level, starting from the root node and proceeding through the levels from top to bottom.

![text_separator](https://user-images.githubusercontent.com/103185975/210472648-353e2123-a800-4f99-9e63-7d8178c468db.png)

Implementation currently supports the following methods:

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Add a child node to an existing one

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Insert a child node at a specific place

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Remove a child node at a specific index

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Preorder/Postorder traversal

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Print all node values in the tree

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Access the size of the tree (total nodes)

I have also included the **Graphviz** library here for generating the visual representation of the tree.
This library is used by first generating the dot file and then using it to produce a png file. 

Example picture:

![tree](https://user-images.githubusercontent.com/103185975/209895522-3c513da2-d00a-4be5-9d3b-5dde4725574e.png)

## Stack

A stack is a linear data structure that allows elements to be added and removed only from the top of the stack. This behavior is known as last-in, first-out (___LIFO___) and is similar to a stack of plates in a cafeteria. Here we are implementing it with the ___std::vector___ container, but the STL library does offer it's own std::stack.

Implementation currently supports the following methods:

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Push a new value onto the stack
 
&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Pop a value from the top of the stack
 
&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Get the value located at the top
 
&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Check whether a stack is empty or not
 
&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Print all values in the stack

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Use iterators for travering the stack

## Queue

A queue is a linear data structure that allows elements to be added only to the back of the queue and removed only from the front of the queue. This behavior is known as first-in, first-out (___FIFO___) and is similar to a line of people waiting in line at the mall. We are implementing it here with the ___std::vector___ container, similarly to how we did the stack.

Implementation currently supports the following methods:

&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Push a new value onto the queue
 
&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Pop a value from the front of the queue
 
&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Get the value located at the front
 
&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Check whether a queue is empty or not
 
&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Print all values in the queue
 
&nbsp;&nbsp;&nbsp;&nbsp;:small_blue_diamond: Use iterators for travering the queue

- - - -
