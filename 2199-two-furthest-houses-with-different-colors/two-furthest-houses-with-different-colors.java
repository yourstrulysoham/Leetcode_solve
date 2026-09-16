class Solution {
    public int maxDistance(int[] colors) {
        int i , count=0 , j=colors.length-1 , dif=1 ;
        for(i=1;i<colors.length;i++){
            if(colors[colors.length-1]!=colors[i]){
                dif = colors.length-i-1;
                count++;
            }
            if(colors[0]!=colors[j]){
                dif = j;
                count++;
            }
            if(count>0) break;
            j--;
        }
        return dif;
    }
}