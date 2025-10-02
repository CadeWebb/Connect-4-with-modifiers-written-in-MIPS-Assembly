#include <stdio.h>
#define M 6
#define N 7

void printGame(int gameSpace[M][N]) {
    int i;
    int j;
    printf("\n");
    for(i=0;i<M;++i){
        for(j=0;j<N;++j) {
            if (gameSpace[i][j]==1) {
                printf("1 ");
            }
            else if(gameSpace[i][j]==2){
                printf("2 ");
            }
            else
            printf("0 ");
        }
        printf("\n");
    }
    printf("\n");
}

int playChip(int chipChoice, int gameCount, int gameSpace[M][N]) {
    int funcChipChoice = chipChoice - 1; //makes choice array friendly 
    int i=5;
    if ((funcChipChoice > -1) && (funcChipChoice < 7)) {
        if (gameCount%2 == 0) { // places chips for player1
            for (i=5;i>=0;--i) {
                if (gameSpace[i][funcChipChoice]==0) {
                    gameSpace[i][funcChipChoice] = 1;
                    //i = row;
                    //col = funcChipChoice;
                    //winVar = checkWin(col, row, gameSpace);
                    return i;
                }
            }
            return -1;
        }
        
        else if (gameCount%2 == 1) {// places chips for player2
            for (i=5;i>=0;--i) {
                if (gameSpace[i][funcChipChoice]==0) {
                        gameSpace[i][funcChipChoice] = 2;
                        //i = row;
                        //col = funcChipChoice;
                        //winVar = checkWin(col, row, gameSpace);
                        return i;
                    }
            }
            return -1;
        }
    }
    return -1;
}

int winCheckFunction (int i, int playerColumn, int gameSpace[M][N]) {
    int row;
    row = i;
    int col;
    col = playerColumn-1;
    //printf("Row is %d, col is %d", row+1, col+1);
    if (gameSpace[row][col] == 1) {
        if ((row+1 < 6) && (gameSpace[row+1][col] == 1)) { // DOWN
            if ((row+2 < 6) && (gameSpace[row+2][col] == 1)) { // DOWN
               if ((row+3 < 6) && (gameSpace[row+3][col] == 1)) { // DOWN
                   return 0;
               } // DOWN
            } // DOWN
        } // DOWN
        
        if ((col-1 > -1) && (gameSpace[i][col-1] == 1)) { // LEFT
            if ((col-2 > -1) && (gameSpace[i][col-2] == 1)) {
                if ((col-3 > -1) && (gameSpace[i][col-3] == 1)) {
                    return 0;
                }
            }
        }
        if ((col+1 < 7) && (gameSpace[i][col+1] == 1)) { // RIGHT
            if ((col+2 < 7) && (gameSpace[i][col+2] == 1)) {
                if ((col+3 < 7) && (gameSpace[i][col+3] == 1)) {
                    return 0;
                }
            }
        }
        if ((row-1>-1) && (col+1 < 7) && (gameSpace[i-1][col+1] == 1)) { // diagonal right-up
            if ((row-2>-1) && (col+2 < 7) && (gameSpace[i-2][col+2] == 1)) {
                if ((row-3>-1) && (col+3 < 7) && (gameSpace[i-3][col+3] == 1)) {
                    return 0;
                }
            }
        }
        if ((row-1>-1) && (col-1 > -1) && (gameSpace[i-1][col-1] == 1)) {// diagonal left-up
            if ((row-2>-1) && (col-2 > -1) && (gameSpace[i-2][col-2] == 1)) {
                if ((row-3>-1) && (col-3 > -1) && (gameSpace[i-3][col-3] == 1)) {
                    return 0;
                }
            }
        }
        if ((row+1<6) && (col+1 < 7) && (gameSpace[i+1][col+1] == 1)) {// diagonal right-down
            if ((row+2<6) && (col+2 < 7) && (gameSpace[i+2][col+2] == 1)) {
                if ((row+3<6) && (col+3 < 7) && (gameSpace[i+3][col+3] == 1)) {
                    return 0;
                }
            }
        }
        if ((row+1<6) && (col-1 > -1) && (gameSpace[i+1][col-1] == 1)) {// diagonal left down
            if ((row+2<6) && (col-2 > -1) && (gameSpace[i+2][col-2] == 1)) {
                if ((row+3<6) && (col-3 > -1) && (gameSpace[i+3][col-3] == 1)) {
                    return 0;
                }
            }
        }
        
    }   
    else if (gameSpace[i][col] == 2) {
        if ((i+1 < 6) && (gameSpace[i+1][col] == 2)) { // DOWN
            if ((i+2 < 6) && (gameSpace[i+2][col] == 2)) { // DOWN
               if ((i+3 < 6) && (gameSpace[i+3][col] == 2)) { // DOWN
                   return 0;
               } // DOWN
            } // DOWN
        } // DOWN
        
        if ((col-1 > -1) && (gameSpace[i][col-1] == 2)) { // LEFT
            if ((col-2 > -1) && (gameSpace[i][col-2] == 2)) {
                if ((col-3 > -1) && (gameSpace[i][col-3] == 2)) {
                    return 0;
                }
            }
        }
        if ((col+1 < 7) && (gameSpace[i][col+1] == 2)) { // RIGHT
            if ((col+2 < 7) && (gameSpace[i][col+2] == 2)) {
                if ((col+3 < 7) && (gameSpace[i][col+3] == 2)) {
                    return 0;
                }
            }
        }
        if ((row-1>-1) && (col+1 < 7) && (gameSpace[i-1][col+1] == 2)) { // diagonal right-up
            if ((row-2>-1) && (col+2 < 7) && (gameSpace[i-2][col+2] == 2)) {
                if ((row-3>-1) && (col+3 < 7) && (gameSpace[i-3][col+3] == 2)) {
                    return 0;
                }
            }
        }
        if ((row-1>-1) && (col-1 > -1) && (gameSpace[i-1][col-1] == 2)) {// diagonal left-up
            if ((row-2>-1) && (col-2 > -1) && (gameSpace[i-2][col-2] == 2)) {
                if ((row-3>-1) && (col-3 > -1) && (gameSpace[i-3][col-3] == 2)) {
                    return 0;
                }
            }
        }
        if ((row+1<6) && (col+1 < 7) && (gameSpace[i+1][col+1] == 2)) {// diagonal right-down
            if ((row+2<6) && (col+2 < 7) && (gameSpace[i+2][col+2] == 2)) {
                if ((row+3<6) && (col+3 < 7) && (gameSpace[i+3][col+3] == 2)) {
                    return 0;
                }
            }
        }
        if ((row+1<6) && (col-1 > -1) && (gameSpace[i+1][col-1] == 2)) {// diagonal left down
            if ((row+2<6) && (col-2 > -1) && (gameSpace[i+2][col-2] == 2)) {
                if ((row+3<6) && (col-3 > -1) && (gameSpace[i+3][col-3] == 2)) {
                    return 0;
                }
            }
        }
    }
    
        return 1;
}

