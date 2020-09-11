//来源：https://zh.wikipedia.org/wiki/%E6%88%B4%E5%85%8B%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95
//维基百科：Dijkstra算法
//使用堆（优先队列）的Dijkstra算法

#include <iostream>
#include <vector>
#include <queue>
using namespace std; 
# define INF 0x3f3f3f3f 

// iPair ==> Integer Pair（整数对）
typedef pair<int, int> iPair;
// 加边
void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt)
{ 
    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt)); 
}

// 计算最短路
void Dijkstra(vector<pair<int,int> > adj[], int V, int src)
{ 
    // 关于stl中的优先队列如何实现，参考下方网址：
    // http://geeksquiz.com/implement-min-heap-using-stl/ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    // 距离置为正无穷大
    vector<int> dist(V, INF);
    // 插入源点，距离为0
    pq.push(make_pair(0, src));
    dist[src] = 0;
    /* 循环直到优先队列为空 */
    while (!pq.empty()) 
    {
        // 每次从优先队列中取出顶点事实上是这一轮最短路径权值确定的点
        int u = pq.top().second; 
        pq.pop();
        // 遍历所有边
        for (auto x : adj[u]) 
        { 
            // 得到顶点边号以及边权
            int v = x.first; 
            int weight = x.second;
            //可以松弛
            if (dist[v] > dist[u] + weight) 
            { 
                // 松弛 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    }
    // 打印最短路
    printf("Vertex Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() 
{ 
    int V = 10;
    vector<iPair > adj[V]; 
//    addEdge(adj, 0, 1, 4);
//    addEdge(adj, 0, 7, 8);
//    addEdge(adj, 1, 2, 8);
//    addEdge(adj, 1, 7, 11);
//    addEdge(adj, 2, 3, 7);
//    addEdge(adj, 2, 8, 2);
//    addEdge(adj, 2, 5, 4);
//    addEdge(adj, 3, 4, 9);
//    addEdge(adj, 3, 5, 14);
//    addEdge(adj, 4, 5, 10);
//    addEdge(adj, 5, 6, 2);
//    addEdge(adj, 6, 7, 1);
//    addEdge(adj, 6, 8, 6);
//    addEdge(adj, 7, 8, 7);
    addEdge(adj, 0,3,4);
    addEdge(adj, 0,4,1);
    addEdge(adj, 0,7,10);
    addEdge(adj, 1,2,2);
    addEdge(adj, 1,5,1);
    addEdge(adj, 2,1,2);
    addEdge(adj, 2,5,3);
    addEdge(adj, 3,0,4);
    addEdge(adj, 3,7,1);
    addEdge(adj, 4,0,1);
    addEdge(adj, 4,5,3);
    addEdge(adj, 4,7,5);
    addEdge(adj, 5,0,1);
    addEdge(adj, 5,2,3);
    addEdge(adj, 5,4,3);
    addEdge(adj, 5,6,7);
    addEdge(adj, 5,8,1);
    addEdge(adj, 6,9,1);
    addEdge(adj, 7,0,10);
    addEdge(adj, 7,3,1);
    addEdge(adj, 7,4,5);
    addEdge(adj, 7,8,9);
    addEdge(adj, 8,5,1);
    addEdge(adj, 8,9,2);
    addEdge(adj, 9,6,1);
    clock_t time1 = clock();
    Dijkstra(adj, V, 4);
    cout << "总耗时："  << clock() - time1 << "毫秒" << endl;
    return 0; 
}