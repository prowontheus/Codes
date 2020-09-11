//
// Created by 丁月星 on 2020/7/20.
//
#include <iostream>
#include <stack>
#include <vector>
#include <ctime>

const int maze1[8][8]={
        {0,0,1,1,1,1,1,1},
        {0,0,1,1,0,1,1,0},
        {1,1,0,0,1,0,0,1},
        {1,1,0,0,1,0,0,1},
        {1,0,1,1,0,1,1,0},
        {1,1,0,0,1,0,0,1},
        {1,1,0,0,1,0,0,1},
        {1,0,1,1,0,1,1,0}
};
const int maze2[8][8]={
        {1,0,0,1,1,0,1,1},
        {0,0,0,0,1,0,1,1},
        {1,1,1,0,0,1,1,1},
        {1,0,1,0,1,1,0,0},
        {1,0,1,1,1,0,1,0},
        {1,0,0,0,0,1,1,1},
        {1,0,1,0,0,1,1,1},
        {1,0,1,0,0,1,1,1}
};
struct point
{
    point(int a,int b):x(a),y(b){}
    int x;
    int y;
};

class Maze{
public:
    Maze(const int m[][8]);
    void printarr();
    void InitMaze(const int m[][8]);
    void findMaze(int r=0,int c=0);//
    void nextstep(int row,int col);//下一步走法
    friend std::ostream & operator<<(std::ostream &os,const Maze &m)
    {
        os << "一共有" << m.m_numofresult.size() << "个白色单元，每个单元对应的白色方块数为：" << std::endl;
        for(auto &r:m.m_numofresult)
            os << r << "块" << std::endl;
        os << std::endl;
        return os;
    };
private:
    int max_num = 0;
    int maze_arr[10][10];
    std::vector<int> m_numofresult;
    std::stack<point,std::vector<point>> m_data;
};

Maze::Maze(const int m[][8])
{
    max_num = 0;
    m_numofresult.clear();
    InitMaze(m);
}

void Maze::printarr()
{
    for(int i = 0;i < 10;i++)
    {
        for(int j = 0;j < 10;j++)
            std::cout << maze_arr[i][j];
        std::cout << std::endl;
    }
}

void Maze::InitMaze(const int m[][8])
{
    for(int i = 0;i < 10;i++)
    {
        for(int j = 0;j < 10;j++)
        {
            if(i <= 0 || i >= 9 || j <= 0 || j >= 9)
            {
                maze_arr[i][j] = 0;
                continue;
            }
            maze_arr[i][j] = m[i-1][j-1];
        }
    }
}

void Maze::findMaze(int r, int c)
{
    for(int row = r,col = c;row < 8;row++)
    {
        if(row != r)
            col = 0;
        for(;col < 8;col++)
        {
            if(maze_arr[row+1][col+1] == 1)
            {
                maze_arr[row+1][col+1] = 2;
                max_num++;
                nextstep(row,col);
            }
            else if(maze_arr[row+1][col+1] == 2)
                nextstep(row,col);
        }
    }
}

void Maze::nextstep(int row, int col)
{
    if(maze_arr[row][col+1] == 1 || maze_arr[row+1][col] == 1 || maze_arr[row+2][col+1] == 1 || maze_arr[row+1][col+2] == 1)
    {
        m_data.push(point(row,col));
        if(maze_arr[row][col+1] == 1)
             findMaze(row-1, col);
        else if(maze_arr[row+1][col] == 1)
            findMaze(row, col-1);
        else if(maze_arr[row+2][col+1] == 1)
            findMaze(row + 1, col);
        else if(maze_arr[row+1][col+2] == 1)
            findMaze(row, col+1);
    }
    if(!m_data.empty())
    {
        point po = m_data.top();
        m_data.pop();
        findMaze(po.x,po.y);
    }
    else if(max_num != 0)
    {
        m_numofresult.push_back(max_num);
        max_num = 0;
    }
}

int main()
{
    //5-13-3
    Maze m1(maze1);
    Maze m2(maze2);
    clock_t starttime,endtime;
    starttime = clock();
    m1.findMaze(0,0);
    m2.findMaze(0,0);
    std::cout << m1;
    std::cout << m2;
    endtime = clock();
    std::cout << "程序耗时:" << (double)(endtime - starttime) << std::endl;
    return 0;
}
