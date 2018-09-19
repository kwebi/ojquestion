import java.util.ArrayList;
import java.util.List;

public class Lc840 {
    public int numMagicSquaresInside(int[][] grid) {
        int ans = 0;
        int m = grid.length;
        int n = grid[0].length;
        if (m < 3 || n < 3) {
            return 0;
        }
        for (int i=0;i<=m-3;i++) {
            for (int j=0;j<=n-3;j++) {
                boolean f=true;
                List<Integer> sum = new ArrayList<>(8);
                int[] arr=new int[10];
                int sum1=0;
                int sum2=0;
                for (int k=i;k<i+3;k++) {
                    sum1 = 0;

                    for (int s=j;s<j+3;s++) {
                        sum1 += grid[k][s];
                        if (grid[k][s]<0 || grid[k][s]>9) {
                            f=false;
                            break;
                        } else {
                            arr[grid[k][s]]++;
                        }
                    }
                    sum.add(sum1);
                }
                for (int i2=1;i2<=9;i2++) {
                    if (arr[i2] != 1) {
                        f=false;
                    }
                }

                for (int k=j;k<j+3;k++) {
                    sum2=0;
                    for (int s=i;s<i+3;s++) {
                        sum2 += grid[s][k];
                    }
                    sum.add(sum2);
                }
                int sum3;
                sum3 = grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
                sum.add(sum3);
                sum3 = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                sum.add(sum3);

                for (int i1=1;i1<8;i1++) {
                    if (sum.get(i1) != sum.get(0)) {
                        f=false;
                    }
                }
                if (f) {
                    ans++;
                }
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        int[][] arr = {{10,3,5},{1,6,11},{7,9,2}};
        System.out.println(new Lc840().numMagicSquaresInside(arr));
    }
}
