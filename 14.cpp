//
//  main.cpp
//  quiz
//
//  Created by Duo Donald Zhao on 11/20/13.
//  Copyright (c) 2013 Duo Donald Zhao. All rights reserved.
//

#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

const uint64_t N = 1e6;
vector<uint64_t> cSize(N + 1,0);
typedef uint64_t INT_TYPE; // int is not OK here

int main(int argc, char *argv[]){
    INT_TYPE maxCize = 0;
    INT_TYPE maxIndex = 0;
    INT_TYPE maxReach = 0;
    for (INT_TYPE i = 1; i <= N; i++) {
        INT_TYPE trace = i;
        INT_TYPE iSize = 1;
        while (trace > 1){
            iSize++;
            if (cSize[i] != 0){
                iSize += cSize[i];
                break;
            }
            trace = (trace & 1) ? (3 * trace + 1) : trace/2;
            maxReach = max (maxReach, trace);
        }
        if (iSize > maxCize){
            maxCize = iSize;
            maxIndex = i;
        }
        cSize[i] = iSize;
    }
    cout << maxIndex << endl;
    cout << maxCize << endl;
    cout << maxReach << endl;
    return 0;
}
