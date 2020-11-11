function solution(A) {
    let purse = new Set(A);
    
    for (let i = 1; i <= 1000000; ++i) {
        if (!purse.has(i)) return i;
    }
    
    return;
}