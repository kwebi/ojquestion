import java.io.*;
import java.util.*;
import java.math.*;

public class poj3181 {
    public static void main(String[] args) {
        InputReader in = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
        Solve s=new Solve();
        s.solve(in,out);
        out.close();
    }
    static class Solve{
        public void solve(InputReader in,PrintWriter out){
            int n,k;
            n=in.nextInt();
            k=in.nextInt();
            BigInteger f[] = new BigInteger[n+10];
            f[0]=new BigInteger("1");
            for(int i=1;i<=n;i++){
                f[i] = new BigInteger("0");
                //out.println(0);
            }
            for(int i=1;i<=k;i++){
                for(int j=i;j<=n;j++){
                    f[j]=f[j].add(f[j-i]);
                    //cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
                }
            }
            out.println(f[n]);
        }
    }
}

class InputReader {
    BufferedReader buf;
    StringTokenizer tok;
    InputReader() {
        buf = new BufferedReader(new InputStreamReader(System.in));
    }
    boolean hasNext() {
        while (tok == null || !tok.hasMoreElements()) {
            try {
                tok = new StringTokenizer(buf.readLine());
            } catch (Exception e) {
                return false;
            }
        }
        return true;
    }
    String next() {
        if (hasNext())
            return tok.nextToken();
        return null;
    }
    int nextInt() {
        return Integer.parseInt(next());
    }
    long nextLong() {
        return Long.parseLong(next());
    }
    double nextDouble() {
        return Double.parseDouble(next());
    }
    BigInteger nextBigInteger() {
        return new BigInteger(next());
    }
    BigDecimal nextBigDecimal() {
        return new BigDecimal(next());
    }
}
