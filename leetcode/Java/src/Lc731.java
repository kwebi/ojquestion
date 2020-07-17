import java.util.ArrayList;
import java.util.List;

public class Lc731 {
    public Lc731() {
        calendar = new ArrayList();
        overlaps = new ArrayList();
    }
    List<int[]> calendar;
    List<int[]> overlaps;

    public boolean book(int start, int end) {
        for (int[] iv: overlaps) {
            if (iv[0] < end && start < iv[1]) return false;
        }
        for (int[] iv: calendar) {
            if (iv[0] < end && start < iv[1])
                overlaps.add(new int[]{Math.max(start, iv[0]), Math.min(end, iv[1])});
        }
        calendar.add(new int[]{start, end});
        return true;
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
