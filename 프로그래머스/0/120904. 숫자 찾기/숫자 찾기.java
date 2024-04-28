class Solution {
    public int solution(int num, int k) {
        String strNum = Integer.toString(num);
        int answer = -1;
        for (int i = 0; i < strNum.length(); i++) {
            if (k == Character.getNumericValue(strNum.charAt(i))) {
                answer = i + 1;
                break;
            }
        }
        
        return answer;
    }
}