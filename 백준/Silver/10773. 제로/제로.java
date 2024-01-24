
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Stack<Integer> stk = new Stack<>();
        int K = Integer.parseInt(br.readLine());
        int x;
        for (int i = 0; i < K; i++) {
            x = Integer.parseInt(br.readLine());
            if (x == 0) {
                stk.pop();
            } else {
                stk.add(x);
            }
        }
        int res = 0;
        while (!stk.isEmpty()) {
            res += stk.pop();
        }
        bw.write(res + "\n");
        bw.close();
    }
}
