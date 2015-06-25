class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		if(E>=C || F>=D || G<=A || H<=B) return (C-A)*(D-B)+(G-E)*(H-F);
		else if(A>=E&&C<=G&&B>=F&&D<=H) return (G-E)*(H-F);
		else if(E>=A&&G<=C&&F>=B&&H<=D) return (C-A)*(D-B);
		vector<int> a{A,C,E,G};
		vector<int> b{B,D,F,H};
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		return (C-A)*(D-B)+(G-E)*(H-F)-(a[2]-a[1])*(b[2]-b[1]);
	}
};
