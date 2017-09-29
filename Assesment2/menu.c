#include "menu.h"
#include "list.h"
#include "statistics.h"
#include <stdio.h>

//Function used to show the menu
void showMenu(struct node** head) {
	drawMain(head);
}


void drawLogin() {

}
//Function used to draw the main menu
void drawMain(struct node** head) {
	//The menu item
	int menu = 0;
	char c;
	//Keep alive the menu until the user needs
	do{
		printf("\n");
		printf("\n-1. Exit");
		printf("\n1. Add player");
		printf("\n2. Display all players to screen");
		printf("\n3. Display Player Details");
		printf("\n4. Update Player's statistics");
		printf("\n5. Delete Player");
		printf("\n6. Generate statistics");
		printf("\n7. Print all Players into a report file");
		printf("\n8. List all the players in Second Row or Back Row\n");

		//Validate to only int
		if (scanf("%d", &menu) == 0) {
			scanf("%c", &c);
			menu = 0;
		}
		//if (menu != -1 || menu < 1 || menu>8) menu = 0;
		doMenuItem(head, menu);

	} while ((menu != -1));
}

//Function used to do the menu item
void doMenuItem(struct node** head, int menu) {
	char tmpTxt[25];
	int tmpInt;
	int stats[8] = { 0,0,0,0,0,0,0 };
	struct node* tmp;
	switch (menu) {
		//Add player
		case 1:
			addSortedNode(head,(struct node*)malloc(sizeof(struct node)),1);
			break;

		//Diplay all players to screen
		case 2: 
			displayList(*head);
			break;
		
		//Display Player details
		case 3:
			//Get player position
			tmp = getPlayer(*head);
			if (tmp != 0x00000000)
				//Display the player's details
				displayDetails(tmp);
			break;

		//Update Player's statistics
		case 4: 
			//Get player position
			tmp = getPlayer(*head);
			if (tmp != 0x00000000)
				//Set the details of the node
				getNodeDetails(*head, tmp, 1);
			break;

		//Delete Player
		case 5: 
				//remove player
				removeItem(head);
			break;

		//Generate statistics
		case 6:
			//Generate statistics
			generateSatistics(*head, stats);
			//Display the statistics
			displayStatistics(stats);
			break;

		//Print all Players into a report file
		case 7:
			savePlayerStatisticsAndDetails("playerreport.txt", *head);
			break;

		//List all the players in Second Row and Back Row
		case 8:
			listPlayerInOrderOfHight(*head);
			break;
	}

}

//Function used to get a player
struct node* getPlayer(struct node* head) {
	char tmpTxt[25];
	struct node* tmp;
	//Check if the list is empty
	if (head == 0x00000000) {
		printf("\nThe list is empty");
		return 0x00000000;
	}
	//Get the player detail
	printf("\nEnter the players firstname or IRFU number:");
	scanf("%s", tmpTxt);
	//Get the position
	tmp = getItem(head, tmpTxt,0);
	//If the player doesnt exists
	if (tmp == 0x00000000) printf("\n Player not found");

	return tmp;
}