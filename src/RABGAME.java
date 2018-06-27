import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
 
public class Main {
    
    public static Scanner cin = new Scanner(System.in);
    
    public static void main(String[] args) throws IOException  {
        
        /*
        FileInputStream fi = new FileInputStream("D:/java.inp"); 
        Scanner in = new Scanner(fi);
        FileOutputStream fo = new FileOutputStream("D:/java.out");
        PrintWriter out = new PrintWriter(fo);
        */
        
        //BufferedReader in = new BufferedReader(new FileReader(new File("D:/java.inp")));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        DecimalFormat df = new DecimalFormat("#.000"); 
        
        //------------------------------------------------------------------------------//
        
        int n = Integer.parseInt(in.readLine());
        BigInteger f[] = new BigInteger[n+1];
        f[1] = BigInteger.valueOf(1);
        f[2] = BigInteger.valueOf(2);
        for (int i=3;i<=n;i++) 
        	f[i] = f[i-1].add(f[i-2].multiply(BigInteger.valueOf(i-1)));
        
        System.out.println(f[n]);

    }
}  