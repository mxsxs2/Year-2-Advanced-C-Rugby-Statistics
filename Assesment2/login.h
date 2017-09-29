#ifndef LOGIN_H
#define LOGIN_H

struct login {
	char name[7];
	char pass[7];
};

//Function used to authenticate the user
int login(struct login* login);
//Function used to get the credentials from the user
void getCrendentials(struct login* login);

#endif