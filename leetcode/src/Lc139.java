import java.util.Arrays;
import java.util.List;

public class Lc139 {
    public boolean wordBreak(String s, List<String> wordDict) {
        int m = s.length();
        boolean[] dp = new boolean[m+1];
//        for (int i=0;i<=m;i++) {
//            dp[i] = false;
//        }
        dp[0] = true;
        for (int i=1;i<=m;i++) {
            for (int j=0;j<i;j++) {
                if (dp[i - j-1] == true) {
                    if (exit(s.substring(i-j-1, i), wordDict)) {
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[m];
    }
    public boolean exit(String s, List<String> wordDict) {
        boolean f = false;
        for (String s1: wordDict) {
            if (s1.equals(s)) {
                f = true;
                break;
            }
        }
        return f;
    }

    public static void main(String[] args) {
        System.out.println(new Lc139().wordBreak("leetacode", Arrays.asList("leet", "code")));
    }
}
