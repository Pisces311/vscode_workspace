import java.util.*;

public class C {

    static int n, m;
    static long ans = 0;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();
        in.close();
        Arrays.sort(a);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                ans += upperBound(a, j + 1, n - 1, m - a[i] - a[j]) - lowerBound(a, j + 1, n - 1, m - a[i] - a[j]);
        System.out.println(ans);
    }

    public static int lowerBound(int[] nums, int l, int r, int target) {
        int ans = n;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] >= target) {
                ans = m;
                r = m - 1;
            } else
                l = m + 1;
        }
        return ans;
    }

    public static int upperBound(int[] nums, int l, int r, int target) {
        int ans = n;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] <= target)
                l = m + 1;
            else {
                ans = m;
                r = m - 1;
            }
        }
        return ans;
    }
}