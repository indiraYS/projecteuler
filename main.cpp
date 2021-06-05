#include <iostream>
#include "Task4.h"
#include "Task9.h"
#include "Task13.h"
// #include "Task24.h"
#include "Task25.h"
#include "Task28.h"
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;

static bool isSimpleNumber(long x) {
    int arr [27] = {2,3,5,7,11, 13, 17,19,23, 29,31,37,41,43,47,53, 59,61,67,71,73, 79, 83, 89,97};

    bool found = (std::find(begin(arr), end(arr), x) != end(arr));
    if (found) return true;

    for (int i = 0 ; i < sizeof(arr); i++) {
        if (x%arr[i] == 0) {
            return false;
        }
    }
    return true;
};

static long euclid(long a, long b) {
    while (a != 0 && b!=0 ) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return (a + b);
}

class Task3 {

public:
    void calc() {
        cout << "calc begin "<< endl;
        long x = 600851475143;

        vector<long> arr = {2,3,5,7,11,13, 17,19,23, 29,31,37,41,43,47,53, 59,61,67,71,73, 79, 83, 89,97};

        long n = 97;
        while (n <= sqrt(x)) {
            for (int  i = 0;  i < arr.size(); i++) {
                if (n % arr[i] != 0) {
                    arr.push_back(n);
                    break;
                }
            }
            n = n + 2;
        }
        // cout << "max " << arr.at(10000) << endl; //104761 -10001
        // return;
        long next; long pairNumber;
        /*for (int i = (arr.size()-1); i > -1; i--) {
            next = arr.at(i);
            if (x % next == 0) {
                pairNumber = x / next;
                cout << "multiplier " << pairNumber << " | next simple: " << next << endl;
            }
        }*/
        for (int i = 0; i < (arr.size()-1); i++) {
            next = arr.at(i);
            if (x % next == 0) {
                pairNumber = x / next;
                cout << "multiplier " << pairNumber << " | next simple: " << next << endl;
            }
        }
    };
};



class Task3__z {

public:
    void calc() {
        cout << "calc begin " << endl;
        long x = 50000000; // 600851475143;
        vector<long> arr = {2,3};

        long n = 3;
        while (n <= x) {
            for (int  i = 0;  i < arr.size(); i++) {
                if (n % arr[i] == 0) {
                    goto nextPotentialSimple;
                }
            }
            arr.push_back(n);
            nextPotentialSimple:
            n = n + 2;
        }
        // cout << "max " << arr.at(10000) << endl; //104761 -10001
        // return;
        // After function call
    };
};

class Task2 {
public:
    void calc() {
        int amnt = 0;
        int a2 = 1;
        int a1;
        int next = 1;
        int step = 0;

        while (next <= 4000000) {
            step += 1;
            a1 = a2;
            a2 = next;
            next = a2 + a1;
            cout << "step: " << step << " | a1: " << a1 << "| a2:" << a2 << endl;
            if (a2 % 2 == 0) {
                amnt += a2;
            }
        }
        cout << amnt << endl;
    };
};

int main() {
    cout << "Hello, World!" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    //Task2 t; t.calc();
    //Task3__z t; t.calc();
    //Task4 t4; t4.calc();
    //Task9 t9; t9.calc();
    /*long a = (600851475143 - 3) / 2, b = 2, c;
    c = euclid(a, b);
    cout << "euclid " << c << endl;*/
    //Task13 t; t.calc();
    //Task24 t; t.calc();
    Task28 t; t.calc();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Duration in micro: " <<duration.count() << endl;
    return 0;
}
