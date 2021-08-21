#include<stdio.h>
void addInitial(int[*][*], int, int, int);
void Display(int[*][*]);
void CreateSudokuPuzzle(int[*][*], int, int);
int checkrow(int[][9], int, int);
int checkcol(int[][9], int, int);
int checksquare(int[][9], int, int, int);
int isFull(int[][9], int, int);
void addGuess(int [][9], int, int, int);
int checkPuzzle(int,int,int,int [][9]);
int main(){
        char again;
        do{
        int done = 1;
        int board[9][9];
        CreateSudokuPuzzle(board, 9, 9);
        addInitial(board, 0, 0, 1);
        addInitial(board, 0, 1, 2);
        addInitial(board, 0, 2, 3);
        addInitial(board, 0, 3, 4);
        addInitial(board, 0, 4, 9);
        addInitial(board, 0, 5, 7);
        addInitial(board, 0, 6, 8);
        addInitial(board, 0, 7, 6);
        addInitial(board, 0, 8, 5);
        addInitial(board, 1, 0, 4);
        addInitial(board, 1, 1, 5);
        addInitial(board, 1, 2, 9);
        addInitial(board, 2, 0, 6);
        addInitial(board, 2, 1, 7);
        addInitial(board, 2, 2, 8);
        addInitial(board, 3, 0, 3);
        addInitial(board, 3, 4, 1);
        addInitial(board, 4, 0, 2);
        addInitial(board, 5, 0, 9);
        addInitial(board, 6, 0, 8);
        addInitial(board, 7, 0, 7);
        addInitial(board, 8, 0, 5);
        addInitial(board, 5, 5, 5);
        addInitial(board, 8, 3, 9);
                while(!isFull(board, 9, 9)){
                        Display(board);
                        int valid;
                        int row, col, value;
                        printf("Enter the number of rows: ");
                        scanf("%d", &row);
                        getchar();
                        printf("Enter the number of columns: ");
                        scanf("%d", &col);
                        getchar();
                        printf("Enter the value: ");
                        scanf("%d", &value);
                        getchar();
                        valid = checkPuzzle(row, col, value, board);
                        if(valid != 1){
                                printf("Violation! take another move.\n");
                                continue;
                        }
                        addGuess(board, row, col, value);
                }
        printf("Congratulations! Mission Complete!\n");
        Display(board);
		printf("Do you wannt another game? Enter(y/n)");
        scanf("%c", &again);
        getchar();
        }while(again == 'y');
        return 0;
}
void CreateSudokuPuzzle(int board[][9], int row, int col){
        int i, j;
        for(i = 0; i < row; i++){
                for(j = 0; j < col; j++){
                        board[i][j] = 0;
                }
        }
}
void addInitial(int board[][9], int row, int col, int value){

            board[row][col] = value;
}
void Display(int board[][9]){
        int i, j;

        for(i = 0; i < 9; i++){
                for(j = 0; j < 9; j++){
                        printf(" [%d] ", board[i][j]);
                }
                printf("\n\n");
        }
}
int checkPuzzle(int row, int col, int value, int board[][9]){
        // fixed values
        if((row == 1) || (col == 1) || (row <= 3 && col <= 3) || (row == 4 && col == 5) || (row == 6 && col == 6) || (row == 9 && col == 4)){
              return 0;
        }
   

        if(checkrow(board, row, value)&& checkcol(board,col, value)&& checksquare(board, row, col, value)){
                return 1;
        }
        return 0;
}
int checkrow(int board[][9], int row, int value){
        int j;
        for(j = 0; j < 9; j++){
                if(value == board[row-1][j]){
                        return 0;
                }
        }
        return 1;
}
int checkcol(int board[][9], int col, int value){
        int i;
        for(i = 0; i < 9; i++){
                if(value == board[i][col-1]){
                        return 0;
                }
        }
        return 1;
}
int checksquare(int board[][9], int row, int col, int value){
        int i, j;
        int startrow = 3*((row-1)/3);
        int startcol = 3*((col-1)/3);
        for(i = startrow; i < startrow + 3; i++){
                for(j = startcol; j < startcol + 3; j++){
                        if(value == board[i][j]){
                                return 0;
                        }
                }
        }
        return 1;
}
int isFull(int board[][9], int row, int col){
        int check = 1;
        int i, j;
        for(i = 0; i < row; i++){
                for(j = 0; j < col; j++){
                        if(board[i][j] == 0){
                            check = 0;
                        }
                }
        }
        return check;
}
void addGuess(int board[][9], int row, int col, int value){
        board[row-1][col-1] = value;
}


                                                              
                                                                                                       

