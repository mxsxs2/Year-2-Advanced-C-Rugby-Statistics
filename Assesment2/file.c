#include <stdio.h>
#include "file.h"
#include "list.h"
#include "statistics.h"
#include "login.h"
//Function used to open a file
FILE* openFIle(char file[100], char flag[2]) {
	//Open the file
	return fopen(file, flag);
}

//Function used to close a file
void closeFile(FILE* fptr) {
	//Close if the pointer is not empty
	if (fptr != 0x00000000)	fclose(fptr);
};


//Function used to save tha players
void savePlayers(FILE* fptr, struct node* head) {
	struct node* tmp;

	//Exit if the file pointer is empty
	if (fptr == 0x00000000) return;

	tmp = head;

	//loop to the end
	while (tmp != 0x00000000) {
		//Write the single player
		fprintf(fptr, "%d %s %s %d %f %f %s %s %d %d %d", tmp->IRFU,tmp->firstname,tmp->secondname,tmp->age,tmp->height,tmp->weight,tmp->club,tmp->email,tmp->position,tmp->tacklesmissed,tmp->metersmake);
		if (tmp->next != 0x00000000) fprintf(fptr, "\n");
		//Go to the next
		tmp=tmp->next;
	}
}

//Function used to load the players
void loadPlayers(FILE* fptr, struct node** head) {
	struct node* newNode;
	struct node* prev_temp= 0x00000000;
	int nfields = 11;
	size_t nret;
	//Exit if the file pointer is empty
	if (fptr == 0x00000000) return;

	//Loop the file til ends
	while (!feof(fptr)) {
		//Allocate memory for the new node
		newNode = (struct node*)malloc(sizeof(struct node));
		newNode->IRFU = 0x00000000;
		//Reat the line
		nret = fscanf(fptr, "%d %s %s %d %f %f %s %s %d %d %d", &newNode->IRFU, newNode->firstname, newNode->secondname, &newNode->age, &newNode->height, &newNode->weight, newNode->club, newNode->email, &newNode->position, &newNode->tacklesmissed, &newNode->metersmake);
		//Without this line the while runs forever	
		if (nret != EOF) fscanf(fptr, "%*[^\n]");
			
			//If IRFU set
			if (newNode->IRFU != 0x00000000) {
				newNode->next = 0x00000000;
				//If there is already one
				if (prev_temp != 0x00000000) {
					//Set the link
					prev_temp->next = newNode;
					prev_temp = newNode;
				} else {
					//If this is the first then set the head
					*head = newNode;
					prev_temp = *head;
				}
			} else {
				//Remove junk
				free(newNode);
			}
	}

};

//Function used to write layer details and statistics into the file
void savePlayerStatisticsAndDetails(char file[50],  struct node* head) {
	//Temporary player
	struct node* tmp;
	//Player counter
	int i = 0;
	//Statistics holder
	int stats[8] = { 0,0,0,0,0,0,0 };
	//File pointer
	FILE* fptr= openFIle(file, "w");

	//Exit if the file pointer is empty
	if (fptr == 0x00000000) return;
	//Notify user
	printf("\n\nWriting player details...");

	//Set the head as starting point
	tmp = head;
	//Write file header
	fprintf(fptr, "Player details:\n\n");
	//loop to the end
	while (tmp != 0x00000000) {

		fprintf(fptr, "\nPlayer at position %d", ++i);
		//Write the single player
		writeDetails(fptr,tmp);
		//Go to the next
		tmp = tmp->next;
	}

	//Write statistics header
	fprintf(fptr, "\n\nPlayer satistics:");
	//Generate the statistics
	generateSatistics(head, stats);
	//Write statistics
	writeStatistics(fptr, stats);
	//Notify user
	printf("\nThe report is saved");
	//Close the file
	closeFile(fptr);

}


//Function used to display statistics
void writeStatistics(FILE* fptr, int stat[8]) {
	int i = 0;
	for (i = 0; i < 8; i++)	fprintf(fptr,"\n%d %s", stat[i], STATISTICSTEXT[i]);
}

//Function used to display the details of a player
void writeDetails(FILE* fptr,struct node* node) {
	//Exit if it is not filled
	if (node == 0x00000000) return;
	fprintf(fptr, "\n\tIRFU: %d", node->IRFU);
	fprintf(fptr, "\n\tFirst Name: %s", node->firstname);
	fprintf(fptr, "\n\tSecond Name: %s", node->secondname);
	fprintf(fptr, "\n\tAge: %d", node->age);
	fprintf(fptr, "\n\tHeight: %.2f", node->height);
	fprintf(fptr, "\n\tWeight: %.2f", node->weight);
	fprintf(fptr, "\n\tClub: %s", node->club);
	fprintf(fptr, "\n\tEmail: %s", node->email);
	fprintf(fptr, "\n\tPosition: %s", POSITIONS[node->position]);
	fprintf(fptr, "\n\tTackles missed per match: %s", TAKLESMISSED[node->tacklesmissed]);
	fprintf(fptr, "\n\tMetres made per game: %s", METRESMADE[node->metersmake]);
}


int compareCredentialsToFile(FILE* fptr, struct login login) {
	//Temporary credential holders holder 
	char tmpName[7];
	unsigned long tmpPass;
	size_t nret;
	//Return 0 as it failed
	if (fptr == 0x00000000) return 0;

	//Loop the file
	while (!feof(fptr)) {
		//Get the line
		nret=fscanf(fptr, "%s %ul", tmpName, &tmpPass);
		//Without this line the while runs forever	
		if (nret == -1) return 0;
		//If the name and the password hash matches then return 1
		if (strcmp(tmpName, login.name) == 0 && tmpPass == getHash(login.pass)) return 1;
	}
	//Retunr 0 as it failed
	return 0;
}

//Function used to has a string
unsigned long getHash(unsigned char *str) {
		//The has
		unsigned long hash = 5381;
		//Each char
		int c;
		//Calculate the hast char by char
		while (c = *str++)	hash = ((hash << 5) + hash) + c; 
		//Return the hash
		return hash;
}