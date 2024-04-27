import java.util.Stack;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<Integer> stk = new Stack<>();
        for (int i = 0; i < prices.length; i++) {
            while (!stk.isEmpty() && prices[i] < prices[stk.peek()]) {
                answer[stk.peek()] = i - stk.peek();
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.isEmpty()) {
            answer[stk.peek()] = prices.length - 1 - stk.peek();
            stk.pop();
        }                                               
        return answer;
    }
}