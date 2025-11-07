//Student Record Management using Linked List

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for Student Record
struct Node{
	char name[20];
	char StudentID[20];
	int age;
	int year;
	char course[20];
	char PhoneNumber[15];
	struct Node* next;
};

struct Node* head=NULL;

//Inserting student record at the beginning
//Student ID should be unique
//if the student ID already exists, it will not insert
//and it give a message to give a valid student ID
void insert()
{
	struct Node* newNode= malloc(sizeof(struct Node));
	printf("Enter Name(use '_' instead of ' '): ");
	scanf("%s", newNode->name);
	while(1){
		printf("Enter a valid Student ID: ");
		scanf("%s", newNode->StudentID);
		struct Node* temp=head;
		int exists=0;
		while(temp){
			if(strcmp(temp->StudentID, newNode->StudentID)==0){
				printf("Student ID already exists. Please enter a valid Student ID.\n");
				exists=1;
				break;
			}
			temp=temp->next;
		}
		if(!exists)
			break;
	}
	printf("Enter Age: ");
	scanf("%d", &newNode->age);
	printf("Enter Year: ");
	scanf("%d", &newNode->year);
	printf("Enter Course(use '_' instead of ' '): ");
	scanf("%s", newNode->course);
	printf("Enter Phone Number: ");
	scanf("%s", newNode->PhoneNumber);

	newNode -> next = head;
	head = newNode;
	printf("Record inserted successfully\n\n");
}

//Deleting student record by Student ID
//If the Student ID does not exist, it will give a message
void delete(char* id){
	struct Node *temp=head, *prev=NULL;
	while(temp){
		if(strcmp(temp->StudentID, id)==0){
			if(prev)
				prev->next=temp->next;
			else
				head=temp->next;
			free(temp);
			printf("Record with Student ID %s deleted\n", id);
			return;
		}
		prev=temp;
		temp=temp->next;
	}
	printf("Record with Student ID %s not found\n", id);

}

//Displaying all student records
void display(){
	struct Node* temp=head;
	if(!temp){
		printf("No records to display\n");
		return;
	}
	printf("All Student Records:\n");
	while(temp){
		printf("\nName: %s, \nStudent ID: %s, \nAge: %d, \nYear: %d, \nCourse: %s, \nPhone Number: %s\n\n", temp->name, temp->StudentID, temp->age, temp->year, temp->course, temp->PhoneNumber);
		temp=temp->next;
	}
}

//Searching student record by Student ID
//If the Student ID does not exist, it will give a message
void search(char* id){
	struct Node* temp=head;
	while(temp){
		if(strcmp(temp->StudentID, id)==0){
			printf("Record Found: \nName: %s, \nStudent ID: %s, \nAge: %d, \nYear: %d, \nCourse: %s, \nPhone Number: %s\n\n", temp->name, temp->StudentID, temp->age, temp->year, temp->course, temp->PhoneNumber);
			return;
		}
		temp=temp->next;
	}
	printf("Record with Student ID %s not found\n", id);
}

//Function to update student record by Student ID
//If the Student ID does not exist, it will give a message
//it will ask which field to update
//and update that field
void update(char* id){
	struct Node* temp=head;
	int flag=0;
	while(temp){
		if(strcmp(temp->StudentID, id)==0){
			flag=1;
			printf("What do you want to update?\n1. Name\n2. Age\n3. Year\n4. Course\n5. Phone Number\n");
			int choice;
			printf("Enter your choice: ");
			scanf("%d", &choice);
			switch(choice){
				case 1:
					printf("Enter new Name(use '_' instead of ' '): ");
					scanf("%s", temp->name);
					printf("Name updated successfully\n");
					break;
				case 2:
					printf("Enter new Age: ");
					scanf("%d", &temp->age);
					printf("Age updated successfully\n");
					break;
				case 3:
					printf("Enter new Year: ");
					scanf("%d", &temp->year);
					printf("Year updated successfully\n");
					break;
				case 4:
					printf("Enter new Course(use '_' instead of ' '): ");
					scanf("%s", temp->course);
					printf("Course updated successfully\n");
					break;
				case 5:
					printf("Enter new Phone Number: ");
					scanf("%s", temp->PhoneNumber);
					printf("Phone Number updated successfully\n");
					break;
				default:
					printf("Invalid choice\n");
					return;
			}
		}
		
		temp=temp->next;
	}
	if(flag)
		return ;
	printf("Record with Student ID %s not found\n", id);
}

//Function to count total number of student in the record
int count(){
	struct Node* temp=head;
	int cnt=0;
	while(temp){
		cnt++;
		temp=temp->next;
	}
	return cnt;
}

//Main function with menu
int main(){
	printf("Studnet Record Management\n");
	printf("1. Insert\n2. Delete\n3. Display\n4. search\n5. Update\n6. Count\n7. Exit\n");
	int choice;
	while(1){
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				insert();
				break;
			case 2:
				{
					char id[10];
					printf("Enter Student ID to delete: ");
					scanf("%s", id);
					delete(id);
				}
				break;
			case 3:
				display();
				break;
			case 4:
				{
					char id[20];
					printf("Enter Student ID to search: ");
					scanf("%s", id);
					search(id);
				}
				break;
			case 5:
				{
					char id[20];
					printf("Enter Student ID to update: ");
					scanf("%s", id);
					update(id);
				}
				break;
			case 6:
				printf("Total number of students: %d\n", count());
				break;
			case 7:
				exit(0);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
