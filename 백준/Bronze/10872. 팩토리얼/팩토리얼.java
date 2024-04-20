import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        System.out.println(getFactorial(N));
       
    }
    static int getFactorial(int x) {
        int ans = 1;
        for (int i = 1; i <= x; i++) {
            ans *= i;
        }
        return ans;
        
    }
    
}