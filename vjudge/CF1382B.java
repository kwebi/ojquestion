import java.util.*;

public class CF1382B {
    public static void main(String[] args) {
        SolveCF1382B s = new SolveCF1382B();
        s.solve();
    }
}

class SolveCF1382B {
    private Scanner sc = new Scanner(System.in);

    public void solve() {
        int T = sc.nextInt();
        while (T > 0) {
            int n = sc.nextInt();
            int[] a = new int[n + 10];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            int j = 0;
            boolean fg = false;
            for (j = 0; j < n; j++) {
                if (a[j] > 1) {
                    if (j % 2 == 0) {
                        System.out.println("First");
                    } else {
                        System.out.println("Second");
                    }
                    fg = true;
                    break;
                }
            }
            if (!fg) {
                if (n % 2 == 0) {
                    System.out.println("Second");
                } else {
                    System.out.println("First");
                }
            }
            T--;
        }
    }
}