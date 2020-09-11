//
// Created by 丁月星 on 2020/7/19.
//

#ifndef A_OUT_EIGHTQUEENS_H
#define A_OUT_EIGHTQUEENS_H


class eightQueens {
public:
    eightQueens(int n = 4);
    void putQueen(int row = 0);
    void printSolution();
    static int numofsolution;
private:
    int queens;//皇后的个数=行数=列数
    int *column;//各个皇后所在的列数。第1行放第一个皇后，第2行放第二个皇后，以此类推。
    bool *vertical;//所有的竖直方向(数量=queens)是否有皇后存在
    bool *left; //所有的左对角线(数量=2*queens-1)是否有皇后存在
    bool *right;//所有的右对角线(数量=2*queens-1)是否有皇后存在
};


#endif //A_OUT_EIGHTQUEENS_H
