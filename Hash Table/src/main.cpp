#include <hash-table.h>

int main()
{
	HashTable* table = new HashTable();

	table->insert("Simple");
	table->insert("Hash");
	table->insert("Table");
	table->insert("Implementation");
	table->insert("C++"); 

	table->remove("C++");

	table->printTable();

	return 0;
}