import java.util.ArrayList;

class Solution {
    public int solution(String dartResult) {
        ArrayList<String> list = transList(dartResult);
        return getScore(list);
    }
    public ArrayList<String> transList(String str) {
        ArrayList<String> answer = new ArrayList<>();
        boolean isTwoDigit = false;
        for (int i = 0; i < str.length(); i++) {
            char letter = str.charAt(i);
            if (Character.isDigit(letter)) {
                if (isTwoDigit) {
                    isTwoDigit = false;
                    continue;
                }
                if (Character.isDigit(str.charAt(i + 1))) {
                    answer.add("10");
                    isTwoDigit = true;
                } else {
                    answer.add(Character.toString(letter));
                }
            } else {
                answer.add(Character.toString(letter));
            }
        }
        return answer;
    }
    public int getScore(ArrayList<String> list) {
        int result = 0;
        int prevScore = 0;
        int crrScore = 0;
        for (String crr : list) {
            if (crr.equals("D")) {
                crrScore = (int) Math.pow(crrScore, 2);
            } else if (crr.equals("T")) {
                crrScore = (int) Math.pow(crrScore, 3);
            } else if (crr.equals("*")) {
                crrScore *= 2;
                prevScore *= 2;
            } else if (crr.equals("#")) {
                crrScore = -crrScore;
            } else if (crr.equals("S")) {
                continue;
            } else {
                result += prevScore;
                prevScore = crrScore;
                crrScore = Integer.parseInt(crr);
            }
        }
        return result + crrScore + prevScore;
    }
    
}
