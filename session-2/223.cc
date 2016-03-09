/* Rectangle area */
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C-A)*(D-B);
        int area2 = (G-E)*(H-F);
        
        int overlap = 0;
        int left = max(A, E);
        int right = min(C, G);
        int top = min(D, H);
        int bottom = max(B, F);
        
        if (left < right && top > bottom)
            overlap = (right-left)*(top-bottom);
            
        return area1+area2-overlap;
    }
};
