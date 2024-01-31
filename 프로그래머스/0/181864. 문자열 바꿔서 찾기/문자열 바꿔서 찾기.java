class Solution {
    public int solution(String myString, String pat) {
        int answer = 0;
        myString = myString.replaceAll("A", "T");
        myString = myString.replaceAll("B", "A");
        myString = myString.replaceAll("T", "B");
        if (myString.contains(pat)) {
            answer = 1;
        }
        return answer;
    }
}