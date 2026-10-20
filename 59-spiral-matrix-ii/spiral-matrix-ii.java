class Solution {
    public int[][] generateMatrix(int n) {
        int arr[][]=new int[n][n];
        int num=1,sr=0,sc=0,er=n-1,ec=n-1;
        while(sr<=er&&sc<=ec){
            // starting row
            for(int j=sc;j<=ec;j++){
                arr[sr][j]=num;
                num++;
            }
            sr++;
            // ending colum
            for(int i=sr;i<=er;i++){
                arr[i][ec]=num;
                num++;
            }
            ec--;
            if(sr<=er){
            //ending row
            for(int j=ec;j>=sc;j--){
                arr[er][j]=num;
                num++;
            }
            er--;
            }
            //starting column
            if(sc<=ec){
            for(int i=er;i>=sr;i--){
                arr[i][sc]=num;
                num++;
            }
            sc++;
            }
        }
        return arr;
    }
}