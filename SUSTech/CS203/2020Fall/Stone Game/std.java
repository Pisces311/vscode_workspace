import java.util.*;

public class Main {
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while (T-- > 0) {
            int n = in.nextInt();
            int[] a = new int[n + 1];
            for (int i = 1; i <= n; ++i) a[i] = in.nextInt();
            int ans = 0;
            for (int i = 1; i <= n; ++i) if (solve(a, n, i)) ++ans;
            System.out.println(ans);
        }
    }

    public static boolean solve (int[] a, int n, int i) {
        int XOR = 0;
        for (int j = 1; j <= n; ++j) {
            if (j != i) XOR ^= a[j];
        }
        return a[i] > XOR;
    }
}