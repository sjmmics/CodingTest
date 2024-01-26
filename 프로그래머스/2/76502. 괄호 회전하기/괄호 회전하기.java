import java.util.Stack;

class Solution {
    public int solution(String s) {
        int answer = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (isRightBrkt(s.substring(i, s.length()) + s.substring(0, i))) {
                answer++;
            }
        }
        return answer;
    }
    
    public boolean isRightBrkt(String str) {
        Stack<Character> stk = new Stack<>();
        char crr;
        for (int i = 0; i < str.length(); i++) {
            crr = str.charAt(i);
            if (crr == ')' || crr == ']' || crr =='}' ) {
                if (stk.isEmpty()) {
                    return false;
                } else if (crr == ')' && stk.peek() == '(') {
                    stk.pop();
                } else if (crr == ']' && stk.peek() == '[') {
                    stk.pop();
                } else if (crr == '}' && stk.peek() == '{') {
                    stk.pop();
                } else {
                    return false;
                }
            } else { 
                stk.push(crr);
            }
        }
        return stk.isEmpty();
    }
}