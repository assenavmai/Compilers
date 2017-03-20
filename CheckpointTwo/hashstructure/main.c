#include "hash.h"


int main(int argc, char const *argv[])
{

	struct HTable * ht;
	struct Entry * find;

	ht = create(1000);

	insert(ht, "1", 1, 0, 3);
	/*insert(ht, "2", 1, 0, 3);
	insert(ht, "3", 1, 0, 3);
	insert(ht, "4", 1, 0, 3);*/

//printTable(ht);
	/*find = lookup(ht, "1");

	if(find)
	{
		printf("Found value\n");
	}
	printTable(ht);

	deleteKey(ht, "3");

	printTable(ht);*/
	return 0;
}