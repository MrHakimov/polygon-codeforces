import java.util.*;

/*
 * @author: Muhammadjon Hakimov
 * created: 07.05.2019 23:18:07
 */

public class MaxAndDeque {
    public static class Pair {
        int first;
        int second;

        Pair (int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void showDeque(Deque<Integer> deque) {
        int n = deque.size();
        for (int i = 0; i < n; i++) {
            System.out.print(deque.peekFirst() + " ");
            deque.addLast(deque.peekFirst());
            deque.removeFirst();
        }
        System.out.println("==");
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        Deque<Integer> deque = new ArrayDeque<>();
        int maxValue = -1;
        for (int i = 0; i < n; i++) {
            int a_i = in.nextInt();
            deque.addLast(a_i);
            maxValue = Math.max(maxValue, a_i);
        }

        Map<Integer, Pair> answer = new HashMap<>();

        int maxIndex = 0;
        while (true) {
            //showDeque(deque);
            int first = deque.getFirst();
            deque.pollFirst();
            int second = deque.getFirst();
            deque.pollFirst();

            if (first == maxValue) {
                deque.addFirst(second);
                deque.addFirst(first);
                break;
            }

            maxIndex++;
            answer.put(maxIndex, new Pair(first, second));

            if (second > first) {
                int tmp = first;
                first = second;
                second = tmp;
            }

            deque.addFirst(first);
            deque.addLast(second);
        }

        int[] a = new int[n];
        //showDeque(deque);
        for (int i = 0; i < n; i++) {
            a[i] = deque.peekFirst();
            deque.removeFirst();
        }

        for (int i = 0; i < m; i++) {
            long m_i = in.nextLong();
            if (m_i <= maxIndex) {
                System.out.println(answer.get((int) m_i).first + " " + answer.get((int) m_i).second);
            } else {
                System.out.println(maxValue + " " + a[(int) ((m_i - (maxIndex + 1)) % (n - 1) + 1)]);
            }
        }
    }
}