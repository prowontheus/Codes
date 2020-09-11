//
// Created by 丁月星 on 2020/8/21.
//用堆实现Dijkstra算法
//

#ifndef A_OUT_DIJKSTRA_DYX_H
#define A_OUT_DIJKSTRA_DYX_H
#include <iostream>
#include <queue>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

using ituple = tuple<int,int>;

struct edge{
public:
    edge(int i,int j):out(i),length(j){}
    bool friend operator>(edge e1,edge e2)
    {
        return e1.length > e2.length;
    }
    int out;
    int length;
};

class Dijkstra{
public:
    Dijkstra();
    void InputVertexAndEdges();//输入顶点和边
    bool IsValid(){return IsValid(m_vertexs,m_edges);}//判断输入的是否是权值为正的单源有向图
    bool IsValid(vector<int> &vertexs,vector<vector<ituple/*edge*/>> &edges);
    int GetNumOfEdges(){
        int size = 0;
        for(auto r:m_edges)
        {
            size += r.size();
        }
        return size;
    }//获取边的数量
    void setvertexs(int num);
    void setedges();
    void split_string( const string & str, vector<string> & words );
    auto Dijkstra_dyx(int first = 0);
    void printsolution(vector<int> dist);
private:
    int m_NumOfVertesx;
    int m_NumOfEdges;
    vector<int> m_vertexs;//存储顶点
    vector<vector<ituple/*edge*/>> m_edges; //储存边和权值,元组里第一个参数是出顶点，第二个参数是入顶点，第三个参数是权值
                                            // 若边是双向的，则必须储存两对元组值
};

template<typename T=ituple>
struct comp_tuple{
    bool operator()(const T &t1,const T &t2)
    {return t1 < t2;}
};

//template<>
//struct comp_tuple<ituple>{
//    bool operator()(ituple &tuple1,ituple &tuple2)
//    { return get<1>(tuple1) > get<1>(tuple2); }
//};
#endif //A_OUT_DIJKSTRA_DYX_H
