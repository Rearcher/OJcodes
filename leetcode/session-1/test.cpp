#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <utility>
#include <map>
using namespace std;

#define INT_MIN (1<<31)
#define INT_MAX 0x7fffffff

void print(vector<string> a) {
	for(auto i : a) 
		cout << i << endl;
}

void print(vector<int> a) {
	for(auto i : a)
		cout << i << " ";
	cout << endl;
}

void print(vector<vector<int> > a) {
	for(auto i : a) {
		for(auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}


void print(vector<vector<string> > a) {
	for(auto i : a) {
		for(auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

void print(ListNode *a) {
	ListNode *p=a;
	while(p!=nullptr) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
//========================================================
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int begin{0}, tank{0}, total{0};
		for(unsigned int i=0; i<gas.size(); i++) {
			tank += gas[i]-cost[i];
			if(tank < 0) {
				total += tank;
				tank = 0;
				begin = i+1;
			}
		}
		if(total+tank<0) return -1;
		return begin;
	}
		int begin{0}, tank{0}, total{0};
		for(unsigned int i=0; i<gas.size(); i++) {
			tank += gas[i]-cost[i];
			if(tank < 0) {
				total += tank;
				tank = 0;
				begin = i+1;
			}
		}
		if(total+tank<0) return -1;
		return begin;
	}

int main() {
	
}


