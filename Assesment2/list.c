#include "list.h"
#include <stdio.h>
//Player positions
const char POSITIONS[7][18] = { { "Prop" },{ "Hooker" },{ "Second Row" },{ "Back Row" },{ "Half Back" },{ "Centres" },{ "Wingers/Full Back" } };
//Takles made
const char TAKLESMISSED[4][32] = { { "Never" },{ "Less than three times per match" },{ "Less than five times per match" },{ "More than five times per match" } };
//Metres made
const char METRESMADE[4][25] = { { "None" },{ "Less than 10 metres" },{ "Less than 20 metres" },{ "More than 20 metres" } };

//Function used to get the details of a node
void getNodeDetails(struct node* head, struct node* node, int showold) {

	int irfu;
	float f=0;
	char tmpTxt[100];
	char c;
	int i;

	struct node* tmp;
	tmp = head;

	//Get the player's details for the node

	while (1==1) {

		if (showold == 1) printf("\nPlayer's old IRFU: %d",node->IRFU);

		//it will loop until we get a walid int
		irfu = -1;
		do {
			printf("\nPlease enter the IRFU:");
			if (scanf("%d", &irfu) == 0) {
				scanf("%c", &c);
				irfu = -1;
			}
			
		} while (irfu == -1);

		//Convert irfu tu text
		sprintf(tmpTxt, "%d",irfu);
		//If it was not in the list yet or it is the same as the old one
		if (getItem(head, tmpTxt,0) == 0x00000000 || (showold==1 && node->IRFU==irfu)) {
			//Set the IRFU
			node->IRFU=irfu;
			//Break the loop
			break;
		}else{
			printf("\n This id already exists.");
		}
	}


	if (showold == 1) printf("\nPlayer's old first name: %s", node->firstname);
	printf("\nPlease enter the first name:");
	scanf("%s", &node->firstname);
	//strcpy(node->firstname, tmpTxt);

	if (showold == 1) printf("\nPlayer's old second name: %s", node->secondname);
	printf("\nPlease enter the second name:");
	scanf("%s", &tmpTxt);
	strcpy(node->secondname, tmpTxt);

	//get valid age
	i = 0;
	do {
		if (showold == 1) printf("\nPlayer's old age: %d", node->age);
		printf("\nPlease enter the age:");
		if (scanf("%d", &irfu) == 0) {
			scanf("%c", &c);
			i = 0;
		}else if (irfu < 1) {
			i = 0;
		}else {
			node->age = irfu;
			i = 1;
		}
	} while (i == 0);

	//get valid height
	i = 0;
	do {
		if (showold == 1) printf("\nPlayer's old height: %.2f", node->height);
		printf("\nPlease enter the height:");
		if (scanf("%f", &f) == 0) {
			scanf("%c", &c);
			i = 0;
		}else if (f<1) {
			i = 0;
		}else {
			node->height = f;
			i = 1;
		}
	} while (i == 0);

	//get valid weight
	i = 0;
	do {
		if (showold == 1) printf("\nPlayer's old weight: %.2f", node->weight);
		printf("\nPlease enter the weight:");
		if (scanf("%f", &f) == 0) {
			scanf("%c", &c);
			i = 0;
		}else if (f<1) {
			i = 0;
		}else {
			node->weight = f;
			i = 1;
		}
	} while (i == 0);


	if (showold == 1) printf("\nPlayer's old club: %s", node->club);
	printf("\nPlease enter the club:");
	scanf("%s", &tmpTxt);
	strcpy(node->club, tmpTxt);

	///Get e-mail address
	//Set validator to false
	irfu = 0;
	if (showold == 1) printf("\nPlayer's old email: %s", node->email);

	do {
		printf("\nPlease enter the email:");
		scanf("%s", &tmpTxt);
		//Check if valid e-mail
		if (strstr(tmpTxt, "@") != 0x00000000 && strstr(tmpTxt, ".com") != 0x00000000) {
			//Set e-mail
			strcpy(node->email, tmpTxt);
			//Trip flag
			irfu = 1;
		} else {
			printf("\n The e-mail must contain an @, a full stop and a .com");
		}
	} while (irfu != 1);

	///Get player position
	//Set validator to false
	irfu = -1;
	if (showold == 1) printf("\nPlayer's old position: %s", POSITIONS[node->position]);

	do {
		printf("\nPlease choose the player position:");
		
		for (i = 0; i < 7; i++) printf("\n\t%d. %s",i+1,POSITIONS[i]);
		
		printf("\n");
		if (scanf("%d", &irfu) == 0) {
			scanf("%c", &c);
			irfu = -1;
		}

		//If valid position then set position
		if (irfu > 0 && irfu < 8) {
			node->position = irfu-1;
		} else {
			irfu = -1;
		}

		
	} while (irfu == -1);

	///Get missed takles
	//Set validator to false
	irfu = -1;
	if (showold == 1) printf("\nPlayer's old takles missed per match: %s", TAKLESMISSED[node->tacklesmissed]);
	do {
		printf("\nPlease choose the missed takles per match:");

		for (i = 0; i < 5; i++) printf("\n\t%d. %s", i + 1, TAKLESMISSED[i]);
		
		printf("\n");
		if (scanf("%d", &irfu) == 0) {
			scanf("%c", &c);
			irfu = -1;
		}

		//If valid position then set position
		if (irfu > 0 && irfu < 5) {
			node->tacklesmissed = irfu-1;
		}else {
			irfu = -1;
		}


	} while (irfu == -1);


	///Get missed takles
	//Set validator to false
	irfu = -1;
	if (showold == 1) printf("\nPlayer's old metres made: %s", METRESMADE[node->metersmake]);
	do {
		printf("\nPlease choose the meters made:");

		for (i = 0; i < 4; i++) printf("\n\t%d. %s", i + 1, METRESMADE[i]);
		
		printf("\n");
		if (scanf("%d", &irfu)==0) {
			scanf("%c",&c);
			irfu = -1;
		}

		//If valid position then set position
		if (irfu > 0 && irfu < 5) {
			node->metersmake = irfu-1;
		} else {
			irfu = -1;
		}


	} while (irfu == -1);

	if (showold != 1)	node->next = 0x00000000;
}

