#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <list>

#ifndef UNTITLED1_TASK24_H
#define UNTITLED1_TASK24_H


using namespace std;
class Task24 {
    struct classcomp {
        bool operator() (const std::string& lhs, const std::string& rhs) const
        {
            return stol(lhs) < stol(rhs);
        }
    };
public:
    string curStr = "0123";
    void calc() {
        vector<string> x;
        string arr;
        chain(arr, x);

//        string test = "9876543211";
//        if (isReverse(test)) {
//            cout << "ok  "<< endl;
//        } else {
//            cout << "no  "<< endl;
//        }
         //chain(0, mutableString, xSet);
         //chain(0, mutableString, xSet);
//        for (int j = 0; j <= curStr.length()-1; j++) {
//
//            xSet.insert(curStr);
//            if (j + 1 < curStr.length()) {
//                mix(j, j+1, curStr);
//            } else {
//                mix(0,j,curStr);
//            }
//            xSet.insert(curStr);
//
//            for (int i = 0; i <= curStr.length()-1;  i++) {
//                xSet.insert(curStr);
//                if (i + 1 < curStr.length()) {
//                    mix(i, i+1, curStr);
//                } else {
//                    mix(i,j,curStr);
//                }
//                xSet.insert(curStr);
//            }
//        }


    }

    /*static void mix(int i, int j, std::string &str) {
        char xTmp = str[i];
        str[i] = str[j];
        str[j] = xTmp;
    }

    static bool isReverse(std::string &str) {
        static string strx = "0123456789";
        for (int i = 0; i <= str.length() - 1; i++) {
            if (str[i] != strx[str.length() -1 - i]) {
                return false;
            }
        }
        return true;
    }*/

    static void chain(string arr, vector<string> &pSet) {
        string numbers[10] = {"0","1","2","3",  "4", "5", "6", "7", "8", "9"};
        int arrSize = arr.size();
        int idxMax = 3628800;
        for (int i = sizeof(numbers)/sizeof(numbers[0]) - 1; i >= 0; i --) {
            if (arr.find(numbers[i]) != string::npos) {
                continue;
            }

            if (arrSize == 9) {
                pSet.push_back(numbers[i] + arr);

                if (pSet.size() == idxMax/*3628800*/) {
                    sort(pSet.begin(), pSet.end());
                    cout << ">> " << "i = " << (pSet.size() - 1) << ", " << pSet[pSet.size() - 1] << "\t" << endl;
                    cout << ">> "<<pSet[999999] << "\t" << endl;
                    return;
                }
            } else {
                chain(numbers[i] + arr, pSet);
            }
        }
    }

    /*static void chain(int startIndex, std::string &str, set<std::string> &pSet) {
        //std::string subStr = str;
        // chain(startIndex, subStr, pSet);
        std::string newStr;
        pSet.insert(str);


        if (startIndex > str.length() - 1) return;

        try {
            for (int i = startIndex; i <= str.length() - 1; i++) {
                if (i < str.length() - 1) {
                    mix(i, i - 1, str);
                    pSet.insert(str);
                } else {
                    mix(startIndex, i, str);
                    startIndex ++;
                    chain(startIndex, str, pSet);
                }

                if (isReverse(str)){
                    return;
                }
            }
        } catch(const std::runtime_error& re)
        {
            // speciffic handling for runtime_error
            std::cerr << "Runtime error: " << re.what() << std::endl;
        }
        catch(const std::exception& ex)
        {
            // speciffic handling for all exceptions extending std::exception, except
            // std::runtime_error which is handled explicitly
            std::cerr << "Error occurred: " << ex.what() << std::endl;
        }
        catch(...)
        {
            // catch any other errors (that we have no information about)
            std::cerr << "Unknown failure occurred. Possible memory corruption" << std::endl;
        }

        // chain(startIndex + 1, subStr, pSet);
        // chain(startIndex + 1, subStr, pSet);
    }*/
};


#endif //UNTITLED1_TASK24_H
