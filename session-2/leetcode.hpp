#ifndef _LEETCODE_HPP_
#define _LEETCODE_HPP_

#include <iostream>
#include <sstream>

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <numeric>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

#endif