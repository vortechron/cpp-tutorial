#include <iostream>
#include <stdio.h>
#include <string.h>
#define SIZE 50

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct task {
	int priority;
	char task[200];
};

task myTask[SIZE];

void displayMenu();
int count();
void displayTask(int index);
void sortDescending();
void swap(int x, int y);
void addTask();
void updateTask();
void deleteTask();
void searchTask();
task generateTask();

int main() {
	
	while (1) {
		displayMenu();
		
		int pilihan;
		
		scanf("%d", &pilihan);
		
		switch (pilihan) {
			case 1:
			{
				addTask();
                break;
			}
			case 2:
			{
                updateTask();
                break;
			}
			case 3:
			{
				deleteTask();
				break;
			}
			case 4:
			{
                searchTask();
				break;
			}
			case 5:
			{
				sortDescending();
				break;
			}
				
		}
	}
	
	return 0;
}

void displayMenu()
{
	printf(
		"\nMy Todo List\n"
		"-------------"
	);
	
	if (count() == 0) {
		printf(
			"\n~ your list is empty ~"
		);
	} else {
		for(int i = 0; i < SIZE; i++) {
			if (myTask[i].priority == 0) {
				break;
			}
			
			printf("\n%d. %s", i + 1, myTask[i].task);
		}
	}
	
	printf(
		"\n\n\n ------------------\n 1. Add task"
		"\n 2. Update task"
		"\n 3. Delete task"
		"\n 4. Search task"
		"\n 5. Sort task"
		"\n\n Your choice: "
	);
	
	
}

int count(){
	int counter = 0;
	for(int i = 0; i < SIZE; i++) {
		if (myTask[i].priority == 0) {
			break;
		}
		
		counter++;
	}
	
	return counter;
}

void displayTask(int index) {
	printf(
		"\nTask: %s"
		"\nPriority: %d",
		myTask[index].task,
		&myTask[index].priority
	);
}

void sortDescending()
{
	int first, second, index;

    for (first = 0; first < SIZE-1; first++)
    {
    	if(myTask[first].priority == 0){
    		break;
		}

        index = first;
        for (second = first+1; second < SIZE; second++){
        	
        	if(myTask[second].priority == 0){
    			break;
			}
			
        	if (myTask[second].priority > myTask[index].priority)
            	index = second;
		}

        swap(index, first);
    }
}

void swap(int x, int y)
{
    task temp = myTask[x];
    myTask[x] = myTask[y];
    myTask[y] = temp;
}

void addTask()
{
    for(int i = 0; i < SIZE; i++) {
        if (myTask[i].priority == 0) {
            myTask[i] = generateTask();
            break;
        }
    }
}

void updateTask()
{
    int index = 0;
    printf("\n What task do you want to edit? (insert task number) : ");
    scanf("%d", &index);
    
    myTask[index - 1] = generateTask();
}

void deleteTask()
{
    int find = 0;
    printf("\n Task numnber that you want to delete : ");
    scanf("%d", &find);
    
    find = find - 1;
    
    bool found = false;
    
    for (int i = 0; i < SIZE; i++) {
        
        if (find == i) {
            myTask[i].priority = 0;
            strcpy(myTask[i].task, "");
                
            found = true;
        }
        
        if (found == true && myTask[i].priority != 0) {
            myTask[i - 1].priority = myTask[i].priority;
            strcpy(myTask[i - 1].task, myTask[i].task);
            
            myTask[i].priority = 0;
            strcpy(myTask[i].task, "");
        }
    }
}

void searchTask()
{
    int find = 0;
    printf("\n Task that you want to find: ");
    scanf("%d", &find);
    
    find = find - 1;
    
    for (int i = 0; i < SIZE; i++) {
        
        if (find == i) {
            displayTask(i);
            break;
        }
    }
}

task generateTask()
{
	task temp;
	char task[200];
    int priority;
    
    cin.clear();
    cin.sync();
    
    printf("\n What is your task? (e.g. wash cloth) : ");
    cin.getline(task, sizeof(task));
    
    printf("\n What is this task priority? (e.g. 7) : ");
    scanf("%d", &priority);
    
    temp.priority = priority;
    strcpy(temp.task, task);
    
    return temp;
}
