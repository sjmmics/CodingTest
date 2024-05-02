
class Solution {
    public String solution(String X, String Y) {
        String answer = getPair(X, Y);
        if (answer.charAt(0) == '0') {
            return "0";
        } else {
            return answer;
        }
    }
    
    static String getPair(String x, String y) {
        int[] cntX = new int[10];
        int[] cntY = new int[10];
        for (int i = 0; i < x.length(); i++) {
            cntX[Character.getNumericValue(x.charAt(i))] += 1;
        }
        for (int i = 0; i < y.length(); i++) {
            cntY[Character.getNumericValue(y.charAt(i))] += 1;
        }
        int[] cntCmn = new int[10];
        boolean haveNoCommon = true;
        for (int i = 0; i < 10; i++) {
            cntCmn[i] = Math.min(cntX[i], cntY[i]);
            if (cntCmn[i] > 0) {
                haveNoCommon = false;
            }
        }
        if (haveNoCommon) {
            return "-1";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < cntCmn[i]; j++) {
                sb.append(Integer.toString(i));
            }
        }
        return sb.toString();
    }
}