/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool isSafe(int board[],int row,int col,int n){
    for(int i=0;i<row;i++){
        int qCol=board[i];
        if(col==qCol)return false;
        if(abs(col-qCol)==abs(row-i))return false;
    }
    return true;
}

void backtrack(int n,char***result, int* returnSize, int** returnColumnSizes,int row,int board[]){
    if(row==n){
        result[*returnSize]=malloc(sizeof(char*)*(n));
        (*returnColumnSizes)[*returnSize]=n;
        for(int i=0;i<n;i++){
            result[*returnSize][i]=malloc(sizeof(char)*(n+1));
            for(int j=0;j<n;j++){
                if(board[i]==j){
                    result[*returnSize][i][j]='Q';
                }
                else{
                    result[*returnSize][i][j]='.';
                }
                if(j==n-1){
                    result[*returnSize][i][j+1]='\0';
                }
            }
        }
        (*returnSize)++;
    }
    for(int col=0;col<n;col++){
        if(isSafe(board,row,col,n)){
            board[row]=col;
            backtrack(n,result,returnSize,returnColumnSizes,row+1,board);
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    char ***result=malloc(sizeof(char**)*400);
    *returnColumnSizes=malloc(sizeof(int)*400);
    *returnSize=0;
    int board[10];
    backtrack(n,result,returnSize,returnColumnSizes,0,board);
    return result;
}