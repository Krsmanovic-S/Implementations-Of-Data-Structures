#pragma once

#include <string>
#include <vector>
#include <linked-list.h>

/// <summary>
/// Hash table class that utilized the
/// close addressing method for handling
/// collisions and allows only unique
/// data to be stored inside it.
/// </summary>
class HashTable
{

public:

	/// <summary>
	/// Constructor that fills out the table vector with
	/// keys from 0 to m_hashGroups and creates empty
	/// linked lists as a starting point for the keys.
	/// </summary>
	HashTable();
	
	/// <summary>
	/// Using the FNV-1a algorithm to generate a hash key value.
	/// </summary>
	/// <param name="input:"> String for which we calculate the key. </param>
	int hashKey(std::string input);

	/// <summary>
	/// Inserts a new value into the hash table but only if that
	/// value doesn't exist inside. Collisions are dealt with using
	/// the closed addressing method (linked lists).
	/// </summary>
	/// <param name="value:"> String that will try to be added. </param>
	void insert(std::string value);

	/// <summary>
	/// Removes a value from the hash table if it exists inside.
	/// </summary>
	/// <param name="value:"> String to be removed if found. </param>
	void remove(std::string value);

	/// <returns> True if there are no values in the hash table, false otherwise. </returns>
	bool isEmpty();

	// Prints the keys and values of the entire hash table.
	void printTable();

	// Operator overload that returns us the 
	// list at the specified key position.
	LinkedList* operator[] (int key) 
	{
		if(0 <= key < m_hashGroups) { return m_table[key].second; }
		
		return nullptr;
	}

private:

	// Number of groups that this table will have,
	// determines the size of the table vector.
	static const int m_hashGroups = 20;

	// Vector for holding keys and linked lists
	// that are associated with said keys.
	std::vector<std::pair<int, LinkedList*>> m_table;
};