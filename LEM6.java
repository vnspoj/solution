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
        
        String s[] = in.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        String t[] = in.readLine().split(" ");
        int S = 0;
        for (int i=0;i<m;i++) {
        	int x = Integer.parseInt(t[i]);
        	S += x;
        }
        if (n < S+m-1) {
        	System.out.println("0");
        	return;
        }
        BigInteger c[][] = new BigInteger[n+5][n+5];
        for (int j=0;j<=n-S+1;j++) 
        	for (int i=0;i<=j;i++) c[i][j] = BigInteger.valueOf(0);
        
        for (int j=0;j<=n-S+1;j++) {
        	for (int i=0;i<=j;i++) {
        		if (i == 0 || i == j) {
        			c[i][j] = BigInteger.valueOf(1);
        		}
        		else {
        			c[i][j] = c[i][j-1].add(c[i-1][j-1]);
        		}
        	}
        }
        
        System.out.println(c[m][n-S+1]);
    }
    
    
}  