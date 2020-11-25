function throttle(func, ms) {
    let timeout;
    let lastThis;
    let lastArguments;

    return function () {
        if (!timeout) {
            timeout = setTimeout(() => {
                if (lastThis && lastArguments) {
                    func.apply(lastThis, lastArguments);

                    lastThis = null;
                    lastArguments = null;
                }

                timeout = null;
            }, ms);

            return func.apply(this, arguments);
        } else {
            lastThis = this;
            lastArguments = arguments;
        }
    }
}