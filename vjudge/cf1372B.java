import java.util.Scanner;

public class cf1372B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while (T > 0) {
            int n = in.nextInt();
            int m = n;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    m = i;
                    break;
                }
            }

            int t = n / m;
            System.out.printf("%d %d\n", t, n - t);
            T--;
        }
        in.close();
    }
}