int main()
{
    printf("Welcome to Connect-4!\n");
    int gameSpace[6][7] = {0};
    // player 1 will assign 1's to their spots and player 2 will get 2's

    int gameCount = 0; //if even player 1, odd player 2
    int chipChoice = 0; // players's column choice
    int powerup1 = 0; //counts for power-ups
    int powerup2 = 0;
    int winVar = 1; //while equals 1 while loop runs, if set to 0 by the wincheck function, then while loop ends
    int test = 69;
    printGame(gameSpace);
    while(winVar) {
            printf("Player one, please select a column to play(1-7)\n");
    	    scanf("%d", &chipChoice);
    	    test = playChip(chipChoice, gameCount, gameSpace);
    	    //printf("%d test\n", test);
    	    while (test == -1) {
    	        test = 0;
    	        printf("Please enter a valid column.\n");
    	        scanf("%d", &chipChoice);
    	        test = playChip(chipChoice, gameCount, gameSpace);
    	    } 
    	    printGame(gameSpace);
    	    winVar = winCheckFunction(test, chipChoice, gameSpace);
    	    //printf("\n%d winVar is this\n", winVar);
    	    ++gameCount;
    	    ++powerup1;
            
            
            if (winVar == 1) {
                chipChoice = 0;
                printf("Player two, please select a column to play(1-7)\n");
        	    scanf("%d", &chipChoice);
        	    test = playChip(chipChoice, gameCount, gameSpace);
        	    while (test == -1) {
        	        test = 0;
        	        printf("Please enter a valid column.\n");
        	        scanf("%d", &chipChoice);
        	        test = playChip(chipChoice, gameCount, gameSpace);
        	    } 
        	    printGame(gameSpace);
        	    winVar = winCheckFunction(test, chipChoice, gameSpace);
        	    //printf("\n%d winVar is this\n", winVar);
        	    ++gameCount;
        	    ++powerup2;
        	    
            }
            
            if (gameCount > 25) { //set to max chips that can be played so it auto stops and do if-state to tell if it stopped this way and say draw
                 winVar = 0;
            }
    }
    
    if (gameCount % 2) {
        printf("Player 1 Wins\n");
    }
    else {
        printf("Player 2 Wins\n");
    }
    return 0;
}
