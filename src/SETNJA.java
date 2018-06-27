import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.util.Random;
import java.math.BigInteger;
 
public class Main {  
 
	public static void main(String[] args) throws IOException  {
       
        //BufferedReader in = new BufferedReader(new FileReader(new File("D:/java.inp")));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        String s = in.readLine();
        BigInteger F = BigInteger.valueOf(1), cnt = F;
        for (int i=0;i<s.length();i++) {
        	if (s.charAt(i) == 'L') 
        		F = F.multiply(BigInteger.valueOf(2));
        	else 
        	if (s.charAt(i) == 'R') 
        		F = F.multiply(BigInteger.valueOf(2)).add(cnt);
        	else
        	if (s.charAt(i) == '*') {
        		F = F.multiply(BigInteger.valueOf(5)).add(cnt);
        		cnt = cnt.multiply(BigInteger.valueOf(3));
        	}
        }
        
        System.out.print(F);
        
	}
    
} 
 