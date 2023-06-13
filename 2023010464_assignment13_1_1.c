#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int getBoard(int index);
int printBoardLine(int line);
int printBoardAll();
int winCheck();
int comPick();
int chooseSign();
int play();
int initBoard();

int winCombination[8][3] = {
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
char board[9];

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

int initBoard() {
	for (int i=0; i<9; i++) board[i] = ' ';
	return 0;
}

int play() {
	initBoard();
	printf("The computer will go first.\n");
	int turn = 0;
	int picked = 0;
	int whoWon = 0;
	while (true) {
		turn++;

		if (turn%2==1) { // computer turn: 1, 3, 5, 7, 9
			picked = comPick(board);
			printf("Computer move on '%d'\n", picked);
			board[picked-1] = comSign;
		} else { // player turn: 2, 4, 6, 8
			printf("What is your next move? (1-9)\n");
			scanf("%d", &picked);
			board[picked-1] = playerSign;
		}

		printBoardAll();
		whoWon = winCheck();
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

int getBoard(int index ) {
	return board[index-1];
}

int printBoardLine(int line) {
	int end=3*line;
	for (int i=3*(line-1)+1; i<=end; i++) {
		printf("%c", getBoard(i));

		if (i!=end) printf("|");
	}

	printf("\n");

	return 0;
}

int printBoardAll() {
	int i;
	for (i=3; i>0; i--) {
		printBoardLine(i);
		
		if (i>1) printf("-+-+-\n");
	}

	return 0;
}

int comPick() {
	char targetSet[3];
	int i, j;
	int pickForBlock = 0;
	int comSignCnt, playerSignCnt, blankPosition;

	// Rule 1(+Find cases that fit into Rule 2)
	for (i=0; i<8; i++) { // winCombination[i][j]
		playerSignCnt = comSignCnt = blankPosition = 0;

		// fill targetSet 
		for (j=0; j<3; j++) {
			targetSet[j] = getBoard(winCombination[i][j]);
			if (targetSet[j] == playerSign) playerSignCnt++;
			else if (targetSet[j] == comSign) comSignCnt++;
			else blankPosition = winCombination[i][j];
		}

		if (comSignCnt == 2 && playerSignCnt == 0) {
			return blankPosition;
		}

		if (pickForBlock != 0 && playerSignCnt == 2 && comSignCnt == 0) {
			pickForBlock = blankPosition;
		}
	}

	// Execute Rule 2
	if (pickForBlock != 0) return pickForBlock;

	// Rule 3: 7, 3, 1, 9
	int cornerOrder[4] = {7, 3, 1, 9};
	for (i=0; i<4; i++) {
		if (getBoard(cornerOrder[i]) == ' ') {
			return cornerOrder[i];
		}
	}

	// Rule 4
	if (getBoard(5) == ' ') {
		return 5;
	}

	// Rule 5
	int sideSpaceOrder[4] = {8, 2, 4, 6};
	for (i=0; i<4; i++) {
		if (getBoard(sideSpaceOrder[i]) == ' ') {
			return sideSpaceOrder[i];
		}
	}

	return 0;
}

// 0 = nobody, 1 = com, 2 = player
int winCheck() {
	int i, j;
	int comSignCnt, playerSignCnt;
	char positionValue;

	for (i=0; i<8; i++) { // winCombination[i][j]
		playerSignCnt = comSignCnt = 0;
		positionValue = ' ';

		for (j=0; j<3; j++) {
			positionValue = getBoard(winCombination[i][j]);
			if (positionValue == playerSign) playerSignCnt++;
			else if (positionValue == comSign) comSignCnt++;
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
