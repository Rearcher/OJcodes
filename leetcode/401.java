/*
 * 401. Binary Watch
 */
public class Solution {
    private int index(int num) {
        int cnt = 0;
        for (int i = 0; i < 6; ++i) {
            if ((num & 1) == 1) cnt++;
            num >>= 1;
        }
        return cnt;
    }

    public List<String> readBinaryWatch(int num) {
        List<List<Integer>> hours = new ArrayList<>();
        List<List<Integer>> minutes = new ArrayList<>();
        for (int i = 0; i < 6; ++i) {
            hours.add(new ArrayList<>());
            minutes.add(new ArrayList<>());
        }

        for (int i = 0; i < 60; ++i) {
            if (i < 12) hours.get(index(i)).add(i);
            minutes.get(index(i)).add(i);
        }

        List<String> res = new ArrayList<>();
        for (int i = 0; i <= num; ++i) {
            int j = num - i;
            if (i >= hours.size()) break;
            if (j >= minutes.size()) continue;

            for (int x = 0; x < hours.get(i).size(); ++x) {
                for (int y = 0; y < minutes.get(j).size(); ++y) {
                    StringBuilder str = new StringBuilder();
                    str.append(hours.get(i).get(x));
                    str.append(":");
                    if (minutes.get(j).get(y) < 10) {
                        str.append("0");
                    }
                    str.append(minutes.get(j).get(y));
                    res.add(str.toString());
                }
            }
        }
        return res;
    }
}