//Function used to display the details of a player
void displayDetails(struct node* node) {
	//Exit if it is not filled
	if (node == 0x00000000) return;
	printf("\n\tIRFU: %d", node->IRFU);
	printf("\n\tFirst Name: %s", node->firstname);
	printf("\n\tSecond Name: %s", node->secondname);
	printf("\n\tAge: %d", node->age);
	printf("\n\tHeight: %.2f", node->height);
	printf("\n\tWeight: %.2f", node->weight);
	printf("\n\tClub: %s", node->club);
	printf("\n\tEmail: %s", node->email);
	printf("\n\tPosition: %s", POSITIONS[node->position]);
	printf("\n\tTackles missed per match: %s", TAKLESMISSED[node->tacklesmissed]);
	printf("\n\tMetres made per game: %s", METRESMADE[node->metersmake]);
}

//Function used to display the players
void displayList(struct node* head) {
	//Index
	int i = 0;
	//Node holder
	struct node* tmp;

	if (head == 0x00000000) {
		printf("\nThere are no players\n");
		return;
	}

	//Add the head
	tmp = head;
	//Loop until there is an item
	while (tmp != 0x00000000) {
		//Print the item
		printf("\nPlayer at position %d", ++i);

		displayDetails(tmp);

		//Go to the next
		tmp = tmp->next;
	}

}

