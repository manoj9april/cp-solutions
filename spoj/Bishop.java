import java.util.*;
import java.math.*;

public class Bishop{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str;
        while(in.hasNext()){
            str = in.next();
            int a = str.charAt(0)-'0';
            if(a==1 && str.length()==1){
                System.out.println(1);
                continue;
            }
            BigInteger n = new BigInteger(str);
            BigInteger two = BigInteger.valueOf(2);
            n = n.multiply(two);
            System.out.println(n.subtract(two));
        }

    }
} 