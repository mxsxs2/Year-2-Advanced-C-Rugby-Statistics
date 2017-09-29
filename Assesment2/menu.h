#ifndef MENU_H
#define MENU_H

//Function used to show the menu
void showMenu(struct node** head);

//Function used to draw the main menu
void drawMain(struct node** head);

//Function used to do the menu item
void doMenuItem(struct node** head, int menu);

//Function used to get a player
struct node* getPlayer(struct node* head);
#endif