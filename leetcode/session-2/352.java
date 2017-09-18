/**
 * Data Stream as Disjoint Intervals
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) {val = x;}
    
} 
 
public class SummaryRanges {
    

    TreeMap<Integer, Interval> tree;
    /** Initialize your data structure here. */
    public SummaryRanges() {
        tree = new TreeMap<>();
    }
    
    public void addNum(int val) {
        if (tree.containsKey(val)) return;

        Integer low = tree.lowerKey(val);
        Integer high = tree.higherKey(val);
        if (low != null && high != null && tree.get(low).end + 1 == val && tree.get(high).start - 1 == val) {
            tree.get(low).end = tree.get(high).end;
            tree.remove(high);
        } else if (low != null && tree.get(low).end + 1 >= val) {
            tree.get(low).end = Math.max(tree.get(low).end, val);
        } else if (high != null && high == val + 1) {
            tree.put(val, new Interval(val, tree.get(high).end));
            tree.remove(high);
        } else {
            tree.put(val, new Interval(val, val));
        }
    }
    
    public List<Interval> getIntervals() {
        return new ArrayList<>(tree.values());
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * List<Interval> param_2 = obj.getIntervals();
 */
