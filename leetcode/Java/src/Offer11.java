public class Offer11 {
    public int minArray(int[] numbers) {
        long mi = (long) 2e18;
        for (int i = 0; i < numbers.length; i++) {
            mi = Math.min(mi, numbers[i]);
        }
        return (int) mi;
    }
}