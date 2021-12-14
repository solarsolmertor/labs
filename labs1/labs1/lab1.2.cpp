#include "math.h"

int main() {

    double firstSide = 4, secondSide = 2, thirdSide = 3; // initial values
    double perimeter = (firstSide + secondSide + thirdSide) / 2; // formula of perimeter
    double square = sqrt(perimeter * (perimeter - firstSide) * (perimeter - secondSide) * (perimeter - thirdSide)); // formula of square
}