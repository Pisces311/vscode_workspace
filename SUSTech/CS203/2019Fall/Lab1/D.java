import java.util.Scanner;

public class D {
    static private int T, cnt;
    static private long n;
    public static void cal(String s) {
        long a = Long.parseLong(s);
        if (a > n || s.length() > 11)
            return;
        if (s.charAt(0) != '0')
            ++cnt;
        for (int i = 0; i <= 9; ++i)
            cal(i + s + i);
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        T = in.nextInt();
        while (T-- > 0) {
            n = in.nextLong();
            cnt = 0;
            for (int i = 0; i <= 9; ++i)
                cal("" + i);
            for (int i = 0; i <= 9; ++i)
                cal("" + i + i);
            System.out.println(cnt + 1);
        }
    }
}
