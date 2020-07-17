import java.util.ArrayList;
import java.util.List;

public class Lc1513 {
    public static void main(String[] args) {
        Lc1513 lc1513 = new Lc1513();
        lc1513.numSub("0110111");
    }

    public int numSub(String s) {
        long ans = 0;
        List<Long> list = new ArrayList<>();
        long cnt = 0L;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '1') {
                if (cnt != 0) {
                    list.add(cnt);
                    // System.out.println(cnt);
                    cnt = 0L;
                }
            } else {
                cnt++;
            }
        }
        if (cnt != 0)
            list.add(cnt);
        long mod = (long) (1e9 + 7);
        for (int i = 0; i < list.size(); i++) {
            long r = (list.get(i) * (list.get(i) + 1) / 2L) % mod;
            ans += r;
        }
        // System.out.println(ans);
        return (int) ans;
    }
}