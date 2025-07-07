import java.util.*;

public class Solution {
    public static boolean isValidTree(int n, int[][] edges) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i < n; i++)
            graph.put(i, new ArrayList<>());

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        boolean[] visited = new boolean[n];

        if (hasCycle(graph, 0, -1, visited))
            return false;

        for (int i = 0; i < n; i++) {
            if (graph.get(i).size() > 0 && !visited[i])
                return false;
        }

        return true;
    }

    private static boolean hasCycle(Map<Integer, List<Integer>> graph, int node, int parent, boolean[] visited) {
        visited[node] = true;

        for (int neighbor : graph.get(node)) {
            if (!visited[neighbor]) {
                if (hasCycle(graph, neighbor, node, visited))
                    return true;
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Boolean> results = new ArrayList<>();

        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] edges = new int[m][2];
            for (int i = 0; i < m; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
            }
            results.add(isValidTree(n, edges));
        }

        for (boolean res : results) {
            System.out.println(res);
        }
    }
}