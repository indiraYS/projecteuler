//
// Created by Indira on 08.04.2021.
//

#ifndef UNTITLED1_TASK9_H
#define UNTITLED1_TASK9_H
#include "iostream"
#include "string"
#include <algorithm>
#include <vector>
using namespace std;

class Task9 {
public:
    void calc() {
        double x;
        int c,b;

        for (int i = 500; i > 0; i-- ) {
            c = i;//arr.at(i);

            for (int j = 1; j < i; j++) {
                b = j;
                x = sqrt(pow(c,2) - pow(b,2));

                if ((double (c + b) + x) == 1000) {
                    cout << "a = "<< x <<", b = "<< b <<", c = "<< c << endl;
                    //return;
                }
            }
        }
        cout << "abc = "<< x * b * c << endl;
    }
};


#endif //UNTITLED1_TASK9_H
