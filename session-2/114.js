/**
 * flatten binary tree to linked list
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) {
    
    if (!root) return;
    
    var leftTree = root.left;
    var rightTree = root.right;
    var curNode = root;
    root.left = root.right = null;
    
    
    var preOrder = function (rt) {
        if (!rt) return;
        
        var stack = [rt];
        while (stack.length > 0) {
            var tmpNode = stack.pop()
            if (tmpNode.right) {
                stack.push(tmpNode.right);
            }
            
            if (tmpNode.left) {
                stack.push(tmpNode.left);
            }
            
            tmpNode.left = null;
            curNode.right = tmpNode;
            curNode = curNode.right;
        }
    }
    
    preOrder(leftTree);
    preOrder(rightTree);
    
};
