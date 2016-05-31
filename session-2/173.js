/* binary search tree iterator */
/**
 * Definition for binary tree
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * @constructor
 * @param {TreeNode} root - root of the binary search tree
 */
var BSTIterator = function(root) {
    this.stack = [];
    
    var tmpNode = root;
    while (tmpNode) {
        this.stack.push(tmpNode);
        tmpNode = tmpNode.left;
    }
};


/**
 * @this BSTIterator
 * @returns {boolean} - whether we have a next smallest number
 */
BSTIterator.prototype.hasNext = function() {
    return this.stack.length > 0;
};

/**
 * @this BSTIterator
 * @returns {number} - the next smallest number
 */
BSTIterator.prototype.next = function() {
    var tmpNode = this.stack.pop();
    
    var tNode = tmpNode.right;
    while (tNode) {
        this.stack.push(tNode);
        tNode = tNode.left;
    }
    
    return tmpNode.val;
};

/**
 * Your BSTIterator will be called like this:
 * var i = new BSTIterator(root), a = [];
 * while (i.hasNext()) a.push(i.next());
*/
