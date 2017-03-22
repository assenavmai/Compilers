#include "list.h"

/****
 NODE FUNCTIONS
****/
struct entryNode * initnode(char * key, enum ExpType type, int tokenValue, int lineno) {

	struct entryNode * this;

	this = malloc(sizeof(struct entryNode));

	if(this)
	{		
		strcpy(this->key, key);
		this->type = type;
		this->tokenValue = tokenValue;
		this->lineno = lineno;

		return this;
	}

	return NULL;
}

struct entryNode * insertNode(struct entryNode * this, char * key, enum ExpType type, int tokenValue, int lineno) {

	struct entryNode * newData, *temp;


	newData = initnode(key, type, tokenValue, lineno);

	if(!newData)
	{
		return NULL;
	}

	if(!this)
	{
		newData->next = NULL;
		return newData;
	}
	else
	{
		temp = this;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newData;
		newData->next = NULL;

		return temp;
	}

	return NULL;
}

struct entryNode * deleteNode(struct entryNode * this) {

	struct entryNode * temp;
		//printf("temp %s\n", this->key);


	if(!this)
	{
		return NULL;
	}
	else
	{
		//temp = this->next;
		this->key[0] = '\0';
		this->type = 0;
		this->tokenValue = 0;
		this->lineno = 0;
		//free(this);

		return this;
	}

	return NULL;
}

struct entryList * createList() {

	struct entryList * this;

	this = malloc(sizeof(struct entryList));

	if(this)
	{
		this->head = NULL;
		//this->curr = NULL;
		this->size = 0;
		this->id = 0;
		this->name[0] = '\0'; //check

		return this;
	}

	return NULL;
}

/****
 LIST FUNCTIONS
****/
void destroyList(struct entryLisr * this) {

	struct entryNode * rm;
	struct entryList *temp;

	/*if(!this)
	{
		printf("end of list\n");		
		return;
	}
	deleteNode(this);
	destroyList(this->next);

	this->next = NULL;
	free(this);*/
}

struct entryList * addToList(struct entryList * this, char * key, enum ExpType type, int tokenValue, int lineno) {

	this->head = insertNode(this->head, key, type, tokenValue, lineno);

}

void removeFromList(struct entryList * this) {

	this->head = deleteNode(this->head);
}

void printList(struct entryNode * this) {

	struct entryNode *temp;

	if(!this || this->key == '\0')
	{
		fprintf(stderr, "List is empty.\n" );
		return;
	}


	printf("key[%s]: type: %d token: %d line: %d\n", this->key, this->type, this->tokenValue, this->lineno);
	
	printList(this->next);
}

/*int main(int argc, char const *argv[])
{

	struct entryList * list;

	list = createList();


	addToList(list, "1", 1, 0, 0);

	addToList(list, "2", 1, 0, 0);
	
	printList(list->head);

	//removeFromList(list);

	printList(list->head);

	destroyList(list->head);

	free(list);
	//printList(list->head);

	return 0;
}
*/
