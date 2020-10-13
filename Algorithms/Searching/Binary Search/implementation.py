def binary_search(input_array, value):
    if len(input_array) == 0:
        return -1
    
    lInd = 0
    hInd = len(input_array) - 1
    
    while lInd < hInd:
        mInd = (lInd+hInd)//2
        if input_array[mInd] == value:
            return mInd
        elif input_array[mInd] < value:
            lInd = mInd + 1
        else:
            hInd = mInd     # Not mInd - 1 to make sure that if the loop is going to exit then lInd
                            # and hInd are equal (lenght of remaining list == 1)
    
    # Test with lInd or hInd, as both are equal at this point
    if input_array[lInd] == value:
        return lInd
            
    return -1


test_list = [1,2,3,4,9,11,15,19,29]
test_val = 17
print(binary_search(test_list, test_val))