//
// Created by Indira on 5/27/21.
//
#include <iostream>
#include <vector>

#ifndef UNTITLED1_TASK25_H
#define UNTITLED1_TASK25_H

class Task25 {
     std::vector<std::string> sumVector(std::vector<std::string> first, std::vector<std::string> second) {
            std::string bpart, apart, mantissa;
            std::vector<std::string> result = {};
            unsigned long itemb, itema, itemNew;

            int maxIdxFirst = first.size() - 1;

            for (int i = (second.size() - 1); i >= 0; i--, maxIdxFirst--) {
                // std::cout <<i<<" index "<<std::endl;
                bpart = second.at(i);
                // std::cout <<i<<" bpart "<< bpart<< std::endl;
                if (maxIdxFirst >= 0) {
                    apart = first.at(maxIdxFirst);
                } else {
                    apart = "0";
                }

                itemb = std::stoul(bpart, nullptr, 10);
                itema = std::stoul(apart, nullptr, 10);
                itemNew = itemb + itema;

                if (mantissa.length() > 0) {
                    itemNew += std::stoul(mantissa,nullptr, 10); // добавляем предыдущий остаток
                }

                mantissa = std::to_string(itemNew);

                if (mantissa.length() <= 10) {
                    result.insert(result.begin(), mantissa.substr(0, 10));
                    mantissa = "0";
                } else {
                    result.insert(result.begin(), mantissa.substr(mantissa.length() - 10, 10));
                    mantissa = mantissa.substr(0, mantissa.length() - 10);
                }
            }

            if (mantissa.length() > 0 && mantissa != "0") {
                result.insert(result.begin(), mantissa);
            }
            // std::cout <<"end function" << std::endl;
            return result;
        }
    public:
        void calc() {
            unsigned long a = 1, b = 1, c = 1, idX = 2;
            std::vector<std::string> fibNew = {};
            std::vector<std::string> fibA = {};//{"6032783461"};//{"7778742049"};
            std::vector<std::string> fibB = {};//{"9496489168"};//{"1", "7778742049"};

            //fibNew = sumVector(fibA, fibB);
            //return;
            while (fibNew.size() < 101) {
                idX = idX + 1;
                if (c < 990000001) {
                    a = b; b = c;
                    c = a + b;
                } else if (!fibA.empty() || !fibB.empty()){
                    fibA = fibB;
                    fibB = fibNew;

                    fibNew = sumVector(fibA, fibB);
                } else {
                    fibA.push_back(std::to_string(b));
                    fibB.push_back(std::to_string(c));
                    fibNew = sumVector(fibA, fibB);
                }

                if (fibNew.size() == 100 && fibNew.at(0).length() == 10) {
                    break;
                }
            }
            std::cout << idX << std::endl;
        }
};


#endif //UNTITLED1_TASK25_H
