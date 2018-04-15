#include <iostream> // to use cin or cout
#include <stdlib.h> // general library
#include <string.h> // to use string related function

struct student
{
	int matrixNo;
	char name[100];
	
	struct marks{
		int test;
		int quiz;
		int final;
	}mark;
	
	struct student *next;
};

// initialize global variable
student *head = NULL;

// Function prototype (declaration)
void printMenu();
void addBegin();
void displayAllNode();
void createStudents();
void sortNameAscending();
void sortTestAscending();
void sortQuizAscending();
void sortFinalAscending();

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
				sortNameAscending();
				displayAllNode();
				break;
			case 2:
				sortTestAscending();
				displayAllNode();
				break;
			case 3:
				sortQuizAscending();
				displayAllNode();
				break;
			case 4:
				sortFinalAscending();
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
		"\nSort by:\n"
		"\n1. Name"
		"\n2. Test Mark"
		"\n3. Quiz Mark"
		"\n4. Final Mark"
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
		printf(
			"\n-------------------\n"
			"> Name: %s \n"
			"> Matrix No.: %d\n"
			"> Mark:\n"
			"\tQuiz :- %d\n"
			"\tTest :- %d\n"
			"\tFinal :- %d\n"
			"-------------------\n"
			"\t| |\n"
			"\t| |\n"
			"\t| |\n"
			"\t| |",
			temp->name, temp->matrixNo, temp->mark.quiz, temp->mark.test, temp->mark.final
		);

		temp = temp->next;
	}
	
	printf(
		"\n-------------------\n"
		"NULL\n"
		"-------------------\n\n"
	);
}

void addBegin()
{
	// create new pointer that point to empty node
	student *newNode = (student *) malloc(sizeof(student));

	// then we assign name into empty node
	printf("Insert student name: ");
	scanf("%s", newNode->name);
	
	printf("Insert student matrix: ");
	scanf("%d", &newNode->matrixNo);
	
	printf("Insert student quiz mark: ");
	scanf("%d", &newNode->mark.quiz);
	
	printf("Insert student test mark: ");
	scanf("%d", &newNode->mark.test);
	
	printf("Insert student final mark: ");
	scanf("%d", &newNode->mark.final);

	// this will put new node at the front
	newNode->next = head;

	// we need to re-point head back into the 
	// first node. this is important or else our head will 
	// disorder
	head = newNode;
}

void sortNameAscending()
{
    student *i = head,*j =head;

	// i is to loop for n-number of node only
    while(i!=NULL){
    	// j is to loop or each loop and compare it with the next node
        while(j->next!=NULL){
            if(j->name[0] > j->next->name[0]){
            	// swap the data if prev is larger than next
            	student temp = *j;
            	
                j->mark = j->next->mark;
                j->matrixNo = j->next->matrixNo;
                strcpy(j->name, j->next->name);
                
                j->next->mark = temp.mark;
                j->next->matrixNo = temp.matrixNo;
                strcpy(j->next->name, temp.name);
            }
            j=j->next;
        }
        j=head;
        i=i->next;
    }
}

void sortTestAscending()
{
    student *i = head,*j =head;

	// i is to loop for n-number of node only
    while(i!=NULL){
    	// j is to loop or each loop and compare it with the next node
        while(j->next!=NULL){
            if(j->mark.test > j->next->mark.test){
            	// swap the data if prev is larger than next
            	student temp = *j;
            	
                j->mark = j->next->mark;
                j->matrixNo = j->next->matrixNo;
                strcpy(j->name, j->next->name);
                
                j->next->mark = temp.mark;
                j->next->matrixNo = temp.matrixNo;
                strcpy(j->next->name, temp.name);
            }
            j=j->next;
        }
        j=head;
        i=i->next;
    }
}

void sortQuizAscending()
{
    student *i = head,*j =head;

	// i is to loop for n-number of node only
    while(i!=NULL){
    	// j is to loop or each loop and compare it with the next node
        while(j->next!=NULL){
            if(j->mark.quiz > j->next->mark.quiz){
            	// swap the data if prev is larger than next
            	student temp = *j;
            	
                j->mark = j->next->mark;
                j->matrixNo = j->next->matrixNo;
                strcpy(j->name, j->next->name);
                
                j->next->mark = temp.mark;
                j->next->matrixNo = temp.matrixNo;
                strcpy(j->next->name, temp.name);
            }
            j=j->next;
        }
        j=head;
        i=i->next;
    }
}

void sortFinalAscending()
{
    student *i = head,*j =head;

	// i is to loop for n-number of node only
    while(i!=NULL){
    	// j is to loop or each loop and compare it with the next node
        while(j->next!=NULL){
            if(j->mark.final > j->next->mark.final){
            	// swap the data if prev is larger than next
            	student temp = *j;
            	
                j->mark = j->next->mark;
                j->matrixNo = j->next->matrixNo;
                strcpy(j->name, j->next->name);
                
                j->next->mark = temp.mark;
                j->next->matrixNo = temp.matrixNo;
                strcpy(j->next->name, temp.name);
            }
            j=j->next;
        }
        j=head;
        i=i->next;
    }
}
