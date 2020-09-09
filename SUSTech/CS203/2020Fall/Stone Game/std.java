import java.util.*;

public class Main {
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while (T-- > 0) {
            int n = in.nextInt();
            int[] a = new int[n + 1];
            for (int i = 1; i <= n; ++i) a[i] = in.nextInt();
            int XOR = 0;
            int ans = 0;
            for (int i = 1; i <= n; ++i) XOR ^= a[i];
            if (XOR != 0) {
                for (int i = 1; i <= n; ++i) if (a[i] >= (XOR ^ a[i])) ++ans;
            }
            System.out.println(ans);
        }
    }
}