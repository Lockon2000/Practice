function solution(A) {
    const a = A.filter(x => x > 0).sort((a,b) => a-b);
    
    let num = 1;
    for (let i = 0; i < a.length; ++i) {
        if (a[i] > num) {
            break;
        } else if (a[i] === num) {
            ++num;
        }
    }
    
    return num;
}