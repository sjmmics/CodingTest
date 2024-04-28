class Solution {
    public String[] solution(String[] names) {
        
        int span = names.length / 5;
        if (names.length % 5 != 0) {
            span++;
        }
        String[] answer = new String[span];
        for (int i = 0; i < answer.length; i++) {
            int j = i * 5;
            answer[i] = names[j];
        }
        return answer;
    }
}