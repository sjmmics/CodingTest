import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static int cnt = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String skills = br.readLine();
        Stack<Character> lrStck = new Stack<>();
        Stack<Character> skStck = new Stack<>();
        Character crr;
        boolean flag = false;
        for (int i = 0; i < n; i++) {
            if (flag) break;
            crr = skills.charAt(i);
            if (Character.isDigit(crr)) {
                cnt++;
            } else {
                if (crr == 'L') {
                    lrStck.add('L');
                } else if (crr == 'S') {
                    skStck.add('S');
                } else if (crr == 'R') {
                    if (lrStck.isEmpty() || lrStck.peek() != 'L') {
                        break;
                    } else if (lrStck.peek() == 'L') {
                        lrStck.pop();
                        cnt++;
                    }
                } else if (crr == 'K') {
                    if (skStck.isEmpty() || skStck.peek() != 'S') {
                        break;
                    } else if (skStck.peek() == 'S') {
                        skStck.pop();
                        cnt++;
                    }
                }            
            }
        }
        System.out.println(cnt);
    }
}
