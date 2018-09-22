public class Lc35 {
    public int searchInsert(int[] nums, int target) {
        return binarySearch(nums,target,0,nums.length-1);
    }
    private int binarySearch(int[] nums, int target, int left, int right) {
        // TODO Auto-generated method stub
        if(left > right)
            return -1;
        if(left == right){
            if(nums[left] >= target){
                return left;
            }else{
                return right+1;
            }
        }
        int mid = (left + right)/2;
        if(target < nums[mid]){
            return binarySearch(nums,target,left,mid);
        }else if(target == nums[mid]){
            return mid;
        }else{
            return binarySearch(nums,target,mid+1,right);
        }
    }
}
