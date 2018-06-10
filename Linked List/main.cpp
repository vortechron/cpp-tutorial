#include <iostream> // to use cin or cout
#include <stdlib.h> // general library
#include <string.h> // to use string related function

struct student
{
	char name[100];
	
	struct extra{
		int score;
	}info;
	
	struct student *next;
};

// initialize global variable
student *head = NULL;

// Function prototype (declaration)
void printMenu();
void addBegin();
void addEnd();
void deleteBegin();
void deleteEnd();
void deleteAnywhere();
void deleteRecursively(student *prev, student *temp, char searchedName[]);
void deleteTraversaly(student *prev, student *current, char searchedName[]);
void displayAllNode();
void createStudents();
void sortAscending();
void sortDescending();

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
				sortAscending();
				displayAllNode();
				break;
			case 7:
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
		"\n1. Add begin"
		"\n2. Add end"
		"\n3. Delete begin"
		"\n4. Delete end"
		"\n5. Delete anywhere"
		"\n6. Sort ascending"
		"\n7. Sort descending"
		"\n0. End"
		"\n\nChoose a menu: "
	);
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
		addBegin();
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
		printf("%s | %d--->", temp->name, temp->info.score);

		temp = temp->next;
	}
	
	printf("NULL\n\n");
}

void addBegin()
{
	// create new pointer that point to empty node
	student *newNode = (student *) malloc(sizeof(student));

	// then we assign name into empty node
	printf("Insert student name: ");
	scanf("%s", newNode->name);
	
	printf("Insert score: ");
	scanf("%d", &newNode->info.score);

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
	
	// we do a simple check to see if our head is empty
	if(head == NULL){
		addBegin();
		return;
	}

	printf("Insert student name: ");
	scanf("%s", newNode->name);
	
	printf("Insert score: ");
	scanf("%d", &newNode->info.score);
	
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

	student *temp = head;

	// else move head to next node
	head = temp->next;
	
	// deallocate
	free(temp);
}

void deleteEnd()
{
	student *temp = head;

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
	
	student *temp = head->next;
	student *prev = head;
	char name[100];

	// get the name of student that we want to delete
	printf("Insert student that you want to delete: ");
	scanf("%s", &name);
	
	if(strcmp(name, head->name) == 0){
		printf("Student found and deleted! first\n");
		head = head->next;
		return;
	}

	// then we will call this function recursively
	// until it find the name, you can comment out 
	// any method that you want to use.
	deleteTraversaly(prev, temp, name); // method: 1
	// deleteRecursively(prev, temp, name); // method: 2
}

void deleteRecursively(student *prev, student *temp, char searchedName[])
{
	if(temp == NULL){

		printf("Student not found\n");

	}else if(strcmp(searchedName, temp->name) == 0){
		
		printf("Student found and deleted!\n");

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

void deleteTraversaly(student *prev, student *temp, char searchedName[])
{
	if(strcmp(searchedName, prev->name) == 0){
		printf("Student found and deleted!\n");
		deleteBegin();
		return;
	}
	
	// traverse each node and do the check
	while(temp != NULL){
		if(strcmp(searchedName, temp->name) == 0){
			printf("Student found and deleted!\n");
			prev->next = temp->next;
			return;
		}
		
		prev = temp;
		temp = temp->next;
	}
	
	printf("Student not found\n");
}

void sortAscending()
{
    student *i = head,*j =head;

	// i is to loop for n-number of node only
    while(i!=NULL){
    	// j is to loop or each loop and compare it with the next node
        while(j->next!=NULL){
            if(j->info.score > j->next->info.score){
            	// swap the data if prev is larger than next
            	student temp = *j;
            	
                j->info.score = j->next->info.score;
                strcpy(j->name, j->next->name);
                
                j->next->info.score = temp.info.score;
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
    student *i = head,*j =head;
	
    while(i!=NULL){
        while(j->next!=NULL){
            if(j->info.score < j->next->info.score){
            	student temp = *j;
            	
                j->info.score = j->next->info.score;
                strcpy(j->name, j->next->name);
                
                j->next->info.score = temp.info.score;
                strcpy(j->next->name, temp.name);
            }
            j=j->next;
        }
        j=head;
        i=i->next;
    }
}
