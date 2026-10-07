int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        // Binary search for the target
        if(nums[mid] == target){
            return mid;
        }

        // Check if the left half is sorted
        else if(nums[left] <= nums[mid]){

            // Check if target is in the left sorted half
            if(target < nums[mid] && target >= nums[left])
                right = mid - 1;
            else
                left = mid + 1;
        }

        // Otherwise, the right half is sorted
        else{

            // Check if target is in the right sorted half
            if(target <= nums[right] && target > nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}