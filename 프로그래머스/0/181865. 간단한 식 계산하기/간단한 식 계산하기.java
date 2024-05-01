class Solution {
    public int solution(String binomial) {
        String[] expr = binomial.split(" ");
        int a = Integer.parseInt(expr[0]);
        int b = Integer.parseInt(expr[2]);
        int answer = 0;
        if (expr[1].equals("+")) {
            answer = a + b;
        } else if (expr[1].equals("-")) {
            answer = a - b;
        } else if (expr[1].equals("*")) {
            answer = a * b;
        }
        return answer;
    }
}