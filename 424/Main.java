import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        BigInteger ans = BigInteger.valueOf(0);
        while(true){
            BigInteger t = in.nextBigInteger();
            if(t.equals(BigInteger.valueOf(0)))
                break;
            ans = ans.add(t);
        }
        System.out.println(ans);
    }
}