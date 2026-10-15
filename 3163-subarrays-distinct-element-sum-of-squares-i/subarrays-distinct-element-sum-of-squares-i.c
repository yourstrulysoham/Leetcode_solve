int sumCounts(int* nums, int numsSize){
    int sum = 0;

    for(int i=1;i<=numsSize;i++){
        for(int j=0;j<=numsSize-i;j++){
            int cnt = 0;
            int hash[101] = {0};
            for(int k=0;k<i;k++){
                hash[nums[j+k]]++;
            }

            for(int k=0;k<101;k++){
                if(hash[k]>0){
                    cnt++;
                    hash[k] = 0;
                }
                
            }
            sum += (cnt*cnt);
        }
    }
    return sum;
}