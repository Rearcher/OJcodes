//When I implemented it in simulation, it turned out to be OLE
//View it as a math problem!
class Solution {
public:
	string convert(string s, int numRows) {
    
        if(numRows==1 || s.length()==0)
            return s;
    
        string res = ""; 
        int len=s.length();
        for(int i = 0; i < len && i < numRows; i++) {
            int index = i;
            res += s[index];

            for(int k = 1; index < len; k++) {
                if(i==0 || i==numRows-1) 
                    index += 2*(numRows-1);
                else {
                    if(k%2)
                        index += 2*(numRows-1-i);
                    else
                        index += 2*i;
                }

                if(index < len)
                    res += s[index];
            }
        }

        return res;
    }   
}
