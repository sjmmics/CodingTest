import java.util.Stack;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        Stack<Integer> stk = new Stack<>();
        
        for (int i = 0; i < numbers.length; i++) {
            while (!stk.isEmpty() && numbers[stk.peek()] < numbers[i]) {
                answer[stk.peek()] = numbers[i];
                stk.pop();
            } 
            stk.push(i);
        }
        for (int i = 0; i < numbers.length; i++) {
            if (answer[i] == 0) {
                answer[i] = -1;
            }
        }
        return answer;
    }
}
