public class Lc64 {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] arr = new int[1000][1000];
        //arr[m-1][n-1] = grid[m-1][n-1];
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                arr[i][j] = grid[i][j];
            }
        }
        for (int i=m-1;i>=0;i--) {
            for (int j=n-1;j>=0;j--) {
                if (i==m-1&&j==n-1) {
                    continue;
                }
                if (i==m-1&&j!=n-1) {
                    arr[i][j] += arr[i][j+1];
                    continue;
                }
                if (i!=m-1&&j==n-1) {
                    arr[i][j] += arr[i+1][j];
                    continue;
                }
                arr[i][j] += Math.min(arr[i+1][j],arr[i][j+1]);
            }
        }
        return arr[0][0];
    }
    public static void main(String[] args) {
        int[][] a = {{1,3,1},{1,5,1},{4,2,1}};
        System.out.println(new Lc64().minPathSum(a));
    }
}
