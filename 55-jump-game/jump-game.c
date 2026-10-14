bool canJump(int* nums, int numsSize) {
    if(numsSize==1){
        return 1;
    }
    for(int i=0;i<numsSize;i++){
        nums[i]+=i;
    }
    int max_idx = nums[0];
    int idx = 1;
    while(idx<=max_idx){
        if(nums[idx]>max_idx){
            max_idx=nums[idx];
        }
        if(max_idx>=numsSize-1){
            return 1;
        }
        idx++;
    }
    return 0;
}