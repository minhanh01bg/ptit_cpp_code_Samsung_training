import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

//day con co tong le
//day con co tong la so nt
//DÃY CON CÓ K PHẦN TỬ TĂNG DẦN
public class DayConCoTongLe {
    public static int b[] = new int[15], n, k;

    public static void Try(int i, Integer a[]) {
        for (int j = 0; j <= 1; j++) {
            b[i] = j;
            if (i == n - 1) {
                // if (check(a)) {
                    print(a);
                // }
            } else
                Try(i + 1, a);
        }
    }

    public static boolean check1(Integer a[]) {
        // ArrayList<Integer> c = new ArrayList<Integer>();
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] * b[i] != 0 && c < a[i] * b[i] && b[i] == 1) {
                c = a[i] * b[i];
            } else if (a[i] * b[i] != 0 && c > a[i] * b[i]) {
                return false;
            }
        }
        return true;
    }

    // public static boolean check(Integer a[]) {
    // int k = 0;
    // for (int i = 0; i < n; i++) {
    // k += a[i] * b[i];
    // }
    // return (k % 2 != 0);
    // }

    public static boolean check(Integer a[]) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == 1)
                cnt += a[i];
        }
        if (isPrime(cnt))
            return true;
        return false;
    }

    public static void print(Integer a[]) {
        for (int i = 0; i < n; i++) {
            if (b[i] == 1)
                System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    public static boolean isPrime(int k) {
        for (int i = 2; i <= Math.sqrt(k); i++) {
            if (k % i == 0)
                return false;
        }
        return (k >= 2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t != 0) {
            t -= 1;
            n = sc.nextInt();
            // k = sc.nextInt();
            Integer[] a = new Integer[n];
            for (int i = 0; i < n; i++)
                a[i] = sc.nextInt();
            Arrays.sort(a, Collections.reverseOrder());
            Try(0, a);
        }
        sc.close();
    }
}
