/*
 * 84. Largest Rectangle in Histogram
 * using [2, 1, 5, 6, 2, 3] as example
 * using one stack
 * iterate from left to right once:
 *   1) if stack.isEmpty() || heights[i] >= stack.peek()
 *      	just push index i into stack
 *   2) else
 *          pop stack until stack.peek() <= heights[i]
 *          after each pop operation, calculate area
 *
 * and why?
 * basic idea: for each bar x, calculate the area as bar x is the smallest bar
 * and we need to know (index of the first smaller bar on left of x) and (the first smaller bar on right of x)
 * that's why we need to keep index in stack increasing
 */ 
public class Solution {
    public int largestRectangleArea(int[] heights) {
        int len = heights.length, i = 0;
        Stack<Integer> stack = new Stack<>();
        int max = 0;

        while (i <= len) {
            int h = (i == len) ? 0 : heights[i];
            if (stack.isEmpty() || h >= heights[stack.peek()]) {
                stack.push(i);
                i++;
            } else {
                int t = stack.pop();
                max = Math.max(max, heights[t] * (stack.isEmpty() ? i : i - 1 - stack.peek()));
            }
        }
        return max;
    }
}
