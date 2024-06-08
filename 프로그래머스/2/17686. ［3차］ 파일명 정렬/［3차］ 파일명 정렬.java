import java.util.Arrays;

class Solution {
    public String[] solution(String[] files) {
        MyFile[] arr = new MyFile[files.length];
        for (int i = 0 ; i < files.length; i++) {
            arr[i] = new MyFile(files[i], i);
        }
        Arrays.sort(arr);
        String[] answer = new String[files.length];
        for (int i = 0; i < files.length; i++) {
            answer[i] = files[arr[i].originalIndex];
        }
        return answer;
    }
}

class MyFile implements Comparable {
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

    @Override
    public int compareTo(Object o) {
        MyFile target = (MyFile) o;
        if (this.head.equalsIgnoreCase(target.head)) {
            if (this.number == target.number) {
                return this.originalIndex - target.originalIndex;
            } else {
                return this.number - target.number;
            }
        } else {
            return this.head.compareToIgnoreCase(target.head);
        }
    }
}
