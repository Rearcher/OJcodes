/*
 * 68. Text Justification
 */
public class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();
        int i = 0, len = words.length;
        while (i < len) {
            int j = i, sum = words[j].length();
            while (j+1 < len) {
                if (sum + (1 + words[j+1].length()) > maxWidth) break;
                sum += (1 + words[j+1].length());
                j += 1;
            }
			// current line words count
            int wordsCnt = j - i + 1;
			// maxWidth - everyword's length - (wordsCnt - 1)spaces
            int emptyCells = maxWidth - sum;
			// allocate emptyCells after each word
            int paddings = wordsCnt == 1 ? emptyCells : (emptyCells / (wordsCnt - 1));
            // empty spaces cannot be allocated evenly, add behind the front words
			int left = wordsCnt == 1 ? emptyCells : (emptyCells % (wordsCnt - 1));

            StringBuilder temp = new StringBuilder();
            
            if (j == len - 1) { // the last len, left justified
                while (i <= j - 1) {
                    temp.append(words[i]);
                    temp.append(" ");
                    i++;
                }
                temp.append(words[i]);
                for (int k = 0; k < emptyCells; ++k)
                    temp.append(" ");
            } else { 			// distributed empty spaces evenly

                while (i <= j - 1) {
                    temp.append(words[i]);
                    temp.append(" ");
                    for (int k = 0; k < paddings; ++k)
                        temp.append(" ");
                    if (left > 0) {
                        left--;
                        temp.append(" ");
                    }
                    i++;
                }
                temp.append(words[i]);
                if (wordsCnt == 1) {
                    for (int k = 0; k < emptyCells; ++k)
                        temp.append(" ");
                }
            }
            res.add(temp.toString());
            i++;
        }
        return res;
    }
}
