/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParity = function(A) {
    for (let i = A.length; i >= 0; --i) {
        if (A[i] % 2 !== 0) {
            A.push(A[i]);
            A.splice(i, 1);
        }
    }
    
    return A;
};