import java.util.*;

public class Solution {
    public int solution(int n) {
        int answer = 0;
        String strN = Integer.toString(n);
        int digitN = strN.length();
        int x;
        for (int i = digitN - 1; i >= 0; i--) {
            x = n / (int) Math.pow(10, i);
            answer += x;
            n -= x * (int) Math.pow(10, i);
        }
        return answer;
    }
}