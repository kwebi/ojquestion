import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Lc731 {
    private static List<int[]> singleBlockedTimes;
    private static List<int[]> doubleBlockedTimes;
    public Lc731() {
        singleBlockedTimes = new ArrayList();
        doubleBlockedTimes = new ArrayList();
    }
    private static void addAndUpdate(int[] input, List<int[]> singleBlockedTimes, List<int[]> doubleBlockedTimes) {
        // pick our intervals that overlaps with input
        List<int[]> conflicts = new ArrayList();
        for (int[] interval : singleBlockedTimes) {
            if (interval[1] <= input[0] || interval[0] >= input[1]) {
                continue;
            } else {
                conflicts.add(interval);
            }
        }

        // no conflict, no work to do
        if (conflicts.size() == 0) {
            singleBlockedTimes.add(input);
            return;
        }

        // merge and update both lists
        List<int[]> allTimes = new ArrayList<>(conflicts);
        allTimes.add(input);
        Collections.sort(allTimes, new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });

        int[] pre = allTimes.get(0);
        for (int i = 1; i < allTimes.size(); i++) {
            int[] cur = allTimes.get(i);
            if (cur[0] >= pre[1]) {
                pre = cur;
                continue;
            } else if (cur[1] > pre[1]) {
                singleBlockedTimes.add(new int[]{pre[0], cur[0]});
                doubleBlockedTimes.add(new int[]{cur[0], pre[1]});
                pre = new int[]{pre[1], cur[1]};
            } else {
                singleBlockedTimes.add(new int[]{pre[0], cur[0]});
                doubleBlockedTimes.add(new int[]{cur[0], cur[1]});
                //singleBlockedTimes.add(new int[]{cur[1], pre[1]});
                pre = new int[]{cur[1], pre[1]};
            }
        }
        singleBlockedTimes.add(pre);

        for (int[] interval : conflicts) {
            singleBlockedTimes.remove(interval);
        }
    }

    public static boolean book(int start, int end) {
        for (int i = 0; i < doubleBlockedTimes.size(); i++) {
            int[] cur = doubleBlockedTimes.get(i);

            if (cur[1] <= start || cur[0] >= end) {
                continue;
            } else {
                return false;
            }
        }
        addAndUpdate(new int[]{start, end}, singleBlockedTimes, doubleBlockedTimes);
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
