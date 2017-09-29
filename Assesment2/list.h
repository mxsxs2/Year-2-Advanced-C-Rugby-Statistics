#ifndef LIST_H
#define LIST_H


//Player positions
extern const char POSITIONS[7][18];


//Takles made
extern const char TAKLESMISSED[4][32];

//Metres made
extern const char METRESMADE[4][25];

//Struct for the linked list nodes
struct node {
	int IRFU; // IRFU Number(Assume	an	integer	– must	be	unique)
	char firstname[25]; //First	Name
	char secondname[25]; //Second	Name
	int age; //Age
	float height; //Height
	float weight; //Weight
	char club[100]; // Club
	char email[50]; // Email	Address(must	contain	an	@,	a	full	stop	and	a.com)
	int position; //Player position
	int tacklesmissed; //Takles missed
	int metersmake; //Meters make
	struct node* next; //Next node
};

//Function used to add a node to a sorted list
void addSortedNode(struct node** head, struct node* newNode, short mode);

//Function used to get the details of a node
void getNodeDetails(struct node* head, struct node* node, int showprevious);

//Function used to display a list
void displayList(struct node* head);

//Function used to display the details of a player
void displayDetails(struct node* node);

//Get The length of the function
int getLenght(struct node* head);

//Remove an item from the list at a given position
short removeItemAtPosition(struct node** head, int position);

//Remove an item from the list
void removeItem(struct node** head);

//Get the index of an item
struct node* getItem(struct node* head, char txt[25], int irfuonly);

#endif