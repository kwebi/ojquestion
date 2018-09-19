import java.util.Arrays;
import java.util.List;

public class Lc841 {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {

        int N = rooms.size();
        int[] ans = new int[N];
        return can(ans,0,rooms);
    }
    public boolean can(int[] ans, int n, List<List<Integer>> rooms) {

        boolean res;
        if (rooms.get(n).isEmpty()||ans[n]==1) {
            if (n==0 && rooms.size()==1) {
                return true;
            }
            return false;
        }
        ans[n] = 1;
        for (int e: rooms.get(n)) {
            if (ans[e] == 1) {
                continue;
            }
            can(ans,e,rooms);
            ans[e]=1;
        }
        for (int i=0;i<rooms.size();i++) {
            if (ans[i] != 1) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        boolean a= new Lc841().canVisitAllRooms(Arrays.asList(Arrays.asList(1),Arrays.asList(2),Arrays.asList(3),Arrays.asList()));
        System.out.println(a);
    }
}
