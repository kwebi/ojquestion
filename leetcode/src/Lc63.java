public class Lc63 {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int[][] arr = new int[105][105];

        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        if (obstacleGrid[m-1][n-1]==1||obstacleGrid[0][0]==1) {
            return 0;
        }
        arr[m-1][n-1]=1;
        for (int i=m-1;i>=0;i--) {
            for (int j=n-1;j>=0;j--) {
                if (obstacleGrid[i][j]==1){
                    arr[i][j] = 0;
                    continue;
                }
                if (i==m-1&&j==n-1) {
                    continue;
                }
                if (i==m-1) {
                    arr[i][j]=arr[i][j+1];
                    continue;
                }
                if (j==n-1) {
                    arr[i][j] = arr[i+1][j];
                    continue;
                }
                arr[i][j]=arr[i+1][j]+arr[i][j+1];

            }
        }
        return arr[0][0];
    }
    public static void main(String[] args) {
        int[][] a = {{0,0},{1,0}};
        System.out.println(new Lc63().uniquePathsWithObstacles(a));
    }
}
