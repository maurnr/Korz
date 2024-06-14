#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdexcept>
using namespace std;
////////////////////////////////////////////////////////////////////////
//////////variable declarations/////////////////////////////////////////
char action[100];
int life = 1;
int progress = 1;
char na[100] = "none";

//tools & enemies
int knife = 0;
int gun = 0;
int bullet = 0;
int enemy = 0;
int correctPassword = 14572;
int imputPassword = 0;

//keys
int keyl1 = 0;

//////////////////////////////////////////////////////////////////////////////
//Life Checker  & LVL function declaration (so it works regardless of the level)/////
void lifeChecker();
void lvl1();
void lvl2();
void lvl3();
void lvl4();
void lvl5();
void lvl6();
void lvl7();

////////////////////////////////////////////////////////////////////////
//////////Space Remover Function, DO NOT EDIT//////////////////////////
void removeSpaces(char* action)
{
	// To keep track of non-space character count
	int count = 0;

	// Traverse the given string. If current character
	// is not space, then place it at index 'count++'
	for (int i = 0; action[i]; i++)
		if (action[i] != ' ')
			action[count++] = action[i]; // here count is
	// incremented
	action[count] = '\0';
}

//Question Funcion + remove spaces function is called
void question() {
	cout << "What Will you Do?\n";
	cin.getline(action, sizeof action);
	removeSpaces(action);
}

////////////////////////////////////////////////////////////////////////
//////////LEVELS GO HERE///////////////////////////////////////////////

//GAME OVER Screen
void gameOver() {
	cout << "GAME OVER.\n";
	abort();
}

//LVL1
void lvl1() {
	system("CLS");
	cout << "You are stuck in a room, there is a door, a chest, and a window.\n";
	question();


	//if types open chest
	if ((strcmp(action, "openchest") == 0) or (strcmp(action, "OpenChest") == 0)) {

		if (keyl1 == 0) {
			keyl1++;
			cout << "You opened the chest, and found a key.\nYou Now Have " << keyl1 << " Keys.\n";
			char action[100] = "";
			Sleep(3000);//timer
			lvl1();
		}
		else {
			cout << "You found nothing else on the chest.\n";
			char action[100] = "";
			Sleep(3000);//timer
			lvl1();
		}
	}

	// if types inspect window
	if ((strcmp(action, "inspectwindow") == 0) or (strcmp(action, "InspectWindow") == 0)) {
		cout << "As you inspect the window you realize it is covered in dust, you try to pry it open, but as you push on the window it collapses and you fall to your death.\n";
		life--;
		cout << "You now have " << life << " lives.\n";
		char action[100] = "";
		Sleep(7000);//timer
		lifeChecker(); //check lives
	}
	// if types open door
	if ((strcmp(action, "opendoor") == 0) or (strcmp(action, "OpenDoor") == 0)) {
		//if you have a key
		if (keyl1 == 1) {
			cout << "You try to open the locked door with the key you found in the chest, and it opens. You then go to the next room.\n";
			char action[100] = "";
			Sleep(6000);//timer
			progress++;
			lvl2();
		}
		//if you dont have a key
		else {
			cout << "You try to open the door but it's locked. You need to find a key first.\n";
			char action[100] = "";
			Sleep(3000);//timer
			lvl1();
		}
	}

	//if invalid imput
	else {
		cout << "You typed in an invalid action, please try again.\n";
		cout << action;
		char action[100] = "";
		Sleep(3000);//timer
		lvl1();
	}

}

//LVL2
void lvl2() {
	system("CLS");
	cout << "As you move out of the other room, you realize you are located in a living room. There is a window, a bookshelf, a table, a couch, and some stairs.\n";
	question();

	//if types inspect window
	if ((strcmp(action, "inspectwindow") == 0) or (strcmp(action, "InspectWindow") == 0)) {
		cout << "As you inspect the window you realize it is covered in dust, you try to pry it open, but as you push on the window it collapses and you fall to your death.\n";
		life--;
		cout << "You now have " << life << " lives.\n";
		char action[100] = "";
		Sleep(7000);//timer
		lifeChecker(); //check lives
	}
	//if types inspect couch
	if ((strcmp(action, "inspectcouch") == 0) or (strcmp(action, "InspectCouch") == 0)) {

	}
	//if types inspect table
	if ((strcmp(action, "inspecttable") == 0) or (strcmp(action, "InspectTable") == 0)) {
		//first time inspecting table
		if (life == 1) {
			cout << "You inspect the table, and find a health kit, wich grants you one more life.\n";
			life++;
			cout << "You now have " << life << " lives.\n";
			char action[100] = "";
			Sleep(3000);//timer
			lvl2();
		}
		//if inspects table again (to avoid cheaters)
		else {
			cout << "You found nothing else on the table.\n";
			char action[100] = "";
			Sleep(3000);//timer
			lvl2();
		}
	}

	//if types inspect bookshelf
	if ((strcmp(action, "inspectbookshelf") == 0) or (strcmp(action, "Inspectbookshelf") == 0)) {
		//first time inspecting bookshelf
		if (knife == 0) {
			cout << "You inspect the bookshelf, and find a secret compartment with a knife in it. You then proceed to take the knife.\n";
			knife++;
			cout << "You now have " << knife << " Knives.\n";
			char action[100] = "";
			Sleep(4000);//timer
			lvl2();
		}
		//if inspects bookshelf again (to avoid cheaters)
		else {
			cout << "You found nothing else on the bookshelf.\n";
			char action[100] = "";
			Sleep(3000);//timer
			lvl2();
		}
	}

	//if types inspect couch
	if ((strcmp(action, "inspectcouch") == 0) or (strcmp(action, "InspectCouch") == 0)) {
		cout << "You inspect the couch and find nothing.\n";
		char action[100] = "";
		Sleep(3000);//timer
		lvl2();
	}

	//if types use stairs
	if ((strcmp(action, "usestairs") == 0) or (strcmp(action, "UseStairs") == 0)) {
		cout << "You use the stairs to go down to the first floor.\n";
		char action[100] = "";
		progress++;
		Sleep(7000);//timer
		lvl3();
	}
	//if invalid imput
	else {
		cout << "You typed in an invalid action, please try again.\n";
		char action[100] = "";
		Sleep(3000);//timer
		lvl2();
	}

}

