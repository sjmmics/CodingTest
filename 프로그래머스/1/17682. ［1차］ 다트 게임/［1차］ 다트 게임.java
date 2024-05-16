class Solution {
    public int solution(String dartResult) {
        
        return getScore(dartResult);
    }
    public int getScore(String darts) {
        int totScore = 0;
        int prevScore = 0;
        int crrScore = 0;
        boolean isTwoDigit = false;
        for (int i = 0; i < darts.length(); i++) {
            char crrLetter = darts.charAt(i);
            
            if (Character.isDigit(crrLetter)) {
                if (!isTwoDigit) {
                    totScore += prevScore;
                    prevScore = crrScore;
                    if (Character.isDigit(darts.charAt(i + 1))) {
                        crrScore = 10;
                        isTwoDigit = true;
                    } else {
                        crrScore = Character.getNumericValue(crrLetter);
                    }
                } else {
                    isTwoDigit = false;
                }
            } else if (crrLetter == 'D') {
                crrScore = (int) Math.pow(crrScore, 2);    
            } else if (crrLetter == 'T') {
                crrScore = (int) Math.pow(crrScore, 3);
            } else if (crrLetter == '*') {
                prevScore *= 2;
                crrScore *= 2;
            } else if (crrLetter == '#') {
                crrScore = -crrScore;
            }
            
        }
        return totScore + crrScore + prevScore;
    }
}