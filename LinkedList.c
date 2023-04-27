//Lab 6
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	//Payload
	int number;

	//Reference to the next node
	struct node* NEXT;
}nodeT;

void main()
{
	nodeT* headPtr = NULL;
	int choice, i, findE;
	nodeT* temp;
	nodeT* newLastNode;

	printf("\n    ===== LINKED LIST MENU =====\n");
	printf(" 1. Add a node at the start of the list.\n");
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
			printf(" -> Adding a node to start...\n");
			//Creating and populating the node
			temp = (nodeT*)malloc(sizeof(nodeT) * 1);
			printf(" -> Please enter the node number: ");
			scanf("%d", &temp->number);
			//Connecting the node to the list
			temp->NEXT = headPtr;
			headPtr = temp;
		}

		else if (choice == 2)
		{
			if (headPtr == NULL)
			{
				printf(" -> [ERROR] No elements to display!\n");
			}

			temp = headPtr;
			i = 0;

			while (temp != NULL)
			{
				printf(" -> Value %d is %d.\n", i, temp->number);
				i++;
				temp = temp->NEXT;
			}
		}

		else if (choice == 3)
		{
			//Delete a node from the end of the list
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
					newLastNode = temp;
					temp = temp->NEXT;
				}
				//Delete it and slot in the previous last node.
				free(temp);
				newLastNode->NEXT = NULL;
			}
		}

		else if (choice == 4)
		{
			//Display length of list
			temp = headPtr;
			i = 0;

			while (temp != NULL)
			{
				i++;
				temp = temp->NEXT;
			}
			printf(" -> The length of the list is %d.\n", i);
		}

		else if (choice == 5)
		{
			//Search by value
			temp = headPtr;
			i = 0;

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