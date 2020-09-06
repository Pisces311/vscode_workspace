import java.util.*;

public class Main {
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while (T-- > 0) {
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            int[] ans = {a, b, a ^ b};
            System.out.println(ans[n % 3]);
        }
    }
}