import java.util.HashMap;
import java.util.ArrayList;

class Solution {
    public String[] solution(String[] record) {
        HashMap<String, String> map = getFinalName(record);
        
        return getMessage(record, map);
    }
    static HashMap<String, String> getFinalName(String[] record) {
        HashMap<String, String> answer = new HashMap<>();
        for (String str : record) {
            String[] arr = str.split(" ");
            if (arr[0].equals("Enter")) {
                answer.put(arr[1], arr[2]);    
            } else if (arr[0].equals("Change")) {
                answer.put(arr[1], arr[2]);
            }
        }
        return answer;
    }
    static String[] getMessage(String[] record, HashMap<String, String> map) {
        ArrayList<String> list = new ArrayList<>();
        for (String str: record) {
            String[] arr = str.split(" ");
            if (arr[0].equals("Enter")) {
                list.add(map.get(arr[1]) + "님이 들어왔습니다.");
            } else if (arr[0].equals("Leave")) {
                list.add(map.get(arr[1]) + "님이 나갔습니다.");
            }
        }
        String[] answer = list.toArray(new String[0]);
        return answer;
    }
}