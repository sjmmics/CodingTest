import java.util.Stack;

class Solution {
    public String solution(String number, int k) {
        Stack<Integer> stk = new Stack<>();
        int[] arr = new int[number.length()];
        for (int i = 0; i < number.length(); i++) {
            arr[i] = Character.getNumericValue(number.charAt(i));
        }
        for (int num : arr) {
            while (!stk.isEmpty() && stk.peek() < num && k > 0) {
                stk.pop();
                k--;
            }
            stk.push(num);
        }
        while (k > 0) {
            stk.pop();
            k--;
        }
        StringBuilder answer = new StringBuilder();
        while (!stk.isEmpty()) {
            answer.append(stk.pop());
        }
        answer.reverse();
        return answer.toString();
        
        
    }
}