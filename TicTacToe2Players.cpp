#include <iostream>
#include <conio.h> //lel only for getch();
using namespace std;

void draw(char *ptr){
	system("cls");
	
	cout << endl;
	cout << ptr[0] << " " << ptr[1] << " " << ptr[2];
	cout << endl << endl;
	cout << ptr[3] << " " << ptr[4] << " " << ptr[5];
	cout << endl << endl;
	cout << ptr[6] << " " << ptr[7] << " " << ptr[8];
	cout << endl << endl << "Player " << ptr[9] << ": ";
}

void choose(char *ptr){
	CHOOSE:
	
	int input = 0;
	cin >> input;
	
	if(input > 0 && input < 10){
		if(ptr[input - 1] == 'X' | ptr[input - 1] == 'O'){
			cout << endl << "This place is already chosen, choose another one: ";
			goto CHOOSE;
		}
		else ptr[input - 1] = ptr[9];
		
		//switch the player
		if(ptr[9] == 'X'){
			ptr[9] = 'O';
		}
		else ptr[9] = 'X';
	}
	else { //invalid input
		cout << endl << "Something went wrong, try again: "; 
		goto CHOOSE;
	}
}

void win(char *ptr){
	if(ptr[0] == 'X' && ptr[1] == 'X' && ptr[2] == 'X'){
		ptr[9] = 'x';
	}
	if(ptr[3] == 'X' && ptr[4] == 'X' && ptr[5] == 'X'){
		ptr[9] = 'x';
	}
	if(ptr[6] == 'X' && ptr[7] == 'X' && ptr[8] == 'X'){
		ptr[9] = 'x';
	}
	
	if(ptr[0] == 'O' && ptr[1] == 'O' && ptr[2] == 'O'){
		ptr[9] = 'o';
	}
	if(ptr[3] == 'O' && ptr[4] == 'O' && ptr[5] == 'O'){
		ptr[9] = 'o';
	}
	if(ptr[6] == 'O' && ptr[7] == 'O' && ptr[8] == 'O'){
		ptr[9] = 'o';
	}
	
	
	if(ptr[0] == 'X' && ptr[3] == 'X' && ptr[6] == 'X'){
		ptr[9] = 'x';
	}
	if(ptr[1] == 'X' && ptr[4] == 'X' && ptr[7] == 'X'){
		ptr[9] = 'x';
	}
	if(ptr[2] == 'X' && ptr[5] == 'X' && ptr[8] == 'X'){
		ptr[9] = 'x';
	}
	
	if(ptr[0] == 'O' && ptr[3] == 'O' && ptr[6] == 'O'){
		ptr[9] = 'o';
	}
	if(ptr[1] == 'O' && ptr[4] == 'O' && ptr[7] == 'O'){
		ptr[9] = 'o';
	}
	if(ptr[2] == 'O' && ptr[5] == 'O' && ptr[8] == 'O'){
		ptr[9] = 'o';
		
		
	}
	if(ptr[0] == 'X' && ptr[4] == 'X' && ptr[8] == 'X'){
		ptr[9] = 'x';
	}
	if(ptr[2] == 'X' && ptr[4] == 'X' && ptr[6] == 'X'){
		ptr[9] = 'x';
	}
	
	if(ptr[0] == 'O' && ptr[4] == 'O' && ptr[8] == 'O'){
		ptr[9] = 'o';
	}
	if(ptr[2] == 'O' && ptr[4] == 'O' && ptr[6] == 'O'){
		ptr[9] = 'o';
	}
	
	//check for a tie
	if(ptr[0] != '1' && ptr[1] != '2' && ptr[2] != '3' &&
	ptr[3] != '4' && ptr[4] != '5' && ptr[5] != '6' && 
	ptr[6] != '7' && ptr[7] != '8' && ptr[8] != '9'){
		ptr[9] = 't';
	}
}

int main() {
	char board[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'X'};
	char *pointer = board;
	char winner;
	
	bool end = false;
	
	while(!end){
		draw(pointer);
		choose(pointer);
		win(pointer);
		
		//checks for winner (note: the player is capital, if there is a winner, it is replaced with lower case O or X)
		if(board[9] == 'x'){
			winner = 'x';
			end = true;
		}
		else if(board[9] == 'o'){
			winner = 'o';
			end = true;
		}
		else if(board[9] == 't'){
			winner = 't';
			end = true;
		}
	}
	
	system("cls");
	
	if(winner == 'x'){
		cout << endl;
		cout << "X WON!!!";
		getch();
	}
	else if(winner == 'o'){
		cout << endl;
		cout << "O WON!!!";
		getch();
	}
	else if(winner == 't'){
		cout << endl;
		cout << "It's a tie! Both of you win!";
		getch();
	}
	else {
		cout << "Something went wrong";
		getch();
	}	
	
	return 0;
}
