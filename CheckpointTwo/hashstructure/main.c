#include "hash.h"


int main(int argc, char const *argv[])
{
	struct Entry * ent;
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

	free(ent);


	/*struct HTable * ht;

	ht = create(1000);

	insert(ht, "1", 1, 0, 3);

	printTable(ht);*/
	return 0;
}