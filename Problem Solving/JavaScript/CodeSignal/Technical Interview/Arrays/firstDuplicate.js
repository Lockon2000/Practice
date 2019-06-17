// Time Complexity O(n) and Space Complexity O(1)

function firstDuplicate(a) {
    let length = a.length
    
    for (let i of a) {
        if (i > length) {
            i -= length
        }
        
        if (a[i-1] <= length) {
            a[i-1] += length
        } else {
            return i
        }
    }
    
    return -1
}
