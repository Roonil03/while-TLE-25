import java.util.*;

class Main {

    public static List<Integer> resolveCollisions(int[] cars) {
        Stack<Integer> stack = new Stack<>();

        for (int car : cars) {
            boolean carSurvived = true;

            while (!stack.isEmpty() && car < 0 && stack.peek() > 0) {
                int top = stack.peek();

                if (Math.abs(car) > Math.abs(top)) {
                    stack.pop(); 
                } else if (Math.abs(car) == Math.abs(top)) {
                    stack.pop(); 
                    carSurvived = false;
                    break;
                } else {
                    carSurvived = false;
                    break;
                }
            }

            if (carSurvived) {
                stack.push(car);
            }
        }

        return new ArrayList<>(stack);
    }

   public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int t = Integer.parseInt(scanner.nextLine());

    for (int test = 0; test < t; test++) {
        int n = Integer.parseInt(scanner.nextLine());
        int[] cars = Arrays.stream(scanner.nextLine().split(" "))
                           .mapToInt(Integer::parseInt)
                           .toArray();

        List<Integer> result = resolveCollisions(cars);
        if (result.isEmpty()) {
            System.out.println(); 
        } else {
            for (int i = 0; i < result.size(); i++) {
                System.out.print(result.get(i));
                if (i != result.size() - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }

    scanner.close();
}
}
