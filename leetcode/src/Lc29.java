public class Lc29 {
    public int divide(int dividend, int divisor) {
        boolean isPositive = true;
        if((dividend < 0 && divisor >0) || (dividend > 0 && divisor < 0)){
            isPositive = false;
        }
        long ldividend = Math.abs((long)dividend);
        long ldivisor = Math.abs((long)divisor);
        if(ldivisor == 0)return Integer.MAX_VALUE;
        if(ldividend == 0)return 0;
        long lans = ldivide(ldividend, ldivisor);
        int ans;
        if (lans > Integer.MAX_VALUE){
            ans = (isPositive)? Integer.MAX_VALUE : Integer.MIN_VALUE;
        } else {
            ans = (isPositive) ? (int)lans : -(int)lans;
        }
        return ans;
    }
    public long ldivide(long ldividend, long ldivisor) {
        if (ldividend < ldivisor) return 0;
        long sum = ldivisor;
        long multiple = 1;
        while ((sum+sum) <= ldividend) {
            sum += sum;
            multiple += multiple;
        }
        return multiple + ldivide(ldividend - sum, ldivisor);
    }
    public static void main(String[] args) {
        System.out.println(new Lc29().divide(10,3));
    }
}
