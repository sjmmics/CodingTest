import java.util.Arrays;
import java.util.Objects;

class Solution {
    public String[] solution(String[] files) {
        String[] answer = getSorted(files);
        return answer;
    }
    public String[] getSorted(String[] files) {
        Object[][] arr = new Object[files.length][3];
        for (int i = 0; i < files.length; i++) {
            String str = files[i];
            int leftNumIdx = 0;
            for (int j = 0; j < str.length(); j++) {
                if (Character.isDigit(str.charAt(j))) {
                    leftNumIdx = j;
                    break;
                }
            }
            int rightNumIdx = getRightIdx(str, leftNumIdx);
            arr[i][0] = str.substring(0, leftNumIdx);
            arr[i][1] = Integer.parseInt(str.substring(leftNumIdx, rightNumIdx + 1));
            arr[i][2] = (int) i;
        }
        Arrays.sort(arr, (o1, o2) ->
        {
            if (((String) o1[0]).equalsIgnoreCase((String) o2[0])) {
                if (o1[1] == o2[1]) return (int) o1[2] - (int) o2[2];
                else return (int) o1[1] - (int) o2[1];}
            else {return ((String) o1[0]).compareToIgnoreCase((String) o2[0]);}
        });
        String[] answer = new String[arr.length];
        for (int i = 0; i < arr.length; i++) {
            answer[i] = files[(int) arr[i][2]];
        }
        return answer;
    }
    public int getRightIdx(String str, int leftNumIdx) {
        
        for (int i = leftNumIdx + 1; i < str.length(); i++) {
            if (!Character.isDigit(str.charAt(i))) {
                return i - 1;
            }
        }
        return str.length() - 1;
    }
}