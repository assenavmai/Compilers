#include "entry.h"

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
	return 0;
}