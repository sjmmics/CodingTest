class Solution {
    public String solution(String my_string, int s, int e) {
        StringBuilder sb = new StringBuilder();
        sb.append(my_string.substring(0, s));
        StringBuilder temp = new StringBuilder();
        temp.append(my_string.substring(s, e + 1));
        temp.reverse();
        sb.append(temp);
        sb.append(my_string.substring(e + 1));
        
        String answer = sb.toString();
        return answer;
    }
}