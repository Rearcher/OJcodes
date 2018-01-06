// Implement Queue using Stacks
/**
 * @constructor
 */
var Queue = function() {
    this.stack1 = [];
    this.stack2 = [];
};

/**
 * @param {number} x
 * @returns {void}
 */
Queue.prototype.push = function(x) {
    this.stack1.push(x);
};

/**
 * @returns {void}
 */
Queue.prototype.pop = function() {
    while (this.stack1.length > 0) {
        var temp = this.stack1.pop();
        this.stack2.push(temp);
    }
    
    var ans = this.stack2.pop();
    
    while (this.stack2.length > 0) {
        var temp2 = this.stack2.pop();
        this.stack1.push(temp2);
    }
    
    return ans;
};

/**
 * @returns {number}
 */
Queue.prototype.peek = function() {
    while (this.stack1.length > 0) {
        var temp = this.stack1.pop();
        this.stack2.push(temp);
    }
    
    var ans = this.stack2.pop();
    this.stack1.push(ans);
    while (this.stack2.length > 0) {
        var temp2 = this.stack2.pop();
        this.stack1.push(temp2);
    }
    
    return ans;
};

/**
 * @returns {boolean}
 */
Queue.prototype.empty = function() {
    return this.stack1.length === 0;
};
