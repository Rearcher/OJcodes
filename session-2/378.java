// Kth Smallest Elements in a Sorted Matrix
public class Solution {
    class Tuple {
        int x, y, val;
        public Tuple(int x, int y, int val) {
            this.x = x;
            this.y = y;
            this.val = val;
        }
    }

    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        PriorityQueue<Tuple> heap = new PriorityQueue<>((a, b) -> a.val - b.val);
        for (int i = 0; i < Math.min(k, n); ++i)
            heap.offer(new Tuple(0, i, matrix[0][i]));
        for (int i = 0; i < k - 1; ++i) {
            Tuple temp = heap.poll();
            if (temp.x == n - 1) continue;
            heap.offer(new Tuple(temp.x + 1, temp.y, matrix[temp.x + 1][temp.y]));
        }
        return heap.poll().val;
    }
}
