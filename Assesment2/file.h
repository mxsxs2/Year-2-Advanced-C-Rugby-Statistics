#ifndef FILE_H
#define FILE_H
#include <stdio.h>

//Function used to open a file
FILE* openFIle(char file[100], char flag[2]);

//Function used to close a file
void closeFile(FILE* fptr);

//Function used to save tha players
void savePlayers(FILE* fptr, struct node* head);

//Function used to load the players
void loadPlayers(FILE* fptr, struct node** head);

//Function used to write layer details and statistics into the file
void savePlayerStatisticsAndDetails(char file[50], struct node* head);

//Function used to display statistics
void writeStatistics(FILE* fptr, int stat[8]);

//Function used to display the details of a player
void writeDetails(FILE* fptr, struct node* node);

//Function used to has a string
unsigned long getHash(unsigned char *str);

int compareCredentialsToFile(FILE* fptr, struct login login);
#endif