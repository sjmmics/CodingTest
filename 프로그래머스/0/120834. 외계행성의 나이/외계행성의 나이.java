class Solution {
    public String solution(int age) {
        String[] alp = { "a", "b", "c", "d", "e",
                       "f", "g", "h", "i", "j" };
        
        String strAge = Integer.toString(age);
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < strAge.length(); i++) {
            sb.append(alp[Character.getNumericValue(strAge.charAt(i))]);
        }
        String answer = sb.toString();
        return answer;
    }
}