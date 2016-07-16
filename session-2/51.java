// N-Queens
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
    
    public List<List<String>> solveNQueens(int n) {
        ArrayList<ArrayList<Point>> ans = new ArrayList<>();
        backtracking(n, 0, new ArrayList<Point>(), ans);

        List<List<String>> res = new ArrayList<>();
        for (ArrayList<Point> solution : ans) {
            List<String> temp = new ArrayList<>();
            for (Point p : solution) {
                String str = "";
                for (int i = 0; i < n; i += 1) {
                    if (i == p.y) str += 'Q';
                    else str += '.';
                }
                temp.add(str);
            }
            res.add(temp);
        }

        return res;
    }
}
