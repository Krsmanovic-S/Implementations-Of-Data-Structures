#include <hash-table.h>
#include <linked-list.cpp>
#include <iostream>

HashTable::HashTable()
{
    for (int i = 0; i < m_hashGroups; i++)
    {
        m_table.push_back({ i, new LinkedList() });
    }
}

int HashTable::hashKey(std::string input)
{
    // These two prime numbers are used with the
    // FNV-1a algorithm as starting points for hashing.
    constexpr unsigned int fnv_prime = 16777259;
    unsigned int hash = 2166136261;

    for (char c : input) 
    {
        hash = hash ^ c;
        hash = hash * fnv_prime;
    }

    return hash % m_hashGroups;
}

void HashTable::insert(std::string value)
{
    int hashValue = this->hashKey(value);

    LinkedList* tableList = m_table[hashValue].second;

    // Look for this value first and if it exists, inform
    // the user and do not add the same value again.
    for (auto it = tableList->begin(); it != tableList->end(); ++it)
    {
        if (*it == value)
        {
            std::cout << "Value already exists in the hash table." << '\n';
            return;
        }
    }

    if (tableList->getHeadPointer() == nullptr)
    { 
        Node* inputNode = new Node(value);

        tableList->setHeadData(inputNode);
        tableList->setTailData(inputNode);
    }
    else { tableList->appendNode(value); }
}

void HashTable::remove(std::string value)
{
    int hashValue = this->hashKey(value);

    LinkedList* tableList = m_table[hashValue].second;

    for (auto it = tableList->begin(); it != tableList->end(); ++it)
    {
        if (*it == value)
        {
            tableList->removeNodeAtLocation(it.getIteratorPosition());

            std::cout << "Removed '" << value << "' from the hash table." << '\n' << '\n';
            return;
        }
    }
}

bool HashTable::isEmpty()
{
    LinkedList* tableList;

    for (int i = 0; i < m_hashGroups; i++)
    {
        tableList = m_table[i].second;

        for (auto it = tableList->begin(); it != tableList->end(); ++it)
        {
            if (!(*it).empty()) return false;
        }
    }

    return true;
}

void HashTable::printTable()
{
    for (auto pair : m_table)
    {
        std::cout << "Key: " << pair.first << " || ";

        std::cout << "Values: ";

        if (pair.second != nullptr) { pair.second->printEntireList(); }

        std::cout << '\n';
    }
}