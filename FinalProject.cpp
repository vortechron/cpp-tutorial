#include <iostream> // to use cin or cout
#include <stdlib.h> // general library
#include <string.h> // to use string related function
#include <stdio.h>

using namespace std;

struct task
{
	char name[100];
	
	struct extra{
		int priority;
	}info;
	
	struct task *next;
};

// initialize global variable
task *head = NULL;

// Function prototype (declaration)
void printMenu();
void addBegin();
void addEnd();
void deleteBegin();
void deleteEnd();
void deleteAnywhere();
void displayAllNode();
void sortAscending();
void sortDescending();
task* createTask();

int main(int argc, char** argv) {
	
	int choice;
	restart: while(1)
	{
		printMenu();

		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				addEnd();
				displayAllNode();
				break;
			case 2:
				deleteEnd();
				displayAllNode();
				break;
			case 3:
				deleteAnywhere();
				displayAllNode();
				break;
			case 4:
				sortAscending();
				displayAllNode();
				break;
			case 5:
				sortDescending();
				displayAllNode();
				break;
			case 0:
				printf("Thank you :)\nExiting...");
				break;
			default:
				goto restart;
				break;
		}

		if(choice == 0){
			break;
		}
	}
	
	return 0;
}

void printMenu()
{
	printf(
		"\nMenu\n"
		"\n1. Add Task"
		"\n2. Delete Task"
		"\n3. Delete anywhere"
		"\n4. Sort ascending"
		"\n5. Sort descending"
		"\n0. End"
		"\n\nChoose a menu: "
	);
}

void displayAllNode()
{
	// always create temporary node
	// and assign head ptr to it
	task *temp = head;

	printf("\n\nMy Todo List\n");

	// then we traverse each node with temporary pointer but
	// not head pointer. we dont want to touch/change head pointer
	// the sole purpose of head pointer is to point at the first node.
	// thats why we always assign head to new pointer
    int counter = 0;
	while(temp != NULL){
        counter++;
		printf("\n%d. %s | %d", counter, temp->name, temp->info.priority);

		temp = temp->next;
	}

    if (counter == 0) {
        printf("~~ Your list is empty ~~");
    }

    printf("\n\n");
}

void addBegin()
{
	// create new pointer that point to empty node
	task *newNode = createTask();

	// this will put new node at the front
	newNode->next = head;

	// we need to re-point head back into the 
	// first node. this is important or else our head will 
	// disorder
	head = newNode;
}

void addEnd()
{
	// we do a simple check to see if our head is empty
	if(head == NULL){
		addBegin();
		return;
	}
	
	task *temp = head;
	task *newNode = createTask();
	
	newNode->next = NULL;

	// else we will traverse each nodes with temporary ptn
	// and check: if it reach last node then assign new node to it next ptr
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = newNode;
}

void deleteBegin()
{
	// do a simple check to see:
	// if our nodes is empty then exit function
	if(head == NULL){
		return;
	}

	task *temp = head;

	// else move head to next node
	head = temp->next;
	
	// deallocate
	free(temp);
}

void deleteEnd()
{
	task *temp = head;

	// simple check to see if node if empty adn exit this function
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

    task *temp = head->next;
	task *prev = head;
    int target;

	// get the name of task that we want to delete
	printf("Insert task number that you want to delete: ");
	scanf("%d", &target);
	
    int counter = 1;
    
    if (target == 1) {
        printf("Task found and deleted!\n");
        deleteBegin();
        return;
	}

    // traverse each node and do the check
	while(temp != NULL){
        counter++;

        if (counter == target) {
            printf("Task found and deleted!\n");
			prev->next = temp->next;
			return;
        }
		
		prev = temp;
		temp = temp->next;
	}
	
	printf("Task not found\n");
}

void sortAscending()
{
    task *i = head,*j =head;

	// i is to loop for n-number of node only
    while(i!=NULL){
    	// j is to loop or each loop and compare it with the next node
        while(j->next!=NULL){
            if(j->info.priority > j->next->info.priority){
            	// swap the data if prev is larger than next
            	task temp = *j;
            	
                j->info.priority = j->next->info.priority;
                strcpy(j->name, j->next->name);
                
                j->next->info.priority = temp.info.priority;
                strcpy(j->next->name, temp.name);
            }
            j=j->next;
        }
        j=head;
        i=i->next;
    }
}


void sortDescending()
{
    task *i = head,*j =head;
	
    while(i!=NULL){
        while(j->next!=NULL){
            if(j->info.priority < j->next->info.priority){
            	task temp = *j;
            	
                j->info.priority = j->next->info.priority;
                strcpy(j->name, j->next->name);
                
                j->next->info.priority = temp.info.priority;
                strcpy(j->next->name, temp.name);
            }
            j=j->next;
        }
        j=head;
        i=i->next;
    }
}

task* createTask()
{
	char name[200];
	cin.clear();
    cin.sync();
    
    // create new pointer that point to empty node
	task *newNode = (task *) malloc(sizeof(task));

	// then we assign name into empty node
	printf("\nWhat is your task? (e.g. wash cloth) : ");
	cin.getline(name, sizeof(name));
	
	printf("What is this task priority: ");
	scanf("%d", &newNode->info.priority);
	
	strcpy(newNode->name, name);

    return newNode;
}
