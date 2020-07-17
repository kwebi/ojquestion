import java.util.*;

public class Lc1512 {
    public static void main(String[] args) {
        int[] arr = new int[]{ 1, 1, 1, 1};
        Lc1512 lc1512 = new Lc1512();
        lc1512.numIdenticalPairs(arr);
    }

    public int numIdenticalPairs(int[] nums) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (map.get(nums[i]) != null)
                map.put(nums[i], map.get(nums[i]) + 1);
            else
                map.put(nums[i],1);
        }
        Set<Integer> set = map.keySet();
        int ans = 0;
        for (int k : set) {
            int r = map.get(k);
            ans += r * (r - 1) / 2;
        }
        return ans;
    }
}