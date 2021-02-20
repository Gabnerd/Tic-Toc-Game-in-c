#include "game.h"
	
int main(){
	while(runGame){
		renderBoard();
		input();
		clear();
		checkWinner();
	}
	return 0;
}
