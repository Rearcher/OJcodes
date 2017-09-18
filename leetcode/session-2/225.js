// implement stack using queues
/**
 * @constructor
 */
var Stack = function() {
    this.queue1 = [];
    this.queue2 = [];
};

/**
 * @param {number} x
 * @returns {void}
 */
Stack.prototype.push = function(x) {
    this.queue1.push(x);
};

/**
 * @returns {void}
 */
Stack.prototype.pop = function() {
    while (this.queue1.length > 0) {
        this.queue2.push(this.queue1.shift());
    }
    while (this.queue2.length > 1) {
        this.queue1.push(this.queue2.shift());
    }
    this.queue2.shift();
};

/**
 * @returns {number}
 */
Stack.prototype.top = function() {
    while (this.queue1.length > 0) {
        this.queue2.push(this.queue1.shift());
    }
    while (this.queue2.length > 1) {
        this.queue1.push(this.queue2.shift());
    }
    var ans = this.queue2.shift();
    this.queue1.push(ans);
    return ans;
};

/**
 * @returns {boolean}
 */
Stack.prototype.empty = function() {
    return this.queue1.length === 0;
};
