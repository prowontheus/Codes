//
// Created by 丁月星 on 2020/8/21.
// 用优先队列实现Dijkstra算法
//

#include "Dijkstra_dyx.h"

Dijkstra::Dijkstra()
{
    m_NumOfEdges = 0;
    m_NumOfVertesx = 0;
    m_vertexs.clear();
    m_edges.clear();
}

void Dijkstra::InputVertexAndEdges()
{
    int count;
    cout << "请输入图的顶点数:";
    cin >> count;
    if(cin.fail())
        exit(0);
    while(count <= 1 || count > 0x7FFFFFFF)
    {
        cout << "顶点数应为大于1的正整数，且小于等于2^31-1(2147483647),请重新输入:" << endl;
        cin >> count;
        if(cin.fail())
            exit(0);
    }
    m_NumOfVertesx = count;
    int tmp;
    cout << "请输入所有顶点的名称，每输入一个换行：" << endl;
    while(count > 0)
    {
        cin >> tmp;
        m_vertexs.push_back(tmp);
    }
    cout << "请输入边的条数:";
    cin >> count;
    if(cin.fail())
        exit(0);
    while(count < 1 || count > m_NumOfVertesx*(m_NumOfVertesx-1))//边的条数 <= 顶点数*(顶点数-1)
    {
        cout << "一共有" << m_NumOfVertesx << "个顶点，所以边的条数应小于等于" << m_NumOfVertesx*(m_NumOfVertesx-1) << "条,且大于0条，请重新输入" << endl;
        cin >> count;
        if(cin.fail())
            exit(0);
    }
    m_NumOfEdges = count;
    cout << "顶点数：" << m_NumOfVertesx << ",边的条数：" << m_NumOfEdges << endl;
    cout << "请输入每条边和权值，以\"出顶点的名字 入顶点的名字 3\"这样的方式输入一条边，用空格隔开，回车结束。然后输入下一条，以此类推：" << endl;
//    while(count > 0)
//    {
//        std::cin >> tmp;
//
//        auto status = m_edges.emplace(tmp);
//        if(status.second)
//            count--;
//        else cout << "名称重复，请重新输入" << endl;
//    }
    if(!IsValid())
    {
        cout << "输入的参数不正确！" << endl;
        exit(0);
    }
}

void Dijkstra::setvertexs(int num)
{
    if(num < 1)
        return;
    for(int i = 0;i < num;i++)
    {
        m_vertexs.push_back(i);
    }
}

void Dijkstra::setedges()
{
//    vector<ituple> tmp;
//    tmp.push_back(make_tuple(2,10));
//    tmp.push_back(make_tuple(4,30));
//    tmp.push_back(make_tuple(5,100));
//    m_edges.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(make_tuple(2,5));
//    m_edges.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(make_tuple(3,50));
//    m_edges.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(make_tuple(5,10));
//    m_edges.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(make_tuple(3,20));
//    tmp.push_back(make_tuple(5,60));
//    m_edges.push_back(tmp);
//    tmp.clear();

    vector<ituple> tmp;
    tmp.push_back(make_tuple(3,4));
    tmp.push_back(make_tuple(4,1));
    tmp.push_back(make_tuple(7,10));
    m_edges.push_back(tmp);
    tmp.clear();
    tmp.push_back(make_tuple(2,2));
    tmp.push_back(make_tuple(5,1));
    m_edges.push_back(tmp);
    tmp.clear();
    tmp.push_back(make_tuple(1,2));
    tmp.push_back(make_tuple(5,3));
    m_edges.push_back(tmp);
    tmp.clear();
    tmp.push_back(make_tuple(0,4));
    tmp.push_back(make_tuple(7,1));
    m_edges.push_back(tmp);
    tmp.clear();
    tmp.push_back(make_tuple(0,1));
    tmp.push_back(make_tuple(5,3));
    tmp.push_back(make_tuple(7,5));
    m_edges.push_back(tmp);
    tmp.clear();
    tmp.push_back(make_tuple(1,1));
    tmp.push_back(make_tuple(2,3));
    tmp.push_back(make_tuple(4,3));
    tmp.push_back(make_tuple(6,7));
    tmp.push_back(make_tuple(8,1));
    m_edges.push_back(tmp);
    tmp.clear();
    tmp.push_back(make_tuple(9,1));
    m_edges.push_back(tmp);
    tmp.clear();
    tmp.push_back(make_tuple(0,10));
    tmp.push_back(make_tuple(3,1));
    tmp.push_back(make_tuple(4,5));
    tmp.push_back(make_tuple(8,9));
    m_edges.push_back(tmp);
    tmp.clear();
    tmp.push_back(make_tuple(5,1));
    tmp.push_back(make_tuple(9,2));
    m_edges.push_back(tmp);
    tmp.clear();
    tmp.push_back(make_tuple(6,1));
    m_edges.push_back(tmp);
    tmp.clear();

//    vector<ituple> tmp;
//    tmp.push_back(make_tuple(1,1));
//    m_edges.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(make_tuple(4,-5));
//    m_edges.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(make_tuple(3,1));
//    tmp.push_back(make_tuple(6,1));
//    tmp.push_back(make_tuple(7,1));
//    m_edges.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(make_tuple(0,2));
//    tmp.push_back(make_tuple(4,4));
//    tmp.push_back(make_tuple(8,1));
//    m_edges.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(make_tuple(5,4));
//    m_edges.push_back(tmp);
//    tmp.clear();
//    m_edges.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(make_tuple(3,-1));
//    m_edges.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(make_tuple(6,-1));
//    m_edges.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(make_tuple(8,1));
//    m_edges.push_back(tmp);
//    tmp.clear();
}

