import java.util.ArrayList;

class Solution {
    static ArrayList<String> list = new ArrayList<>();
    static ArrayList<String> temp = new ArrayList<>();
    public int solution(String word) {
        String[] arr = {"A", "E", "I", "O", "U"};
        dfs(arr);
        int answer = 0;
        for (String str : list) {
            if (str.equals(word)) {
                break;
            }
            answer++;
        }
        return answer;
    }
    static void dfs(String[] arr) {
        StringBuilder sb = new StringBuilder();
        for (String str : temp) {
            sb.append(str);
        }
        list.add(sb.toString());
        if (temp.size() == 5) {
            return;
        }
        
        for (String letter : arr) {
            temp.add(letter);
            dfs(arr);
            temp.remove(temp.size() - 1);
        }
    }
}