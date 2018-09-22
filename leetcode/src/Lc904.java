import java.util.ArrayList;
import java.util.List;

public class Lc904 {
    public int totalFruit(int[] tree) {
        int m = tree.length;
        int ans = 0;
        for (int i=0; i<tree.length; i++) {
            int b1 = tree[i];
            int b2 = -1;
            int total = 1;
            if (ans >= m) {
                break;
            }
            m--;
            for (int j=i+1; j<tree.length; j++) {
                int f = tree[j];
                if (f == b1) {
                    total++;
                    continue;
                }
                if (b2 == -1) {
                    b2 = f;
                    total++;
                }
                else {
                    if (f == b2) {
                        total++;
                    }
                    else {
                        break;
                    }
                }
            }
            ans = Math.max(ans, total);
        }
        return ans;
    }
    public static void main(String[] args) {
        System.out.println(new Lc904().totalFruit(new int[] {1,2,1}));
    }
}