void Dijkstra::split_string(const string & str, vector<string> & words )
{
    words.clear();

    typedef string::size_type string_size;
    string_size i = 0;

    while( i != str.size() )
    {
        while( i != str.size() && isspace( str[i] ))
            ++i;

        string_size j = i;
        while( j != str.size() && !isspace(str[j]))
            ++j;
        if( i != j )
        {
            words.push_back( str.substr( i, j - i ) );
            i = j;
        }
    }
}

bool Dijkstra::IsValid(vector<int> &vertexs,vector<vector<ituple/*edge*/>> &edges)
{
    int i = 0;
    if((GetNumOfEdges() > vertexs.size() * (vertexs.size() - 1)) || GetNumOfEdges() < 1)
        return false;
    for(auto r:edges)
    {
        for(auto s:r)
        {
            if (get<1>(s) <= 0)
            {
                cout << "边:\"" << i << "->" << get<0>(s) << " " << get<1>(s)
                     << "\"的权值为负" << endl;
                return false;
            }
        }
        ++i;
    }
    return true;
}

auto Dijkstra::Dijkstra_dyx(int first)
{
    priority_queue<ituple,vector<ituple>,greater<ituple>> pq;
//    priority_queue<ituple,vector<ituple>,less<ituple>> pq;
//    priority_queue<ituple,vector<ituple>,comp_tuple<ituple>> pq;
//    priority_queue<ituple,vector<ituple>> pq;
//    priority_queue<ituple> pq;
    int i = 0;
    pq.push(make_tuple(first,0));
    int size = m_vertexs.size();
    vector<int> dist;
    dist.resize(m_vertexs.size());
    dist.assign(m_vertexs.size(),INT_MAX);
    dist[first] = 0;
    while(!pq.empty())
    {
        auto tmp = get<0>(pq.top());
        pq.pop();
        if(tmp > m_vertexs.size())
            exit(0);
        for(auto r:m_edges[tmp])
        {
            int i = get<0>(r);
            int j = get<1>(r);
            if(dist[i] > dist[tmp] + j)
            {
                dist[i] = dist[tmp] + j;
                pq.push(make_tuple(i,dist[i]));
            }
        }
    }
    return dist;
}

void Dijkstra::printsolution(vector<int> dist)
{
    int i = 0;
    for(auto tmp:dist)
    {
        if(tmp == INT_MAX)
            cout << i << ":无路径" << endl;
        else cout << i << ":" << tmp << endl;
        ++i;
    }
}
int main()
{
    Dijkstra g;
    g.setvertexs(10);
    g.setedges();
    g.printsolution(g.Dijkstra_dyx(3));
    return 0;
}
