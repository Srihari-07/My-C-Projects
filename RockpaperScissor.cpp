#include <iostream>
#include <random>
using namespace std;

// Methods Used:
int getUserChoice(); 
int getComputerChoice();  
int checkResult(int userchoice, int computerchoice);  
void showFinalResults(int userscore, int computerscore);
void showChoice(int userchoice, int computerchoice); 


int main(){
	// Game Start!
	int userchoice, computerchoice, result,userscore, computerscore, totalPlays;
	cout << "************* ROCK PAPER SCISSORS **************\nHow many times you want to Play? \nENTER : ";
	cin >> totalPlays;
	
	for(int i = 1; i<=totalPlays; i++){
		
		userchoice = getUserChoice();
		if(userchoice == -1){cout << "You Lost 1 Attempt to play!\n" << endl; continue;}
		computerchoice = getComputerChoice();
		
		showChoice(userchoice, computerchoice);
		result = checkResult(userchoice, computerchoice);
		
		if(result == 1){userscore++;}
		else if(result == 0){computerscore++;}
		
		cout << endl << "Your Score     : " << userscore<<endl;
		cout << "Computer Score : "<< computerscore <<endl << endl;
		
		if(result == 0){cout << "Computer Won!\n" << endl;}
		else if (result == 1){cout << "You Won!\n" << endl;}
		else{cout << "TIE!\n" << endl;}
		
		cout << "Remaining Attempts : "<< totalPlays-i << endl;
		
	}
	
	showFinalResults(userscore, computerscore);
	
	return 0;
}

// Take's the user's input for the game.
int getUserChoice(){
	int userchoice;
	cout << "************* ROCK PAPER SCISSORS **************\nPress : 0 -> ROCK , 1 -> PAPER , 2 -> SCISSORS \nENTER: ";
	cin >> userchoice;
	if (userchoice > 2 || userchoice < 0){
			cout<< "Enter an Valid Option between 0 , 1 and 2.\n" << endl;
		}
	else{return userchoice;}
	return -1;
}

// Computer plays it's turn.
int getComputerChoice(){
	std::random_device rd;  // Obtain a random seed
    std::mt19937 gen(rd()); // Mersenne Twister PRNG
	std::uniform_int_distribution<int> dist(0, 2); // Range [0, 2]
	return dist(gen);
}

// Main game logic to decide the winner.
int checkResult(int userchoice, int computerchoice){
	int result;
	// Conditions when Game Tie's
	if ((userchoice == 0 && computerchoice == 0) || (userchoice == 1 && computerchoice == 1)  || (userchoice == 2 && computerchoice == 2)){
		result = -1;
	}
	// Conditions when the user will win.
	else if ((userchoice == 0 && computerchoice == 2) || (userchoice == 1 && computerchoice == 0) || (userchoice == 2 && computerchoice == 1)){
		result = 1;
	}
	else{
		result = 0;
	}
	
	return result;
}
// Display's the Game choice's of both the Player
void showChoice(int userchoice, int computerchoice){
	string user, computer;
	switch(userchoice){
		case 0:
			user = "ROCK";
			break;
		case 1:
			user = "PAPER";
			break;
		case 2:
			user = "SCISSOR";
			break;
	}
	switch(computerchoice){
		case 0:
			computer = "ROCK";
			break;
		case 1:
			computer = "PAPER";
			break;
		case 2:
			computer = "SCISSOR";
			break;
	}
	
	cout << "You      : " << user<< endl;
	cout << "Computer : " << computer << endl;
	
}

// Display's the final scores of the Game.
void showFinalResults(int userscore, int computerscore){
	
	cout << "================= FINAL SCORE ===============\n";
	
	if(userscore > computerscore){
		cout << "******** You Won! ********\n";
	}
	else if (computerscore > userscore){
		cout << "******** You Lose ******** \nBetter Luck next Time!\n";
	}
	else{cout << " ********* GAME TIE! *********\n";}
	
	cout << "Your Score : " << userscore << endl;
	cout << "Computer Score : " << computerscore << endl;
	
}
