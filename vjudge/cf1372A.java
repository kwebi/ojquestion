import java.util.Scanner;

public class cf1372A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while (T > 0) {
            int n = in.nextInt();
            for (int i = 0; i < n; i++) {
                System.out.printf("%d ", i % 2 == 0 ? i + 1 : i);
            }
            System.out.println();
            T--;
        }
        in.close();
    }
}