import java.util.ArrayList;
import java.util.List;

public class Lc91 {
    public int numDecodings(String s) {
        int n = s.length();
        List<Integer> chars = new ArrayList<>(n+1);
        List<Integer> arr = new ArrayList<>(n+1);
        List<Boolean> flag = new ArrayList<>(n+1);

        for (int i = 0; i< n; i++) {
            chars.add(0,Integer.parseInt(s.substring(i,i+1)));
            flag.add(true);
        }
        if (chars.get(n-1)==0) {
            return 0;
        }
        if (chars.get(0) == 0) {
            arr.add(0);
        } else {
            arr.add(1);
        }
        for (int i=1;i<n;i++) {
            arr.add(0);
            int sum = chars.get(i)*10+chars.get(i-1);
            if (sum ==0) {
                return 0;
            }
            if (chars.get(i) != 0) {
                if (sum<=26 && sum > 0 ) {
                    if ( chars.get(i-1) != 0 ) {
                        if ( flag.get(i-1)) {
                            if (i >= 2) {
                                arr.set(i, arr.get(i - 1) + arr.get(i - 2));
                            } else {
                                arr.set(i, arr.get(i - 1) + 1);
                            }
                        } else {
                            arr.set(i, arr.get(i-1));
                        }
                    } else {
                        flag.set(i,false);
                        if (i==1) {
                            arr.set(i, 1);
                        } else {
                            arr.set(i, arr.get(i - 1));
                        }
                    }
                    continue;
                }
            }
            if (sum > 26 && chars.get(i-1)==0) {
                return 0;
            }
            arr.set(i,arr.get(i-1));
        }
        return arr.get(n-1);
    }
    public static void main(String[] args) {
        System.out.println(new Lc91().numDecodings("1212"));
    }
}
