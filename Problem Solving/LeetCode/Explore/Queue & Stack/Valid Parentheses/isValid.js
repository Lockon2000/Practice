/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    const stack = [];

    for (let i = 0; i < s.length; ++i) {
        if (['(', '[', '{'].includes(s[i])) {
            stack.push(s[i]);
        } else {
            switch (s[i]) {
                case ')':
                    if (stack[stack.length - 1] !== '(') return false;
                    break;
                case ']':
                    if (stack[stack.length - 1] !== '[') return false;
                    break;
                case '}':
                    if (stack[stack.length - 1] !== '{') return false;
                    break;
            }

            stack.pop();
        }
    }
    
    if (stack.length !== 0) {
        return false;
    } else {
        return true;
    }
};


console.log(isValid('()'));