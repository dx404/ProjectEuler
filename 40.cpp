// Champernowne's constant

#include <iostream>
#include <cmath>
using namespace std;
const int bound = 1e6;

int main(int argc, char *argv[]){
    int currentBitLen = 0;
    int culen = 0;
    int lenMark = 1;
    int product = 1;
    for (int i = 1; i <= bound; i++){
        if ( i == (int) pow(10, currentBitLen)){
            currentBitLen++;
        }
        culen += currentBitLen;
        if (culen >= lenMark){
            product *= int(i / pow(10, culen - lenMark)) % 10;
            lenMark *= 10;
        }
    }
    cout << product << endl;
    return 0;
}
