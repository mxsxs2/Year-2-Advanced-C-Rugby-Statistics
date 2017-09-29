/*Krisztian Nagy - G00330024*/

#include "menu.h"
#include "list.h"
#include "file.h"
#include "login.h"

int main() {
	//The head of the player list
	struct node* head = 0x00000000;
	FILE* players;
	int loggedin = 0;
	//Login structure
	struct login* loginU = (struct login*)malloc(sizeof(struct login));

	//Keep asking for the password and user name until it passes
	do {
		//Try to log in
		loggedin=login(loginU);
		//If not successful then notify the user
		if (loggedin == 0) printf("\nWrong password or user name. Try again.\n");
	} while (loggedin == 0);
	
	//This area is available after login

	//This line is helpful if there loading time is longer
	printf("\nPlease wait loading players database...\n");
	
	
	///Load players from a file
	//Open the player file
	players= openFIle("Rugby.txt","r");
	//Read the initial file
	loadPlayers(players, &head);
	//Close the player file
	closeFile(players);

	
	//Show the mnu
	showMenu(&head);

	
	///Save the players to a file
	//Open the player file
	players = openFIle("Rugby.txt", "w");
	//Read the initial file
	savePlayers(players, head);
	//Close the player file
	closeFile(players);

	//Free the login 
	free(loginU);
}

