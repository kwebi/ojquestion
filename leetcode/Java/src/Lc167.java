public class Lc167 {
    public int[] twoSum(int[] numbers, int target) {
        int[] ans = new int[2];
        int end = numbers.length - 1;
        int begin = 0;
        while (end > begin) {
            int sum = numbers[end] + numbers[begin];
            if (sum > target) {
                end--;
            } else if (sum < target){
                begin++;
            } else {
                break;
            }
        }
        ans[0] = begin+1;
        ans[1] = end+1;
        return ans;
    }
}
