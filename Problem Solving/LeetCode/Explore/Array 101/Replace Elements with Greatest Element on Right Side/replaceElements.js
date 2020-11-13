var replaceElements = function(arr) {
    let maximum = -1;
    
    for (let i = arr.length - 1; i >= 0; --i) {
        const tmp = arr[i];
        
        arr[i] = maximum;
        
        if (tmp > maximum) {
            maximum = tmp;
        }
    }
    
    return arr;
};

console.log(replaceElements([17,18,5,4,6,1]));