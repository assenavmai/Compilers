#include "hash.h"


int main(int argc, char const *argv[])
{

	struct HTable * ht;
	struct entryList * find;

	ht = create(239);

	insert(ht, "1", 1, 0, 3);
	//insert(ht, "2", 1, 0, 3);
	//insert(ht, "3", 1, 0, 3);
	//insert(ht, "4", 1, 0, 3);

	printHash(ht);

	find = lookup(ht, "1");

	if(find)
	{
		printf("Found value\n");
	}

	deleteKey(ht, "2");

	printHash(ht);

	destroyTable(ht);


	//printHash(ht);

	return 0;
}