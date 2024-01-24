import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        Stack<Integer> stk = new Stack<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x;
            switch (st.nextToken()) {
                case "push":
                    x = Integer.parseInt(st.nextToken());
                    stk.add(x);
                    break;
                case "pop":
                    if (stk.isEmpty()) bw.write(-1 + "\n");
                    else bw.write(stk.pop() + "\n");
                    break;
                case "size":
                    bw.write(stk.size() + "\n");
                    break;
                case "empty":
                    if (stk.isEmpty()) bw.write(1 + "\n");
                    else bw.write(0 + "\n");
                    break;
                case "top":
                    if (stk.isEmpty()) bw.write(-1 + "\n");
                    else bw.write(stk.peek() + "\n");
                    break;
            }
        }
        bw.close();
    }
}
