import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
    private static BigInteger rev(BigInteger x){
        BigInteger r = BigInteger.ZERO;
        while(x != BigInteger.ZERO){
            r = r.multiply(BigInteger.valueOf(10));
            r = r.add(x.mod(BigInteger.valueOf(10)));
            x = x.divide(BigInteger.valueOf(10));
        }
        return r;
    }
    public static void main(String... args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for(int i = 0; i < n; i++){
            BigInteger a = scanner.nextBigInteger(), b = scanner.nextBigInteger();
            System.out.println(rev(rev(a).add(rev(b))));        
        }        
    }
}