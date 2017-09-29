#ifndef STATISTICS_H
#define STATISTICS_H

extern const char STATISTICSTEXT[8][50];

//Function used to display players in order of height
void listPlayerInOrderOfHight(struct node *head);

//Function used to sort the players  by height
struct node* sortPlayers(struct node *head, int mode);

//Function used to duplicate a node
struct node* duplicateNode(struct node* from);

//Function used to display statistics
void displayStatistics(int stat[8]);

#endif