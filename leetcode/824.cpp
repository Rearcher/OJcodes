// 824. Goat Latin

class Solution {
public:
    string toGoatLatin(string S) {
        stringstream ss(S);
        string word;
        string result = "";
        int idx = 1;
        
        while (ss >> word) {
            if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' ||
                word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U') {
                word += "ma";
            } else {
                word = word.substr(1) + word.substr(0, 1) + "ma";
            }
            word += string(idx, 'a');            
            idx += 1;
            
            if (result.size()) result += " ";
            result += word;
        }
        return result;
    }
};