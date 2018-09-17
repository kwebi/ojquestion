import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Lc120 {
    public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle == null || triangle.size() == 0) return 0;
        int triszie = triangle.size();
        int[] dp = new int[triszie];

        for(int i = triszie - 1; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                if(i == triszie - 1) dp[j] = triangle.get(i).get(j);
                else dp[j] = Math.min(dp[j],dp[j+1]) + triangle.get(i).get(j);
            }
        }
        return dp[0];
    }
    public static void main(String[] args) {
        List<List<Integer>> a = new ArrayList<>(4);
        List<Integer> b0 = new ArrayList<>();
        b0.add(-1);
        a.add(b0);
        List<Integer> b1 = new ArrayList<>(Arrays.asList(3,2));
        a.add(b1);
        List<Integer> b2 = new ArrayList<>(Arrays.asList(1,-2,-1));
        a.add(b2);
        List<Integer> b3 = new ArrayList<>(Arrays.asList(4,1,8,3));
       // a.add(b3);
        System.out.println(new Lc120().minimumTotal(a));
    }
}