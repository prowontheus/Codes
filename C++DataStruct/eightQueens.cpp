//
// Created by 丁月星 on 2020/7/19.
//

#include "eightQueens.h"
#include <iostream>

int eightQueens::numofsolution = 0;

eightQueens::eightQueens(int n):queens(n)
{
    column = new int[n];
    vertical = new bool[n];
    left  = new bool[2 * n -1];
    right = new bool[2 * n - 1];
    for(int i = 0;i < n;i++)
    {
        column[i] = -1;
        vertical[i] = true;
    }
    for(int i = 0;i < 2*n - 1;i++)
    {
        left[i] = true;
        right[i] = true;
    }
}

void eightQueens::putQueen(int row)
{
    for(int col = 0; col < queens;col++)
    {
        if(vertical[col] == true && left[col+row] == true && right[col-row+queens-1] == true)
        {
            column[row] = col;
            vertical[col] = false;
            left[col+row] = false;
            right[col-row+queens-1] = false;
            if(row < queens - 1)
                putQueen(row+1);
            else
                printSolution();
            vertical[col] = true;
            left[col+row] = true;
            right[col-row+queens-1] = true;
        }
    }
}

void eightQueens::printSolution()
{
    numofsolution++;
    for(int i = 0;i < queens;i++)
    {
        for(int j = 0;j < queens;j++)
        {
            if(j == column[i])
                std::cout << "👑";
            else
                std::cout << "〇";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int n = -1;
    std::cout << "请输入棋盘的规格，行数=列数=皇后数量=";
    while(std::cin >> n)
    {
        if(n < 3)
            std::cout << "棋盘规格太小或者规格错误,请重新输入..." << std::endl;
        else
            break;
    }
    eightQueens queen(n);
    queen.putQueen();
    std::cout << "一共找到" << queen.numofsolution << "种解法" << std::endl;
    return 0;
}