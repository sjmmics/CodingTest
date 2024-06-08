import java.util.Arrays;

class Solution {
    public String[] solution(String[] files) {
        MyFile[] arr = new MyFile[files.length];
        for (int i = 0 ; i < files.length; i++) {
            arr[i] = new MyFile(files[i], i);
        }
        Arrays.sort(arr, ((o1, o2) -> {
            if (o1.head.equalsIgnoreCase(o2.head)) {
                if (o1.number == o2.number) {
                    return o1.originalIndex - o2.originalIndex;
                } else {
                    return o1.number - o2.number;
                }
            } else {
                return o1.head.compareToIgnoreCase(o2.head);
            }
        }));
        String[] answer = new String[files.length];
        for (int i = 0; i < files.length; i++) {
            answer[i] = files[arr[i].originalIndex];
        }
        return answer;
    }
}

class MyFile {
    String head;
    int number;
    int originalIndex;
    
    public MyFile(String str, int index) {
        int leftNumberIdx = getLeftNumberIdx(str);
        int rightNumberIdx = getRightNumberIdx(str, leftNumberIdx);
        this.head = str.substring(0, leftNumberIdx);
        this.number = Integer.parseInt(str.substring(leftNumberIdx, rightNumberIdx + 1));
        this.originalIndex = index;
    }

    private int getRightNumberIdx(String str, int leftNumberIdx) {
        for (int i = leftNumberIdx + 1; i < str.length(); i++) {
            if (!Character.isDigit(str.charAt(i))) {
                return i - 1;
            }
        }
        return str.length() - 1;
    }

    private int getLeftNumberIdx(String str) {
        for (int i = 0; i < str.length(); i++) {
            if (Character.isDigit(str.charAt(i))) {
                return i;
            }
        }
        return str.length() - 1;
    }
    
}