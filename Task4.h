//
// Created by Indira on 4/6/21.
//

#ifndef UNTITLED1_TASK4_H
#define UNTITLED1_TASK4_H
#include "iostream"
#include "string"
#include <algorithm>
using namespace std;

class Task4 {
    public:
        static bool isPolindrom(unsigned a) {
            string str = std::to_string(a);

            for (unsigned i = 0, j = (str.length()-1);
                    i < (str.length()/2);
                    i++, j--)
            {
                // cout << "i = "<<i<<", char = " << str.at(i)<<", j = " <<j<<", char = "<< str.at(j) << endl;
                if (str.at(i) != str.at(j)) {
                    return false;
                }
            }
            return true;
        }

        void calc() {
            cout << "task4"<< endl;
//            cout << "is pol "<< isPolindrom(9900099)<<endl;
//            cout << "is pol "<< isPolindrom(14641)<<endl;
//            cout << "is pol "<< isPolindrom(899198)<<endl;
//            cout << "is pol "<< isPolindrom(33312333)<<endl;
//            cout << "is pol "<< isPolindrom(33300333)<<endl;
//            cout << "is pol "<< isPolindrom(111111)<<endl;
//            return;
            int pollist[99] = {};
            int b = 1, poldx = 0;
            unsigned step = 0;
            //while (!is_found) {
            for (unsigned j = 999; j >= 900; j--) {
                for (unsigned i = 900; i <= 999; i++) {
                    step++;
                    b = i * j;
                    if (isPolindrom(b)) {
                        poldx ++;
                        pollist[poldx] = b;
                        cout << "polindrom found: " << b << ", on step: "<<step<<", a = "<< i <<", j = "<<j<<endl;
                        break;
                    }
                }
            }

            cout << *max_element(begin(pollist), end(pollist)) <<endl;
        }
};


#endif //UNTITLED1_TASK4_H
