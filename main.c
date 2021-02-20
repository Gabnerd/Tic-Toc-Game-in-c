#include "game.h"
	
int main(){
	while(runGame){
		renderBoard();
		input();
		checkWinner();
	}
	return 0;
}
