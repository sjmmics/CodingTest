import java.util.Stack;
import java.util.ArrayList;
import java.util.List;
class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Stack<Character> stk = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stk.push('(');
            } else if (s.charAt(i) == ')') {
                if (stk.isEmpty()) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.isEmpty();
    }
}