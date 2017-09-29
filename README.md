# Introduction
The application is written in C for Advanced Procedural Programming module in year 2 of Software Development(2017) course at Galway Mayo Institute of Technology, Galway Campus.
The application is a database and analyser for rugby players.
# How to run
In order to run the applaication, it has to be built first. It can be buil either from the "Assesment2" folder with a commandline compiler or open up the Assesment2.sln in Microsoft Visual Studio and build from there.


# Fetures:
0) Login
	* The login details are stored in password.pw file. The file contains the user name and a pasword has for each user.
	* The password and user name are 6 charcater long and required in th beggining of the program.
	* The login is a simple struct,which is passed to various functions
1) Add	player
	* Request several details of the palyer then save it intu a player struct.
	* The IRFU id is unique in the whole list.
	* The list is ordered on insertion by the IRFU id
2) Display all players to screen
	* Loop throught the list of players and displays every single detail of the players.
3) Display player Details
	* Requires and input fomr the user, which can be the IRFU or the First name of the player.
	* Loops throught the list and displays the first macth. (If two players has the same name, the first will be shown)
4) Update a player’s statistic
	* Requires and input fomr the user, which can be the IRFU or the First name of the player.
	* Loops throught the list and displays the first macth for update. (If two players has the same name, the first will be shown)
	* Every attribute of a player can be edited.
5) Delete player
	* Requires and the IRFU the player.
	* Will remove from any position. 
6) Generate statistics based on the user selecting one of the criteria listed in I - II
	* Requires the user to choose one of the two options:
		* Player Position
			* Requires the user to choose the position of the player.
		* Weight
			* Requires the player to input a weight. The data will be filtered this weight upwards.
7) Print all player details into a report file.
	* Does the same as menu 2 and menu 6, but insted of writing to the screen. It writes to playerreport.txt.
8) List all the players of the following categories in order of height:
	* Requires the user to chose one of the following:
		* Second Row
		* Back Row
	* Re organizes and filters the whole list into a new list. The list is in order by height.



The players are stored in Rugby.txt which is space delimited and ordered by IRFU.
The player performances are stored as int and they reflects the arrays in file.c

Every input is validated in the application.
	It has to be done in order to prevent infinite loop when the user enters a letter instead of a number. This makes the code look ugly, but it is needed.

The passwords are stored as a hash. For security reasosns the password should never be human readable.
(I would say there is no point to have multiple password without permission restriction. Permission restriction was not required for the project, so i left it out)

The test login credetials are:
admin0 admin0


	
