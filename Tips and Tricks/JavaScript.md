* `~undefined === -1`

* With `a = -~a` you can make an incrementer of `a` just like `a += 1` or `++a`, but with the additional feature that
if `a` has a value of undefined or null it will get a value of 1 after the first time (Something like it having
a default value of 0).

* The Order of insertion for non-integer string properties in an obejct is preserved. See
[This](https://stackoverflow.com/questions/5525795/does-javascript-guarantee-object-property-order) for more details.

* When `Date` objects are converted automatically to privmitives, the `toString` method is used directly without
consulting `valueOf` first to see if it returns a primitive type.