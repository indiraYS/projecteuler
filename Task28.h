//
// Created by Indira on 6/4/21.
#include <iostream>
#include <vector>

#ifndef UNTITLED1_TASK28_H
#define UNTITLED1_TASK28_H


class Task28 {

    private:
    int** bld() {
        int** a = 0;
        a = new int*[1001];
        for (int i = 0; i < 1001; i ++) {
            a[i] = new int[1001];
        }

        int x = 0, y = 1000 , excIdx = 1001, curVal = 1001*1001;

        //std::cout<< a[i][j] <<std::endl;
        //return a;
        bool isX = false; // флаг направления
        bool isMinus = true;
        while (curVal > 0) {
            a[x][y] = curVal;
            //std::cout << "a[" << x << "][" << y << "] = " << curVal << std::endl;

            if (!isX) {
                if (isMinus) {
                    if ((y-1) >= 0  && a[x][y-1]==0 ) {
                        y--;
                    } else {
                        x++;
                        isX = true;
                        isMinus = false;
                    }
                } else {
                    if ((y+1) < excIdx  && a[x][y+1]==0 ) {
                        y++;
                    } else {
                        x--;
                        isX = true;
                        isMinus = true;
                    }
                }
            } else {
                if (isMinus) {
                    if ((x-1) >= 0  && a[x-1][y]==0 ) {
                        x--;
                    } else {
                        y--;
                        isX = false;
                        isMinus = true;
                    }
                } else {
                    if ((x+1) < excIdx  && a[x+1][y]==0 ) {
                        x++;
                    } else {
                        y++;
                        isX = false;
                        isMinus = false;
                    }
                }
            }
            curVal = curVal - 1;
        }

        return a;
    }

    public:
        void calc() {
        int** a = bld();

        printf("first is %i,", a[0][1000]);
        printf("central is %i,", a[500][500]);
        std::cout << "=====================================" << std::endl;

        int y = 1000;
        int sum = 0; int item, itemsecond;
        for (int x = 0; x < 1001; x++)
        {
            if (x != 500 && y !=500) {
                item = *(*(a + x) + y);
                itemsecond = *(*(a + x) + (1000-y));
                sum = sum + item + itemsecond;//a[1000-x][1000-y];
            }
            y--;
        }

        sum = sum + 1;//(sum - 1)* 2;

        printf("sum %i,", sum); //669171001
    }
};


#endif //UNTITLED1_TASK28_H
