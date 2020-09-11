//
// Created by 丁月星 on 2020/8/26.
//

#include <iostream>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
#define maxint 0x3f3f3f3f
#define maxnum 1051

int link[maxnum][maxnum];
int c[maxnum][maxnum];
int sum,n;//sum为最小权之和，n为顶点个数

struct node
{
    int s;//起点
    int e;//终点
    int w;//权
};

bool operator < (const node &a,const node &b)
{
    return a.w > b.w;
}

void prim(int s)
{
    int i,j,k,m,t,u,total;
    int vis[maxnum];//标记访问
    memset(vis,0,sizeof(vis));//初始化vis均为0，即未被访问
    priority_queue <node> qq;//声明一个存储node结构体的优先队列

    struct node nn;

    total  = 1;
    vis[s] = 1;
    sum = 0;
    while(total < n)//遍历所有的顶点
    {
        for(i=1;i<link[s][0];i++)//遍历所有和s点相连的边,s点为源点
        {
            if(!vis[link[s][i]])//若这个边没被访问，就将其加入优先队列
            {
                nn.s = s;
                nn.e = link[s][i];
                nn.w = c[s][nn.e];
                qq.push(nn);
            }
        }
        //这里就是简单处理一下特殊情况
        while(!qq.empty() && vis[qq.top().e])//遇到顶点和集合外的顶点没有相连的
            qq.pop();//刚巧这个点作为终点是最短的，因为这个顶点没背标记过，所以会错误的计入在内
        //将优先队列的队顶元素输出
        nn = qq.top();
        s = nn.e;
        sum += nn.w;//队顶的边就是最适合的边，因为优先队列的作用就是对权值进行排序，队顶总是
        //最大或最小的权值的边，又因为没被访问过，所有一定是最适合的
        //cout<<nn.s<<" "<<nn.e<<" "<<nn.w<<endl;
        vis[s] = 1;//标记为集合内的元素
        qq.pop();
        total++;//访问的点数加一
    }
}

int main()
{
    int i,j,k;
    int line,len;
    int t,s,d,p,q;
    cin>>n>>line;
    for(i=1;i<=n;i++)
    {
        link[i][0] = 1;
    }
    for(i=1;i<=line;i++)
    {
        cin>>p>>q>>len;
        c[p][q] = c[q][p] = len;
        link[p][link[p][0]++] = q;
        link[q][link[q][0]++] = p;
    }
    cin>>s;//输入起始点
    prim(s);
    cout<<sum<<endl;
    return 0;
}