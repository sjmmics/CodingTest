class Solution {
    boolean solution(String s) {
        String lowerS = s.toLowerCase();
        int cntP = 0; 
        int cntY = 0;
        for (int i = 0; i < lowerS.length(); i++) {
            if (lowerS.charAt(i) == 'p') cntP++;
            else if (lowerS.charAt(i) == 'y') cntY++;
        }
        
        return (cntP == cntY);
    }
}