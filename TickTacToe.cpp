#include <iostream>
#include <random>
using namespace std;

void drawBoard(char *spaces);
void computerMove(char *spaces , char computer);
void playerMove(char *spaces, char player);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);
char playAgain();
int main(){
	
	char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

	bool running = true;
	bool play = true;
	char player = 'X';
	char computer = 'O';
	
	// Play again loop
	while(play){
	
	cout << "============= TIC TAC TOE ==============" << endl << endl;
	cout << " You -> X \n Computer -> O" << endl;
	drawBoard(spaces);
	
	
		// Main game loop.
		while(running){
			// user plays
			playerMove(spaces, player);
			
			// Game Grid
			cout<< endl << "Your Move : \n";
			drawBoard(spaces);
			
			// Checks for Winner or Tie game
			if(checkWinner(spaces, player, computer)){
				break;
			}
			else if(checkTie(spaces)){
				break;
			}
			
			// Computer plays it's turn.
			cout<< "Computer's Move : \n";
			computerMove(spaces, computer);
			drawBoard(spaces);
			
			// Checks for Winner or Tie game.
			if(checkWinner(spaces, player, computer)){
				break;
			}
			else if(checkTie(spaces)){
				break;
			}
		}
		
		if(playAgain() == 'n') {break;}
		fill(spaces, spaces + 9, ' ');  // Fills the array with empty spaces to play again.
}
	
	
	cout << endl << "================= Thank You For Playing =================" << endl;
	
	return 0;
}
void drawBoard(char *spaces){
	cout << "  "<< spaces[0]<<"  |  "<< spaces[1]<<"  |  "<< spaces[2]<< "  " << "\n";
	cout << " ---------------" << "\n";
	cout << "  "<< spaces[3]<<"  |  "<< spaces[4]<<"  |  "<< spaces[5]<< "  " << "\n";
	cout << " ---------------" << "\n";
	cout << "  "<< spaces[6]<<"  |  "<< spaces[7]<<"  |  "<< spaces[8]<< "  " << "\n";
	cout << endl << endl;
}

void computerMove(char *spaces , char computer){
	int computerIndex;
	while(true){
		std::random_device rd;  // Obtain a random seed
		std::mt19937 gen(rd()); // Mersenne Twister PRNG
		std::uniform_int_distribution<int> dist(0, 8); // Range [0, 8]
		computerIndex = dist(gen);
		
		if(spaces[computerIndex] == ' '){
			spaces[computerIndex] = computer;
			break;
		}
}
}

void playerMove(char *spaces, char player){
	int index;
	do{
		cout << "Enter your move between(1-9) : ";
		cin >>  index;
		index--;
		if(spaces[index] == ' '){
			spaces[index] = player;
			break;
		}
		
	}while(true); //!index > 0 || !index < 8
}

bool checkWinner(char *spaces, char player, char computer){
	
	// For Rows
	if(spaces[0] != ' ' && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
		spaces[0] == player ? cout << "You win!\n" : cout << "You lose!\n";   // using ternary operators.
	}
	else if(spaces[3] != ' ' && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
		spaces[3] == player ? cout << "You win!\n" : cout << "You lose!\n";
	}
	else if(spaces[6] != ' ' && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
		spaces[6] == player ? cout << "You win!\n" : cout << "You lose!\n";
	}
	
	// For colums
	else if(spaces[0] != ' ' && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
		spaces[0] == player ? cout << "You win!\n" : cout << "You lose!\n";
	}
	else if(spaces[1] != ' ' && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
		spaces[1] == player ? cout << "You win!\n" : cout << "You lose!\n";
	}
	else if(spaces[2] != ' ' && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
		spaces[2] == player ? cout << "You win!\n" : cout << "You lose!\n";
	}
	
	// For Diagonal
	else if(spaces[0] != ' ' && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
		spaces[0] == player ? cout << "You win!\n" : cout << "You lose!\n";
	}
	else if(spaces[2] != ' ' && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
		spaces[2] == player ? cout << "You win!\n" : cout << "You lose!\n";
	}
	
	else{return false;}
	
	
	return true;
		
}
bool checkTie(char *spaces){
	for(int i = 0; i<9; i++){
		if(spaces[i] == ' '){
			return false;
		}
	}
	cout << "It's a TIE!" << endl;
	return true;
	
	
}
char playAgain(){
	char play;
	
	while(true){
		cout << "Want to Play Again? "  << "Press : y (yes) / n (no) : ";
		cin >> play;
		
		if(play != 'y' && play != 'n'){
			cout << "Enter the Correct Option." << endl << endl;
			continue;
		}
		else{break;}
	}
	return play;
}


