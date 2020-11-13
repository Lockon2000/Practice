/**
 * Initialize your data structure here.
 * @param {number} size
 */
var MovingAverage = function(size) {
    this.queue = new Queue();
    this.limit = size;
    this.sum = 0;
};

/** 
 * @param {number} val
 * @return {number}
 */
MovingAverage.prototype.next = function(val) {
    if (this.queue.size() < this.limit) {
        this.queue.enqueue(val);
        
        this.sum = this.sum + val;
    } else {
        const removed = this.queue.dequeue();
        this.queue.enqueue(val);
        
        this.sum = this.sum - removed + val;
    }
    
    return this.sum / this.queue.size();
};

/** 
 * Your MovingAverage object will be instantiated and called as such:
 * var obj = new MovingAverage(size)
 * var param_1 = obj.next(val)
 */