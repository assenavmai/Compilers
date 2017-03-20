#include "hash.h"


int main(int argc, char const *argv[])
{
	/*struct Entry * ent;
	struct Entry * newN;

	ent = createEntryList();
	newN = newEntryNode("key1", 1, 0, 0);
	ent = addToFront(ent, newN);
	newN = newEntryNode("key1", 1, 0, 0);
	ent = addToFront(ent, newN);newN = newEntryNode("key1", 1, 0, 0);
	ent = addToFront(ent, newN);newN = newEntryNode("key1", 1, 0, 0);
	ent = addToFront(ent, newN);newN = newEntryNode("key1", 1, 0, 0);
	ent = addToFront(ent, newN);newN = newEntryNode("key1", 1, 0, 0);
	ent = addToFront(ent, newN);newN = newEntryNode("key1", 1, 0, 0);
	ent = addToFront(ent, newN);newN = newEntryNode("key1", 1, 0, 0);
	ent = addToFront(ent, newN);newN = newEntryNode("key1", 1, 0, 0);
	ent = addToFront(ent, newN);
	printEntries(ent);

	ent = removeFromFront(ent);

	
	printEntries(ent);
	struct Entry *temp;

	while(ent)
	{
		temp = ent;
		ent = ent->next;
		destroyEntries(temp);
	}

	free(ent);*/


	struct HTable * ht;
	struct Entry * find;

	ht = create(1000);

	insert(ht, "1", 1, 0, 3);
	insert(ht, "2", 1, 0, 3);
	insert(ht, "3", 1, 0, 3);
	insert(ht, "4", 1, 0, 3);

	find = lookup(ht, "1");

	if(find)
	{
		printf("Found value\n");
	}
	printTable(ht);

	deleteKey(ht, "3");

	printTable(ht);
	return 0;
}