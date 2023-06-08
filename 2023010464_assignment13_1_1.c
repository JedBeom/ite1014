#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int accessBoard(char *board, int index);
int printBoardLine(char *board, int line);
int printBoardAll(char *board);
int winCheck(char *board);
int comPick(char *board);
int chooseSign();
int play();

int winCondition[8][3] = {
	// horizontal
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
	// vertical
	{1, 4, 7},
	{2, 5, 8},
	{3, 6, 9},
	// cross
	{1, 5, 9},
	{3, 5, 7},
};
char playerSign, comSign;

int main() {
	char answer[4] = "yes";
	while (strcmp(answer, "yes") == 0) {
		chooseSign();
		play();
		printf("Do you want to play again? (yes or no)\n");
		scanf("%s", answer);
	}

	return 0;
}


int chooseSign() {

	while (true) {
		printf("Select your sign (X or O)\n");
		scanf(" %c", &playerSign);
		
		if (playerSign == 'O') comSign = 'X'; else if (playerSign == 'X') comSign = 'O'; else {
			printf("Please enter O or X.\n");
			continue;
		}
	
		break;
	}

	return 0;
}

int play() {
	char board[9];
	for (int i=0; i<9; i++) board[i] = ' ';
	
	printf("The computer will go first.\n");
	int turn = 0;
	int picked = 0;
	int whoWon = 0;
	while (true) {
		turn++;

		if (turn%2==1) {
			picked = comPick(board);
			printf("Computer move on '%d'\n", picked);
			board[picked-1] = comSign;
		} else {
			printf("What is your next move? (1-9)\n");
			scanf("%d", &picked);
			board[picked-1] = playerSign;
		}

		printBoardAll(board);
		whoWon = winCheck(board);
		if (whoWon == 1) {
			printf("Computer win! You lose.\n");
			break;
		} else if (whoWon == 2) {
			printf("User win! Computer lose.\n");
			break;
		}

		if (turn >= 9) {
			printf("Draw!\n");
			break;
		}
	}

	return 0;
}

int accessBoard(char *board, int index ) {

	return board[index-1];
}

int printBoardLine(char *board, int line) {
	int end=3*line;
	for (int i=3*(line-1)+1; i<=end; i++) {
		printf("%c", accessBoard(board, i));

		if (i!=end) printf("|");
	}

	printf("\n");

	return 0;
}

int printBoardAll(char *board) {
	int i;
	for (i=3; i>0; i--) {
		printBoardLine(board, i);
		
		if (i>1) printf("-+-+-\n");
	}

	return 0;
}

int comPick(char *board) {
	char targetSet[3];
	int i, j, comSignCnt, playerSignCnt;
	int pickForBlock = 0;

	// Rule 1, 2
	for (i=0; i<8; i++) { // winCondition[i][j]
		playerSignCnt = comSignCnt = 0;

		for (j=0; j<3; j++) {
			targetSet[j] = accessBoard(board, winCondition[i][j]);
		}

		for (j=0; j<3; j++) {
			if (targetSet[j] == playerSign) playerSignCnt++;
			else if (targetSet[j] == comSign) comSignCnt++;
		}

		if (comSignCnt == 2) {
			for (j=0; j<3; j++) {
				if (targetSet[j] == ' ') {
					return winCondition[i][j];
				}
			}
		}

		if (playerSignCnt == 2) {
			for (j=0; j<3; j++) {
				if (targetSet[j] == ' ') {
					pickForBlock = winCondition[i][j];
					break;
				}
			}
		}
	}

	if (pickForBlock != 0) return pickForBlock;

	// Rule 3: 7, 3, 1, 9
	int cornerOrder[4] = {7, 3, 1, 9};
	for (i=0; i<4; i++) {
		if (accessBoard(board, cornerOrder[i]) == ' ') {
			return cornerOrder[i];
		}
	}

	// Rule 4
	if (accessBoard(board, 5) == ' ') {
		return 5;
	}

	// Rule 5
	int sideSpaceOrder[4] = {8, 2, 4, 6};
	for (i=0; i<4; i++) {
		if (accessBoard(board, sideSpaceOrder[i]) == ' ') {
			return sideSpaceOrder[i];
		}
	}

	return 0;
}

// 0 = nobody, 1 = com, 2 = player
int winCheck(char *board) {
	char targetSet[3];
	int i, j, comSignCnt, playerSignCnt;

	for (i=0; i<8; i++) { // winCondition[i][j]
		playerSignCnt = comSignCnt = 0;

		for (j=0; j<3; j++) {
			targetSet[j] = accessBoard(board, winCondition[i][j]);
		}

		for (j=0; j<3; j++) {
			if (targetSet[j] == playerSign) playerSignCnt++;
			else if (targetSet[j] == comSign) comSignCnt++;
		}

		if (comSignCnt == 3) {
			return 1;
		}

		if (playerSignCnt == 3) {
			return 2;
		}
	}

	return 0;
}
