class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.empty() || haystack.size()<needle.size()) 
            return -1;
        if(haystack.size()==needle.size()) {
            if(haystack == needle) return 0;
            else return -1;
        }
        int i,j,k;
        for(i = 0; i < haystack.size();) {
            j=0;
            if(haystack[i]==needle[j]) {
                k = i;
                while(i<haystack.size() && j<needle.size() && haystack[i]==needle[j]) {
                    i++; j++;
                }
                if(j==needle.size()) return k;
                else i=k+1;
            }
            else i++;
        }
        return -1;
    }
};
