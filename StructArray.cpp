#include <iostream> // to use cin or cout
#include <stdlib.h> // general library
#include <string.h> // to use string related function

#define SIZE 100

struct student
{
	char name[100];
	char matrixNo[100];
	int unix = 0;
	
	struct marks{
		int test;
		int final;
	}mark;
};

// initialize global variable
student lists[SIZE];

// Function prototype (declaration)
void printMenu();
void add(int index);
void displayAllNode();
void createStudents();
void sortMatrixDescending();
void sortFinalDescending();
void swap(int intx, int inty);

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
				sortMatrixDescending();
				displayAllNode();
				break;
			case 2:
				sortFinalDescending();
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
		"\n1. Matrix No."
		"\n2. Final"
		"\n0. End"
		"\n\nChoose a menu: "
	);
}

void createStudents()
{
	int choice;
	int index = 0;
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
		add(index);
		
		index++;
	}
}

void displayAllNode()
{
	printf("\n\nMy lists\n");
	
	int i;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < SIZE-1; i++)
    {
    	
    	if(lists[i].unix == 0){
    		break;
		}
    	
        printf(
			"\n-------------------\n"
			"> Name: %s \n"
			"> Matrix No.: %s\n"
			"> Mark:\n"
			"\tTest :- %d\n"
			"\tFinal :- %d\n"
			"-------------------\n"
			"\t| |\n"
			"\t| |\n"
			"\t| |\n"
			"\t| |",
			lists[i].name, lists[i].matrixNo, lists[i].mark.test, lists[i].mark.final
		);
    }
	
	printf(
		"\n-------------------\n"
		"NULL\n"
		"-------------------\n\n"
	);
}

void add(int index)
{
	// create new pointer that point to empty node
	student newNode;
	
	// then we assign name into empty node
	printf("Insert student name: ");
	scanf("%s", newNode.name);
	
	printf("Insert student matrix: ");
	scanf("%s", newNode.matrixNo);
	
	printf("Insert student test: ");
	scanf("%d", &newNode.mark.test);
	
	printf("Insert student final mark: ");
	scanf("%d", &newNode.mark.final);
	
	newNode.unix = 1;

	// this will put new node at the front
	lists[index] = newNode;
}

void sortMatrixDescending()
{
	int first, second, index;
 
    // One by one move boundary of unsorted subarray
    for (first = 0; first < SIZE-1; first++)
    {
    	
    	if(lists[first].unix == 0){
    		break;
		}
		
        // Find the minimum element in unsorted array
        index = first;
        for (second = first+1; second < SIZE; second++){
        	
        	if(lists[second].unix == 0){
    			break;
			}
			
        	if (lists[second].matrixNo[0] > lists[index].matrixNo[0])
            	index = second;
		}
        // Swap the found minimum element with the first element
        swap(index, first);
    }
}

void sortFinalDescending()
{
int first, second, index;
 
    // One by one move boundary of unsorted subarray
    for (first = 0; first < SIZE-1; first++)
    {
    	if(lists[first].unix == 0){
    		break;
		}
		
        // Find the minimum element in unsorted array
        index = first;
        for (second = first+1; second < SIZE; second++){
        	
        	if(lists[second].unix == 0){
    			break;
			}
			
        	if (lists[second].mark.final > lists[index].mark.final)
            	index = second;
            	
		}
          
        // Swap the found minimum element with the first element
        swap(index, first);
    }
}

void swap(int x, int y)
{
    student temp = lists[x];
    lists[x] = lists[y];
    lists[y] = temp;
}
