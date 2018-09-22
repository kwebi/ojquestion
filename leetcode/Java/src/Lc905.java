public class Lc905 {
    public int[] sortArrayByParity(int[] A) {
        int m = A.length;
        int[] ans = new int[m];
        int i;
        int j = 0;
        for (i = 0; i<m; i++) {
            if (A[i] % 2 == 0) {
                ans[j] = A[i];
                j++;
            }
        }
        for (i = 0; i<m; i++) {
            if (A[i] %2 == 1) {
                ans[j] = A[i];
                j++;
            }
        }
        return ans;
    }
}
