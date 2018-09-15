import java.util.HashMap;

public class Lc731 {
    private HashMap hashMap = new HashMap();
    public Lc731() {

    }
    public boolean book(int start, int end) {
        boolean ans = true;
        if (hashMap.isEmpty()) {
            for (int i = start; i < end; i++) {
                hashMap.put(i,0);
            }
        } else {
            for (int i = start; i < end; i++) {
                if (!hashMap.containsKey(i)) {
                    hashMap.put(i,0);
                } else {
                    if ((int)hashMap.get(i) >= 2) {
                        ans = false;
                        break;
                    }
                }
            }
        }
        if (ans) {
            for (int i = start; i < end; i++) {
                int v = (int)hashMap.get(i);
                hashMap.replace(i, v+1);
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        Lc731 o = new Lc731();
        System.out.println(o.book(10,20));
        System.out.println(o.book(50,60));
        System.out.println(o.book(10,40));
        System.out.println(o.book(5,15));
        System.out.println(o.book(15,40));
    }
}
