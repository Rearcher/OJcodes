#ifndef _LEETCODE_HPP_
#define _LEETCODE_HPP_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <cstdlib>
#include <ctime>

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

#endif