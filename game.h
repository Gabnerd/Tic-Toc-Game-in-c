#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define clear() printf("\033[H\033[J")
#define width 3
#define height 3

int board[width][height] = {{0,0,0}, {0,0,0}, {0,0,0}};

int roundGame = 0;
bool runGame = true;

void renderBoard(){
	for(int j = 0; j < width; j++){
		if(j != 0){
			printf("   %d", j+1);
		}else{
			printf("    %d",j+1);
		}
	}
	printf("\n");
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(j == 0){
				printf("  +---");
			}else{
				printf("+---");
			}
			if(j == (width-1)){
				printf("+\n");
			}
		}
		for(int j = 0; j < width; j++){
			if(j == 0){
				printf("%c ", i+65);
			}
			if(board[i][j] == 0){
				printf("|   ");
			}else if(board[i][j] == 1){
				printf("| X ");
			}else if(board[i][j] == 2){
				printf("| O ");
			}

			if(j == (width-1)){
				printf("|\n");
			}
		}
		if(i == (width-1)){
			for(int j = 0; j < width; j++){
				if(j == 0){
					printf("  +---");
				}else{
					printf("+---");
				}
				if(j == 2){
					printf("+\n");
				}
			}
		}
	}
}

void input(){
	int player = (roundGame%2)+1;
	char cord[2];
	printf("P%d>",player);
	scanf("%s", &cord);
	int cordLetra = cord[0] - 65;
	if(cord[0] != 'q' && board[cordLetra][atoi(&cord[1])-1] == 0){
		player = (roundGame%2)+1;
		board[cordLetra][atoi(&cord[1])-1] = player;
		roundGame++;
	}else if(cord[0] == 'q'){
		runGame = false;
	}
}

void checkWinner(){
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0){
		printf("player %d ganhou\n", board[0][0]);
		runGame = false;
	}else if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != 0){
		printf("player %d ganhou\n", board[0][0]);
		runGame = false;
	}else if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != 0){
		printf("player %d ganhou\n", board[1][0]);
		runGame = false;
	}else if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != 0){
		printf("player %d ganhou\n", board[2][0]);
		runGame = false;
	}else if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != 0){
		printf("player %d ganhou\n", board[0][0]);
		runGame = false;
	}else if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != 0){
		printf("player %d ganhou\n", board[0][1]);
		runGame = false;
	}else if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != 0){
		printf("player %d ganhou\n", board[0][2]);
		runGame = false;
	}else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0){
		printf("player %d ganhou\n", board[0][2]);
		runGame = false;
	}
}
