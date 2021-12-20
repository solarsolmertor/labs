int main() {
    // changing values with temp variable
    double firstWithTemp = 3, secondWithTemp = -7, temp; // initial values
    temp = firstWithTemp; // writing first value into temp
    firstWithTemp = secondWithTemp; // writing second value into first value
    secondWithTemp = temp; // writing first value from temp

    // changing values without temp variable
    double firstWithoutTemp = 3, secondWithoutTemp = -7; // initial values
    firstWithoutTemp += secondWithTemp; // writing sum of first and second value into first
    secondWithTemp = firstWithoutTemp - secondWithTemp; // calculating second value substracting first from second
    firstWithoutTemp -= secondWithTemp; // calculating first value the same way
    return 0;
}
