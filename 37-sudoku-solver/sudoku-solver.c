bool isSafe(char **board,int row,int col,int num){
    for(int i=0;i<9;i++){
        if(board[row][i]==num) return false;
        if(board[i][col]==num) return false;

        int gridR=3*(row/3)+i/3;
        int gridC=3*(col/3)+i%3;
        if(board[gridR][gridC]==num)return false;
    }
    return true;
}

bool solve(char** board){
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            if(board[row][col]=='.'){
                for(char num='1';num<='9';num++){
                    if(isSafe(board,row,col,num)){
                        board[row][col]=num;
                        if(solve(board)){
                            return true;
                        }
                        board[row][col]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board);
}