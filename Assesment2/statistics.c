#include "statistics.h"
#include "list.h"


const char STATISTICSTEXT[8][50] = { {"of players who miss no tackles"},
                                     {"of players who miss less than 3 tackles per match"},
									 {"of players who miss less than 5 tackles per match"},
									 {"of players who miss more than 5 tackles per match"},
									 {"of players who make no metres in a game"},
									 {"of players who make less than 10 meters in a game"},
									 {"of players who make less than 20 meters in a game"},
									 {"of players who make more than 20 meters in a game"}};

//Function used to display players in order of height
void listPlayerInOrderOfHight(struct node *head) {
	int mode= -1;
	struct node* sortedList;
	char c;
	//Check if the list is empty
	if (head == 0x00000000) {
		printf("\nThe list is empty");
		return;
	}

	//Ask for the category
	do {
		printf("\n");
		printf("\nCategories:");
		printf("\n\t1. Second Row");
		printf("\n\t2. Back Row\n");
		if (scanf("%d", &mode) == 0) {
			scanf("%c", &c);
			mode = -1;
		}
		if (mode != 1 && mode != 2) mode = -1;
	} while (mode == -1);


	//Sort, filter
	sortedList=sortPlayers(head, mode);
	
	//Check if the new list is empty
	if (sortedList != 0x00000000) {
		//Display
		displayList(sortedList);
	} else {
		printf("\n No one is in this position");
	}
	
	//Free memory
	free(sortedList);
}

//Function used to sort the players  by height
struct node* sortPlayers(struct node *head, int mode) {
	struct node* newHead= 0x00000000;
	struct node* current;
	struct node* tmp;

	current=head;
	//Loop the list
	while (current != 0x00000000){
		//Get the next one
		tmp = current->next;
		//Add only if the position is Second Row or Back Row
		if ((mode == 1 && current->position == 2) || (mode == 2 && current->position == 3)) {
			//Add to the new list
			addSortedNode(&newHead, duplicateNode(current), 2);
		}
		//Set the next to the current
		current = tmp;
	}

	//Return the new list
	return newHead;
}

//Function used to duplicate a node
struct node* duplicateNode(struct node* from) {
	//Allocate for the new one
	struct node* to = (struct node*)malloc(sizeof(struct node));
	//Copy details
	to->IRFU = from->IRFU;
	to->age = from->age;
	to->height = from->height;
	to->weight = from->weight;
	to->position = from->position;
	to->tacklesmissed = from->tacklesmissed;
	to->metersmake = from->metersmake;
	strcpy(to->firstname, from->firstname);
	strcpy(to->secondname, from->secondname);
	strcpy(to->club, from->club);
	strcpy(to->email, from->email);
	to->next = 0x00000000;
	//Return the new one
	return to;
}

//Function used to generate statistics
void generateSatistics(struct node *head, int stats[8]) {
	int mode = -1;
	struct node* tmp;
	int i,pos=-1;
	char c;
	//Check if the list is empty
	if (head == 0x00000000) {
		printf("\nThe list is empty");
		return;
	}

	//Ask for the category
	do {
		printf("\n");
		printf("\nCategories for statistics:");
		printf("\n\t1. Player Position");
		printf("\n\t2. Weight\n");
		if (scanf("%d", &mode) == 0) {
			scanf("%c", &c);
			mode = -1;
		}
		if (mode != 1 && mode != 2) mode = -1;
	} while (mode == -1);

	//If it is the player position mode
	if (mode == 1) {
		do {
			printf("\nPlease choose the player position:");

			for (i = 0; i < 7; i++) printf("\n\t%d. %s", i + 1, POSITIONS[i]);
			printf("\n");
			if (scanf("%d", &pos) == 0) {
				scanf("%c", &c);
				pos = -1;
			}
			//If the position is invalid then reset
			if (pos < 1 && pos > 7) pos = -1;
		} while (pos == -1);
	}

	//If it is the weight mode
	if (mode == 2) {
		do {
			printf("\nPlease enter the player weight to show from:");

			printf("\n");
			if (scanf("%d", &pos) == 0) {
				scanf("%c", &c);
				pos = -1;
			}

			//If the position is invalid then reset
			if (pos < 1) pos = -1;
		} while (pos == -1);
	}

	//Loop the list
	tmp = head;
	while (tmp != 0x00000000) {
		//Filter to position or weight. Depends on mode
		if ((mode == 1 && tmp->position == pos-1) || (mode==2 && tmp->weight>=pos)) {
			//No missed takles
			if (tmp->tacklesmissed == 0) stats[0]++;
			//Missed less than three
			if (tmp->tacklesmissed == 1) stats[1]++;
			//Missed less than five
			if (tmp->tacklesmissed == 2) stats[2]++;
			//Missed more than 5
			if (tmp->tacklesmissed == 3) stats[3]++;

			//No meters in game
			if (tmp->metersmake == 0) stats[4]++;
			//Less than 10 meter
			if (tmp->metersmake == 1) stats[5]++;
			//Less than 20 meter
			if (tmp->metersmake == 2) stats[6]++;
			//More than 20 meter
			if (tmp->metersmake == 3) stats[7]++;
		}
		//Go next
		tmp = tmp->next;
	}
}

//Function used to display statistics
void displayStatistics(int stat[8]) {
	int i = 0;
	printf("\n");
	for (i = 0; i < 8; i++) {
		printf("\n%d %s", stat[i], STATISTICSTEXT[i]);
	}
}