///LVL3
void lvl3() {
	system("CLS");
	//char action[100] = "";
	cout << "As you go down the stairs, you realize you are located on the lobby of a house. This room has three unlocked doors, the main door, a door that leads to the kitchen, and a door that leads to the basement.\n";
	question();

	//if types enter kitchen
	if ((strcmp(action, "enterkitchen") == 0) or (strcmp(action, "EnterKitchen") == 0)) {
		//if you have a knife
		if (knife == 1) {
			cout << "As you enter the kitchen, you are surprised by a robber. You try to pull your knife on him, but it's too late, for he has shot you, and you are dead.\n";
			life--;
			cout << "You now have " << life << " lives.\n";
			char action[100] = "";
			Sleep(7000);//timer
			lifeChecker(); //check lives
		}
		//if you dont have knife
		else {
			cout << "As you enter the kitchen, you are surprised by a robber. You try to attack him, but you are unarmed. The robber then shoots you, and you die.\n";
			life--;
			cout << "You now have " << life << " lives.\n";
			char action[100] = "";
			Sleep(7000);//timer
			lifeChecker(); //check lives
		}
	}

	//if types exit house
	if ((strcmp(action, "exithouse") == 0) or (strcmp(action, "ExitHouse") == 0)) {
		cout << "You open the main door and leave the house through the porch.\n";
		char action[100] = "";
		Sleep(4000);//timer
		progress = 4;
		lvl4();
	}

	//if types enter basement
	if ((strcmp(action, "enterbasement") == 0) or (strcmp(action, "EnterBasement") == 0)) {
		cout << "You open the basement door and enter the room.\n";
		char action[100] = "";
		Sleep(4000);//timer
		progress = 5;
		lvl5();
	}
}

//LVL4 (Porch)
void lvl4() {
	system("CLS");
	cout << "lvl4.\n";
	question();
}

//LVL5 (Basement)
void lvl5() {
	system("CLS");
	cout << "lvl5.\n";
	question();
}

//LVL6 (Basement 2)
void lvl6() {
	system("CLS");
	cout << "lvl6.\n";
	question();
}

//LVL7 (Street)
void lvl7() {
	system("CLS");
	cout << "lvl7.\n";
	question();
}


//Life Checker
void lifeChecker() {

	//when you are out of lifes go to game over sequence
	if (life <= 0) {
		gameOver();
	}

	//if you are not out of lives check for progression and send to level function
	else {

		//progress lvl1
		if (progress == 1) {
			lvl1();
		}

		//progress lvl2
		if (progress == 2) {
			lvl2();
		}

		//progress lvl3
		if (progress == 3) {
			lvl3();
		}

		//progress lvl4
		if (progress == 4) {
			lvl4();
		}
		//progress lvl5
		if (progress == 5) {
			lvl5();
		}
		//progress lvl6
		if (progress == 6) {
			lvl6();
		}
		//progress lvl7
		if (progress == 7) {
			lvl7();
		}




	}
	//

}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

// Main program
int main()
{
	//credits
	cout << "Created by Mauricio Nunez - 2018\n";
	Sleep(3000);
	system("CLS");

	// tittle
	cout << "KORZ v1.0\n";
	Sleep(3000);
	system("CLS");

	//intro
	cout << "To be able to play, type in the action you want to do; for instance, if you want to open a door, type in 'open door'.\nPress ENTER to begin a new game...\n";
	getchar();

	lifeChecker();
	//removeSpaces(action);
	cout << action;

	return 0;
}