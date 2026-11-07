class Solution {
    
    public int divc(int []nums, int target, int lo, int hi){
        
        if(lo > hi) return 0;
        
        int mid = lo +(hi -lo)/2;
        if(nums[mid] > nums[mid+1]){
            return mid+1;
        }else if(nums[lo] == nums[hi]){
            int a = divc(nums,target,lo,mid-1);
            int b = divc(nums,target,mid+1,hi);
            return b != 0 ? b : a;
        }else if(nums[lo] > nums[mid] ){
            return divc(nums,target,lo,mid-1);
        }else{  
            return divc(nums,target,mid+1,hi);
        }
        
    }
    public boolean search(int[] nums, int target) {
       // Arrays.sort(nums); //nlogn
        
        
        int n = nums.length;
        int lo =0;
        int hi = n-2;
        
        int pivot =divc(nums, target, lo, hi);
        var a = Arrays.binarySearch(nums, 0, pivot,target); // logn
        var b = Arrays.binarySearch(nums,pivot, n,target); // logn
        
        //System.out.println(a+" "+b+" "+pivot);
        if( a < 0 && b < 0) return false;
        return true;
    }
}