// Course Schedule
public class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] indegrees = new int[numCourses];
        boolean[] removed = new boolean[numCourses];
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < numCourses; ++i)
            graph.add(new ArrayList<>());
        for (int[] prerequisite : prerequisites) {
            graph.get(prerequisite[0]).add(prerequisite[1]);
            indegrees[prerequisite[1]]++;
        }

        int cnt = 0;
        while (cnt < numCourses) {
            boolean flag = false;
            for (int i = 0; i < indegrees.length; ++i) {
                if (!removed[i] && indegrees[i] == 0) {
                    flag = true;
                    removed[i] = true;
                    cnt++;

                    for (int j = 0; j < graph.get(i).size(); ++j)
                        indegrees[graph.get(i).get(j)]--;
                    break;
                }
            }
            if (!flag) return false;
        }

        return true;
    }
}
