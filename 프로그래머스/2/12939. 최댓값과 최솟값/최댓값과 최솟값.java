class Solution {
    public String solution(String s) {
        String[] arr = s.split(" ");
        int bgst, smst, temp;
        bgst = smst = Integer.parseInt(arr[0]);
        for (int i = 0; i < arr.length; i++) {
            temp = Integer.parseInt(arr[i]);
            if (temp > bgst) {
                bgst = temp;
            } 
            if (temp < smst) {
                smst = temp;
            }
        }
        return smst + " " + bgst; 
        
    }
}