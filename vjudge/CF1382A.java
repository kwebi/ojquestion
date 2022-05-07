import java.util.*;

public class CF1382A {

    public static void main(String[] args) {
        Solve s = new Solve();
        s.solve();
    }
}

class Solve {
    private Scanner sc = new Scanner(System.in);

    public void solve() {
        int T = sc.nextInt();
        while (T > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] a = new int[n + 10];
            int[] b = new int[m + 10];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            for (int i = 0; i < m; i++) {
                b[i] = sc.nextInt();
            }
            boolean fg = false;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i] == b[j]) {
                        System.out.printf("YES\n");
                        System.out.printf("%d %d\n", 1, a[i]);
                        fg = true;
                        break;
                    }
                }
                if (fg)
                    break;
            }
            if (!fg)
                System.out.println("NO");
            T--;
        }
    }
}