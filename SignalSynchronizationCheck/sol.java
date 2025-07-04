import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = Integer.parseInt(sc.nextLine());
        for (int t = 0; t < T; t++) {
            String x = sc.nextLine();
            String y = sc.nextLine();
            String z = sc.nextLine();
            System.out.println(isMerged(x, y, z));
        }
    }

    static boolean isMerged(String x, String y, String z) {
        int m = x.length(), n = y.length();
        if (m + n != z.length()) return false;

        boolean[][] dp = new boolean[m + 1][n + 1];
        dp[0][0] = true;

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i > 0 && x.charAt(i - 1) == z.charAt(i + j - 1)) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (j > 0 && y.charAt(j - 1) == z.charAt(i + j - 1)) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
}
