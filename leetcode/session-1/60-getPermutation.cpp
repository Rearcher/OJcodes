class Solution { //128ms
public:
	string getPermutation(int n, int k) {
		vector<int> a;
		int tot = 1;
		for(int i=1; i<=n-1; i++) tot *= i;
		for(int i=1; i<=n; i++)	a.push_back(i);
		int begin,end;
		if(k%tot) {
			begin = k/tot + 1;
			end = k%tot;
			swap(a[0], a[begin-1]);
			sort(a.begin()+1, a.end());
			
			for(int i=1; i<end; i++) {
				int j, h;
				for(j=a.size()-2; j>=0; j--)
					if(a[j] < a[j+1]) break;
				for(h=a.size()-1; h>=0; h--)
					if(a[h] > a[j]) break;
				swap(a[h], a[j]);
				reverse(a.begin()+j+1, a.end());
			}
		}
		else {
			begin = k/tot;
			end = 0;
			swap(a[0], a[begin-1]);
			sort(a.begin()+1, a.end());
			reverse(a.begin()+1, a.end());
		}

		string ans;
		for(auto i : a) {
			char t = '0'+i;
			ans.push_back(t);
		}
		return ans;
	}		
};

class Solution {//0ms
public:
	string getPermutation(int n, int k) {
		int i,j,f=1;
		string s(n,'0');
		for(int i=1; i<=n; i++) {
			f *= i;
			s[i-1] += i;
		}

		for(i=0,k--; i<n; i++) {
			f /= n-i;
			j = i+k/f;
			char c = s[j];
			for(; j>i; j--) s[j] = s[j-1];
			k %= f;
			s[i] = c;
		}
		return s;
	}
};
