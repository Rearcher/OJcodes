/**
 * Path Sum II
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number[][]}
 */
var pathSum = function(root, sum) {
    
    if (!root) return [];
    
    var res = [];
    var singleRes = [root.val];
    var add = root.val;
    
    var dfs = function (head) {
        if (!head.left && !head.right) {
        	if (add === sum) {
				res.push(singleRes.slice(0));
			}
			return;
		}
        
        
        if (head.left) {
            singleRes.push(head.left.val);
            add += head.left.val;
            
            dfs(head.left);
            
            singleRes.pop();
            add -= head.left.val;
        }
        
        if (head.right) {
            singleRes.push(head.right.val);
            add += head.right.val;
            
            dfs(head.right);
            
            singleRes.pop();
            add -= head.right.val;
        }
        
    }
    
    dfs(root);
    
    return res;
};
