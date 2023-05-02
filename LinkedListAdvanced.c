//Lab 7
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	//Payload
	int number;

	//Reference to the next node
	struct node* NEXT;
}nodeT;

void addStart(nodeT** topPtr);
void addEnd(nodeT* top);
void deleteStart(nodeT** topPtr);
void deleteEnd(nodeT* top);
void search(nodeT* top);
void displayList(nodeT* top);
int displayLength(nodeT* top);

void main()
{
	nodeT* headPtr = NULL;
	int choice, i, findE;
	nodeT* temp;
	nodeT* temp2;

	printf("\n    ===== LINKED LIST MENU =====\n");
	printf(" 1. Add a node to the list.\n");
	printf(" 2. Display the list.\n");
	printf(" 3. Delete a node from the list.\n");
	printf(" 4. Display the length of the list.\n");
	printf(" 5. Search the list for a value.\n");
	printf("-1. Exit\n");
	printf(" -> Enter selection: ");
	scanf("%d", &choice);

	while (choice != -1)
	{
		if (choice == 1)
		{
			printf("\n -> Add to start (1) or End (2)?: ");
			scanf("%d", &choice);

			if (choice == 1)
				addStart(&headPtr);
			else if (choice == 2)
				addEnd(headPtr);
			else
				printf("\n -> Invalid selection!");
		}

		else if (choice == 2)
		{
			displayList(headPtr);
		}

		else if (choice == 3)
		{
			printf("\n -> Delete from start (1) or End (2)?: ");
			scanf("%d", &choice);

			if (choice == 1)
				deleteStart(&headPtr);
			else if (choice == 2)
				deleteEnd(headPtr);
			else
				printf("\n -> Invalid selection!");
		}

		else if (choice == 4)
		{
			printf(" -> The length of the list is %d.\n", displayLength(headPtr));
		}

		else if (choice == 5)
		{
			search(headPtr);
		}

		printf("\n    ===== LINKED LIST MENU =====\n");
		printf(" 1. Add a node at the start of the list.\n");
		printf(" 2. Display the list.\n");
		printf(" 3. Delete a node from the list.\n");
		printf(" 4. Display the length of the list.\n");
		printf(" 5. Search the list for a value.\n");
		printf("-1. Exit\n");
		printf(" -> Enter selection: ");
		scanf("%d", &choice);
	}

}

void addStart(nodeT** topPtr) {
	nodeT* newNode;

	printf(" -> Adding a node to start...\n");
	//Creating and populating the node
	newNode = (nodeT*)malloc(sizeof(nodeT) * 1);
	printf(" -> Please enter the node number: ");
	scanf("%d", &newNode->number);
	//Connecting the node to the list
	newNode->NEXT = *topPtr;
	*topPtr = newNode;
}

void addEnd(nodeT* top) {
	nodeT* temp = top;
	nodeT* newNode;

	newNode = (nodeT*)malloc(sizeof(nodeT));
	printf(" -> Please enter the node number: ");
	scanf("%d", &newNode->number);

	while (temp->NEXT != NULL) {
		temp = temp->NEXT;
	}

	temp->NEXT = newNode;
	newNode->NEXT = NULL;
}

void deleteStart(nodeT** topPtr) {
	nodeT* temp;
	temp = *topPtr;
	
	if (*topPtr == NULL)
	{
		printf(" -> [ERROR] No elements to delete!\n");
	}
	else
	{
		*topPtr = temp->NEXT;
		free(temp);
	}
}

void deleteEnd(nodeT* top) {
	//Delete a node from the end of the list
	nodeT* headPtr = top;
	nodeT* temp;
	nodeT* temp2;

	temp = headPtr;

	if (headPtr == NULL)
	{
		printf(" -> [ERROR] No elements to delete!\n");
	}
	else
	{
		//Find last node
		while (temp->NEXT != NULL)
		{
			temp2 = temp;
			temp = temp->NEXT;
		}
		//Delete it and slot in the previous last node.
		free(temp);
		temp2->NEXT = NULL;
	}
}

void search(nodeT* top) {
	//Search by value
	nodeT* headPtr = top;
	nodeT* temp = headPtr;
	int i = 0, findE;

	printf(" -> Please enter the number you'd like to search for: ");
	scanf("%d", &findE);

	while (temp != NULL)
	{
		if (findE == temp->number)
		{
			i++;
			printf(" -> Element %d found pointing to address %p.\n", temp->number, temp->NEXT);
		}
		temp = temp->NEXT;
	}

	if (i < 1)
	{
		printf(" -> No elements matching %d found!\n", findE);
	}
	else
	{
		printf(" -> %d instances of %d found!\n", i, findE);
	}
}

void displayList(nodeT* top) {
	nodeT* headPtr = top;
	nodeT* temp;
	int i = 0;

	if (headPtr == NULL)
	{
		printf(" -> [ERROR] No elements to display!\n");
	}

	temp = headPtr;

	while (temp != NULL)
	{
		printf(" -> Value %d is %d.\n", i, temp->number);
		i++;
		temp = temp->NEXT;
	}
}

int displayLength(nodeT* top) {
	//Display length of list
	int i = 0;
	nodeT* temp = top;

	while (temp != NULL)
	{
		i++;
		temp = temp->NEXT;
	}
	return i;
}
