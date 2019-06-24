import java.math.BigInteger;
import java.util.Scanner;

public class P2142 {
    public static void main(String []args) {
        Scanner cin=new Scanner(System.in);
        BigInteger c;
        BigInteger d;
        c=cin.nextBigInteger();
        d=cin.nextBigInteger();
        c=c.subtract(d);
        System.out.println(c);
        cin.close();
    }
}
