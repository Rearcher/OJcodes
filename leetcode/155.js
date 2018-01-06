// min stack
/**
 * @constructor
 */
var MinStack = function() {
    this.stack = [];
    this.min = [];
};

/**
 * @param {number} x
 * @returns {void}
 */
MinStack.prototype.push = function(x) {
    this.stack.push(x);
    if (this.min.length === 0) {
        this.min.push(x);
    } else {
        var t = this.min.pop();
        this.min.push(t);
        this.min.push(Math.min(t, x));
    }
};

/**
 * @returns {void}
 */
MinStack.prototype.pop = function() {
    this.stack.pop();
    this.min.pop();
};

/**
 * @returns {number}
 */
MinStack.prototype.top = function() {
    var t = this.stack.pop();
    this.stack.push(t);
    return t;
};

/**
 * @returns {number}
 */
MinStack.prototype.getMin = function() {
    var t = this.min.pop();
    this.min.push(t);
    return t;
};
