#include "login.h";
#include "file.h";

//Function used to authenticate the user
int login(struct login* login) {
	//The credential holders
	char name[7]="";
	char pass[7]="";

	int logined = 0;
	//Get the credentials
	getCrendentials(login);
	//Open the file
	FILE* passwordfile = openFIle("password.pw", "r");
	//Check credentials
	logined=compareCredentialsToFile(passwordfile, *login);
	//Close the file
	closeFile(passwordfile);
	//Return the result
	return logined;
}

//Function used to get the credentials from the user
void getCrendentials(struct login* login) {
	char c;
	short counter = 0;
	///Name
	printf("Please enter the login name: ");
	//Read the name
	while (counter < 6 && (c = getch()) != '\n') {
		login->name[counter] = c;
		printf("%c", c);
		counter++;
	}
	login->name[6] = '\0';

	///Password
	printf("\nPlease enter the password:");
	//Reset counter
	counter = 0;
	//Read the password
	while (counter < 6 && (c = getch()) != '\n') {
		login->pass[counter] = c;
		printf("*");
		counter++;
	}
	login->pass[6] = '\0';
}

