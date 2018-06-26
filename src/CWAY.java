import java.io.*;
import java.math.*;
import java.util.*;
 
class main {
    public static void main(String args[]) throws IOException {
    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    	
    	int n = Integer.parseInt(in.readLine());
    	BigInteger ans = new BigInteger("1"), tmp = ans;
    	for(int i=n-2;i>0;i--) {
    		tmp = tmp.multiply(BigInteger.valueOf(i));
    		ans = ans.add(tmp);
    	}
    	System.out.println(ans);
    }
        
}