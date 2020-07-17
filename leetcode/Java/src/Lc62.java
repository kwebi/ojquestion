
public class Lc62 {
    public int uniquePaths(int m, int n) {
        int[][] arr = new int[105][105];
        for (int i=0;i<104;i++) {
            arr[0][i]=1;
            arr[i][0]=1;

        }
        arr[0][0]=0;
        if (m==1||n==1) {
            return 1;
        }
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                arr[i][j] = arr[i][j-1] + arr[i-1][j];
            }
        }
        return arr[m-1][n-1];
    }
    public static void main(String[] args) {
        System.out.println(new Lc62().uniquePaths(7,3));
    }
}
