import java.util.*;

public class Solution {

    public static int minConferenceRooms(int[][] events) {
        TreeMap<Integer, Integer> timeMap = new TreeMap<>();

        for (int[] event : events) {
            int start = event[0], end = event[1];
            timeMap.put(start, timeMap.getOrDefault(start, 0) + 1);
            timeMap.put(end + 1, timeMap.getOrDefault(end + 1, 0) - 1);
        }

        int maxOverlap = 0, ongoing = 0;

        for (int count : timeMap.values()) {
            ongoing += count;
            maxOverlap = Math.max(maxOverlap, ongoing);
        }

        return maxOverlap;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] events = new int[n][2];

        for (int i = 0; i < n; i++) {
            events[i][0] = sc.nextInt();
            events[i][1] = sc.nextInt();
        }

        System.out.println(minConferenceRooms(events));
    }
}