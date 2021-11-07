import java.lang.*;
import java.util.*;
import java.math.*;

public class LCM {
    public static BigInteger lcm(String a, String b) {
        BigInteger s = new BigInteger(a);
        BigInteger s1 = new BigInteger(b);
        BigInteger mul = s.multiply(s1);
        BigInteger gcd = s.gcd(s1);
        BigInteger lcm = mul.divide(gcd);
        return lcm;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- != 0) {
            String a = sc.nextLine(), b = sc.nextLine();
            System.out.println(lcm(a, b));
        }
        sc.close();
    }
}