//Mode 1 if by IRFU, Mode 1 if by height
void addSortedNode(struct node** head, struct node* newNode, short mode) {
	struct node* prev_temp = 0x00000000;
	struct node* tmp;
	int i = 0;


	if (mode == 1) {
		//Gte node details
		getNodeDetails(*head, newNode, 0);
	}

	//If the head is null
	if ((*head) == 0x00000000) {
		//Replace the head
		*head = newNode;
		return;
	}
	
	//if it is the head
	if ((mode==1 && (*head)->IRFU > newNode->IRFU) || (mode == 2 && (*head)->height > newNode->height)) {
		//Add the head to the new node
		newNode->next = *head;
		//Replace the head
		*head = newNode;
		return;
	}


	//If it is after the head
	tmp = *head;
	while (tmp != 0x00000000) {
		//If the current smaller than the new
		if ((mode == 1 && tmp->IRFU < newNode->IRFU) || (mode == 2 && tmp->height < newNode->height)) {
			prev_temp = tmp;
			tmp = tmp->next;
		} else {
			break;
		}
	}

	//If it should be the last one 
	if (prev_temp->next == 0x00000000 && ((mode == 1 && prev_temp->IRFU < newNode->IRFU) || (mode == 2 && prev_temp->height < newNode->height))) {
		//Add to the end
		prev_temp->next = newNode;
		return;
	}
	
	//insert the new one between
	prev_temp->next = newNode;
	newNode->next = tmp;

}

//Get The length of the function
int getLenght(struct node* head) {
	int length = 0;
	struct node* tmp;

	//Return 0 if the list is empty
	if (head == 0x00000000) return 0;

	//Initialize first node
	tmp = head;
	//Find the last
	while (tmp != 0x00000000) {
		length++;
		tmp = tmp->next;
	}

	//return the length
	return length;
}

//Get the index of an item
struct node* getItem(struct node* head, char txt[25], int irfuonly) {
	struct node* tmp;
	char tmpTxt[25];
	//Return 0 if the list is empty
	if (head == 0x00000000) return 0x00000000;

	//Initialize first node
	tmp = head;
	//Find the last
	while (tmp != 0x00000000) {
		//If the number is found then return the index
		sprintf(tmpTxt, "%d", tmp->IRFU);
		//Return true if ifu matches
		if (strcmp(tmpTxt, txt) == 0) return tmp;
		//Retrurn true if name match is allowed adn matches
		if (irfuonly != 1 && strcmp(tmp->firstname, txt) == 0) return tmp;
		tmp = tmp->next;
	}

	//return 0x00000000 if not exists
	return 0x00000000;
}

//Function used to remove an item at a position
short removeItemAtPosition(struct node** head, int position) {
	//The node's position and the iteartor index
	int i = 0;
	//Holders for the nodes
	struct node* prev = 0x00000000;
	struct node* curr = 0x00000000;

	//Set the head to the first in the loop
	curr = *head;
	//Loop to the end
	while (curr != 0x00000000 && i<position) {
		//Set the current to be the previous one
		prev = curr;
		//Go to the next one
		curr = curr->next;
		i++;
	}

	if (position == 0) {
		//If there is a next one
		if (curr != 0x00000000) {
			//Set the next one as head
			*head = curr->next;
		} else {
			*head = 0x00000000;
		}
	} else {
		//If it is not the head node
		//If there is next one
		if (curr->next != 0x00000000) {
			//Set the next one to the previous
			prev->next = curr->next;
		} else {
			//If it is the last one
			prev->next = 0x00000000;
		}
	}
	//Free the memory
	free(curr);
	//Return true
	return 1;
}

//Remove an item from the list
void removeItem(struct node** head) {
	//The node's position
	int position=-1, index = 0;
	//player id
	int id=0;
	char c;
	//Initialize first node
	struct node* tmp = *head;

	//Get the number
	printf("\nPlease enter the IRFU of the player to delete:");
	//Validate to only int
	if (scanf("%d", &id) == 0) {
		scanf("%c", &c);
		position = -1;
	}
	//Find the last
	while (tmp != 0x00000000) {
		//Return true if ifu matches
		if (tmp->IRFU == id) {
			position = index;
			break;
		}
		index++;
		tmp = tmp->next;
	}
	//Return false if the item is not found
	if (position == -1) {
		printf("\n Player not found");
		return;
	}
	//Remove item at the position
	removeItemAtPosition(head, position);
	printf("\n The player is removed");
}