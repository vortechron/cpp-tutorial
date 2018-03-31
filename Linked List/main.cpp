#include <iostream>
#include <stdlib.h>
#include <string.h>

struct student
{
	char name[100];
	struct student *next;
};

student *head = NULL;

void printMenu();
void addBegin();
void addEnd();
void deleteBegin();
void deleteEnd();
void deleteAnywhere();
void deleteRecursively(student *prev, student *temp, char searchedName[]);
void traversalDelete(student *prev, student *current, char searchedName[]);
void displayAllNode();
void createStudents();

int main(int argc, char** argv) {

	createStudents();
	
	int choice;
	restart: while(1)
	{
		printMenu();

		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				addBegin();
				displayAllNode();
				break;
			case 2:
				addEnd();
				displayAllNode();
				break;
			case 3:
				deleteBegin();
				displayAllNode();
				break;
			case 4:
				deleteEnd();
				displayAllNode();
				break;
			case 5:
				deleteAnywhere();
				displayAllNode();
				break;
			case 6:
				printf("Thank you :)\nExiting...");
				break;
			default:
				goto restart;
				break;
		}

		if(choice == 6){
			break;
		}
	}
	
	return 0;
}

void printMenu()
{
	printf("\nMenu\n");
	printf("\n1. Add begin");
	printf("\n2. Add end");
	printf("\n3. Delete begin");
	printf("\n4. Delete end");
	printf("\n5. Delete anywhere");
	printf("\n6. End");
	printf("\n\nChoose a menu: ");
}

void createStudents()
{
	int choice;
	while(1)
	{
		// ask user whether they want to keep creating student
		printf("\nDo you want to create students? (0 = no, 1 = yes): ");
		scanf("%d", &choice);

		// if user input is 0, we stop creating new student
		if(choice == 0){
			break;
		}

		// create new student
		// we just call addEnd function.
		// p/s: you also can use addbegin
		addEnd();
	}

	displayAllNode();
}

void displayAllNode()
{
	
	// always create temporary node
	// and assign head ptr to it
	student *temp = head;

	printf("\n\nMy node\n");

	// then we traverse each node with temporary pointer but
	// not head pointer. we dont want to touch/change head pointer
	// the sole purpose of head pointer is to point at the first node.
	// thats why we always assign head to new pointer
	while(temp != NULL){
		printf("%s--->", temp->name);

		temp = temp->next;
	}

	free(temp);

	printf("NULL\n\n");
}

void addBegin()
{
	// create new pointer that point to empty node
	student *newNode = (student *) malloc(sizeof(student));

	// then we assign name into empty node
	printf("Insert student name: ");
	scanf("%s", newNode->name);

	// this will put new node at the front
	newNode->next = head;

	// we need to re-point head back into the 
	// first node. this is important or else our head will 
	// disorder
	head = newNode;
}

void addEnd()
{
	// explained at above docs
	student *temp = head;
	student *newNode = (student *) malloc(sizeof(student));

	printf("Insert student name: ");
	scanf("%s", newNode->name);

	// we do a simple check to see if our head
	// is empty then we assign new node to it.
	if(head == NULL){
		head = newNode;
		head->next = NULL;
		return;
	}

	// else we will traverse each nodes with temporary ptn
	// and check: if it reach last node then assign new node to it next ptr
	while(temp != NULL){

		if(temp->next == NULL){
			temp->next = newNode;
			return;
		}

		temp = temp->next;
	}


}

void deleteBegin()
{
	// do a simple check to see:
	// if our nodes is empty then exit function
	if(head == NULL){
		return;
	}

	student *temp = head;

	// else move head to next node
	head = temp->next;

	// then we break the chain by assiging it
	// to null
	
}

void deleteEnd()
{
	student *temp = head;

	// simple check to see if node if empty adn exit
	// this function
	if(head == NULL){
		return;
	}

	// else if only has one node, call delete begin function
	if(temp->next == NULL){
		deleteBegin();
		return;
	}

	// else traverse each node but skip last node.
	while(temp->next->next!=NULL){
	    temp = temp->next;
	}

	// this will remove last node from the list
	temp->next = NULL;
}

void deleteAnywhere()
{
	if(head == NULL){
		return;
	}
	
	student *temp = head->next;
	student *prev = head;
	char name[100];

	// get the name of student that we want to delete
	printf("Insert student that you want to delete: ");
	scanf("%s", &name);

	// then we will call this function recursively
	// until it find the name
	traversalDelete(prev, temp, name); // method: 1
	// deleteRecursively(prev, temp, name); // method: 2
}

void deleteRecursively(student *prev, student *temp, char searchedName[])
{
	if(temp == NULL){

		printf("Student not found\n");

	}else if(strcmp(searchedName, temp->name) == 0){

		// this section will be executed when the student is found on the list
		
		printf("Student found and deleted!\n");

		// do a simple check to see if temp is same as head
		if(temp == head)
		{
			head = temp->next;
			temp->next = NULL;
			return;
		}

		// else we will assign prev ptr to its second next node,
		// not first next node. we will skip first next node because its
		// the node that we want to delete
		prev->next = prev->next->next;

		return;

	}else{

		// call this function again but different head and prev

		deleteRecursively(temp, temp->next, searchedName);

	}
}

void traversalDelete(student *prev, student *temp, char searchedName[])
{
	if(strcmp(searchedName, head->name) == 0){
		printf("Student found and deleted! first\n");
		head = head->next;
		return;
	}
	
	while(temp != NULL){
		
		if(strcmp(searchedName, temp->name) == 0){
			printf("Student found and deleted!\n");
			prev->next = temp->next;
			return;
		}
		
		prev = temp;
		temp = temp->next;
	}
}
