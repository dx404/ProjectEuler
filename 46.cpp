//
//  Created by Duo Donald Zhao on 11/20/13.
//  Copyright (c) 2013 Duo Donald Zhao. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

bool primeQ(int n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]){
    for (int i = 1;; i+=2){
        if (primeQ(i)){
            continue;
        }
        bool status = false;
        int bmax = 1 + (int) sqrt(i/2 + 1);
        for (int b = 1; b <= bmax; b++) {
            int a = i - 2 * b * b;
            if (a > 0 && primeQ(a)){
                status = true;
                //cout << "(" << i << ", " << a << ", " << b << ")" << endl;
                break;
            }
        }
        if (!status){
            cout << "--->" <<i << endl;
            break;
        }
    }
    return 0;
}
