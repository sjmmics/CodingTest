import java.util.Stack;
import java.util.Arrays;

class Solution {
    public String solution(String p) {
        
        String answer = recursion(p);
        return answer;
    }

    static String recursion(String str) {
        if (str.equals("")) {
            return "";
        }
        
        for (int i = 2; i <= str.length(); i+=2) {
            String left = str.substring(0, i);
            String right = str.substring(i);
            if (isBalance(left)) {
                if (isBalance(right)) {
                    if (isRight(left)) {
                        return left + recursion(right);
                    } else {
                        String temp = "(";
                        temp = temp + recursion(right);
                        temp = temp + ")";
                        left = left.substring(1, left.length() - 1);
                        temp += getReverse(left);
                        return temp;
                    }
                }
            }
        }
        
        return "123";
    }
    static boolean isBalance(String str) {
        int cntLeft = 0;
        int cntRight = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(') {
                cntLeft++;
            } else if (str.charAt(i) == ')') {
                cntRight++;
            }
        }
        boolean answer = false;
        if (cntLeft == cntRight) {
            answer = true;
        }
        return answer;
    }
    
    static boolean isRight(String str) {
        Stack<Character> stck = new Stack<>();
        for (int i = 0; i < str.length(); i++) {
            if (!stck.isEmpty() && str.charAt(i) == ')' && stck.peek() == '(') {
                stck.pop();
            } else {
                stck.push((Character) str.charAt(i));
            }
        }
        boolean answer = false;
        if (stck.isEmpty()) {
            answer = true;
        }
        return answer;
    }
    static String getReverse(String str) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(') {
                sb.append(")");
            } else {
                sb.append("(");
            }
        }
        return sb.toString();
    }

}