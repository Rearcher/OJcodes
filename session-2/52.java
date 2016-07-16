// N-Queens II
class Point {
    int x, y;
    Point(int i, int j) {
        x = i;
        y = j;
    }
}

public class Solution {
    
    private Boolean isValid(Point p, ArrayList<Point> solution) {
        for (Point s : solution) {
            if (p.y == s.y) return false;
            if (Math.abs(p.x - s.x) == Math.abs(p.y - s.y)) return false;
        }
        return true;
    }

    private void backtracking(int n, int row, ArrayList<Point> solution, ArrayList<ArrayList<Point>> solutions) {
        if (row == n) {
            solutions.add(new ArrayList<Point>(solution));
            return;
        }

        for (int j = 0; j < n; j++) {
            Point p = new Point(row, j);
            if (isValid(p, solution)) {
                solution.add(p);
                backtracking(n, row+1, solution, solutions);
                solution.remove(row);
            }
        }
    }
    
    public int totalNQueens(int n) {
        ArrayList<ArrayList<Point>> ans = new ArrayList<>();
        backtracking(n, 0, new ArrayList<Point>(), ans);

        return ans.size();
    }
}
