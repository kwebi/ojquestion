import java.util.ArrayList;
import java.util.List;

public class Lc96 {
    public int numTrees(int n) {
        //定义 a[i] 为以 [1; i] 能产生的 Unique Binary Search Tree 的数目
        List<Integer> a = new ArrayList(n+1);
        for (int i=0;i<=n;i++) {
            a.add(0);
        }
        a.set(0,1);
        a.set(1,1);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                a.set(i, a.get(i)+a.get(j-1)*a.get(i-j));
            }
        }
        return a.get(n);
    }
    public static void main(String[] args) {
        Lc96 o = new Lc96();
        System.out.println(o.numTrees(3));
    }
}
