//
// Created by 丁月星 on 2020/8/29.
//
#include <iostream>
#include <cstdlib>
#include <array>
#include <vector>
#include <stack>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::array;
using std::stack;

const int LENGTHOFARRAY = 10000;

array<int,21> data1 = {8,11,5,12,18,4,13,7,20,6,10,1,9,6,19,3,8,15,12,14,10};
array<int,10> data2= {10,1234,9,7234,67,9181,733,197,7,3};

//1.插入排序
template <typename T>
void InsertSort(T &data)
{
    for(int i = 1;i < data.size();i++)
    {
        auto tmp = data[i];
        int j = i;
        for(;j > 0 && tmp < data[j-1];j--)
            data[j] = data[j-1];
        data[j] = tmp;
    }
    return;
}

//2.选择排序
template<typename T>
void SelectSort(T &data)
{
    for(int i = 0;i < data.size()-1;i++)
    {
        int num = i;
        for(int j = i + 1;j < data.size();j++)
        {
            if(data[i] > data[j])
                num = j;
        }
        if(i != num)
        {
            auto tmp = data[i];
            data[i] = data[num];
            data[num] = tmp;
        }
    }
}

//3.冒泡排序
template<typename T>
void BubbleSort(T &data)
{
    for(int i = 0;i < data.size()-1;i++)
    {
        bool ret = true;
        for(int j = 0;j < data.size()-1-i ;j++)
        {
            if (data[j] > data[j + 1])
            {
                auto tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
                ret = false;
            }
        }
        if(ret)
            break;
    }
}

//4.梳排序
template<typename T>
void CombSort(T &data)
{
    int n = data.size();
    int step = n;
    while((step = (int)(step/1.3)) > 1)
    {
        for(int i = 0;i < n - step;i++)
        {
            if(data[i] > data[step+i])
            {
                auto tmp = data[i];
                data[i] = data[step+i];
                data[step+i] = tmp;
            }
        }
    }
    BubbleSort(data);
}

//5.希尔排序
template<typename T>
void ShellSort(T &data)
{
    int size = data.size();
    stack<int> increment;
    int h = 1;
    while(h < size)
    {
        increment.push(h);
        h = 3*h + 1;
    }
    while(!increment.empty())
    {
        int r = increment.top();
        increment.pop();
        for(int k = 0;k < r;k++)
        {
            for (int i = r + k;i < size;i = i + r)
            {
                auto tmp = data[i];
                int j = i;
                for (;j-r >= 0 && tmp < data[j-r]; j = j - r)
                        data[j] = data[j-r];
                data[j] = tmp;
            }
        }
    }
}

//6.堆排序
template<typename T>
void moveDown(T &data,int pos,int size)//用自底向上方法将数组实现为堆
{
    if(pos < 0)
        return;
    while(2*pos+1 < size)
    {
        int least = -1;
        if(data[pos] < data[2*pos+1])
        {
            if(2*pos+2 < size && data[2*pos+1] < data[2*pos+2])
                least = 2 * pos + 2;
            else least = 2 * pos + 1;
        }
        else if(2*pos+2 < size)//存在右子节点
        {
            if(data[pos] < data[2*pos+2])
                least = 2 * pos + 2;
        }
        else break;//data[pos]只有左子节点并且dada[pos] > 它的左子节点
        if(least != -1)
        {
            auto tmp = data[pos];
            data[pos] = data[least];
            data[least] = tmp;
            pos = least;
        }
        else break;
    }
}

template<typename T>
void HeapSort(T &data)
{
    int size = data.size();
    for(int i = size/2-1;i >= 0;i--)
        moveDown(data,i,size);
    int n = size;
    while(--n > 0)
    {
        auto tmp = data[n];
        data[n] = data[0];
        data[0] = tmp;
        moveDown(data,0,n);
    }
}

//7.快速排序
template<typename T>
void swap(T &a,T &b)
{
    if(a == b) return;
    auto tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void QuickSort(T &data,int first,int last)
{
    if(first + 1 == last)
    {
        if(data[first] > data[last])
            swap(data[first],data[last]);
        return;
    }
    int lower = first+1,upper = last;
    swap(data[first],data[(first+last)/2]);
    auto pivot = data[first];
    while(lower < upper)
    {
        while(data[lower] < pivot)
            lower++;
        while(data[upper] > pivot)
            upper--;
        if(lower < upper)
            swap(data[lower++],data[upper--]);
    }
    swap(data[first],data[upper]);
    if(first < upper-1)
        QuickSort(data,first,upper-1);
    if(upper+1 < last)
        QuickSort(data,upper+1,last);
}

//8.归并排序
template<typename T>
void merge1(T &data,int first,int last)
{
    int mid = (first + last) / 2;
    int i = 0,j = first,k = mid + 1;
    T temp = {0};
    while(j <= mid && k <= last)
    {
        if(data[j] < data[k])
            temp[i++] = data[j++];
        else temp[i++] = data[k++];
    }
    if(j > mid)
    {
        for (int l = k; l <= last; l++)
            temp[i++] = data[l];
    } else{
        for (int l = j; l <= mid; l++)
            temp[i++] = data[l];
    }
    for(int m = 0,l = first;m <= last-first;m++)
        data[l++] = temp[m];
}

template <typename T>
void mergesort1(T &data,int first,int last)//递归版本
{
    if(first < last - 1)
    {
        int mid = (first + last) / 2;
        mergesort1(data, first, mid);
        mergesort1(data, mid + 1, last);
        merge1(data, first, last);
    }
    else if(last == first + 1){
        if(data[first] > data[last])
        {
            auto tmp = data[first];
            data[first] = data[last];
            data[last] = tmp;
        }
    }
}

/****
 *
 * @tparam T
 * @param data 数组地址
 * @param first 第一个子数组的起始下标
 * @param length1 第一个子数组的长度
 * @param last 第二个子数组的起始下标
 * @param length2 第二个子数组的长度
 *
 * 将第一个子数组和第二个子数组进行归并，且两个子数组必须满足首尾相连
 */
template<typename T>
void merge2(T &data,int first,int length1,int last,int length2)
{
    if(first + length1 != last) return;
    int i = 0,j = first,k = last;
    T temp = {0};
    while(j < first+length1 && k < last+length2)
    {
        if(data[j] < data[k])
            temp[i++] = data[j++];
        else temp[i++] = data[k++];
    }
    if(j >= first+length1)
    {
        for (int l = k; l <= last+length2; l++)
            temp[i++] = data[l];
    } else{
        for (int l = j; l <= first+length1; l++)
            temp[i++] = data[l];
    }
    for(int m = 0,l = first;m < length1+length2;m++)
        data[l++] = temp[m];
}

template<typename T>
void mergesort2(T &data,int first,int last)//迭代版本
{
    int begin = first;
    int length = 2;
    while(length - 1 < last)
    {
        begin = first;
        while(begin + length - 1 <= last)
        {
            merge2(data, begin, length/2,begin + length / 2,length/2);
            begin = begin + length;
        }
        if(begin <= last)
            merge2(data,begin-length,length,begin,last-begin+1);
        length *= 2;
    }
}

//9.基数排序
void RadixSort(std::array<int,LENGTHOFARRAY> &data,int n)
{
    int radix = 10;
    int factor = 1;
    int max = data[0];
    std::queue<int> vec[radix];
    for(int i = 1;i < n;i++)
    {
        if(max < data[i])
            max = data[i];
    }
    while(factor < max)
    {
        for(int i = 0;i < n;i++)
        {
            int tmp = data[i] / factor;
            vec[tmp % radix].push(data[i]);
        }
        int j = 0;
        for(int i = 0;i < 10;i++)
        {
            while(!vec[i].empty())
            {
                data[j++] = vec[i].front();
                vec[i].pop();
            }
        }
        factor *= radix;
    }
}

//10.计数排序
template<typename T>
void CountingSort(T &data,int n)
{
    int max = data[0],min = data[0];
    for(int i = 1;i < n;i++)
    {
        if(data[i] > max)
            max = data[i];
        else if(data[i] < min)
            min = data[i];
    }
    int count[max-min+1];
    for(int i = 0;i < max-min+1;i++)
        count[i] = 0;
    for(int i = 0;i < n;i++)
        count[data[i]-min]++;
    for(int i = 0,j = 0;i < max-min+1;i++)
    {
        if(count[i] > 0)
        {
            while(count[i]-- > 0)
                data[j++] = i + min;
        }
    }
}

template <typename T>
void print(T &data)
{
    for(auto r:data)
        cout << r << " ";
    cout << endl;
}

int main()
{
    array<int,LENGTHOFARRAY> data={0};
    srand(time(nullptr));
    for(int i = 0;i < LENGTHOFARRAY;i++)
    {
        data[i] = rand() % LENGTHOFARRAY;
    }
    array<int,LENGTHOFARRAY> arr = data;
    cout << "原始数组:" << endl;
//    print<>(data);
    clock_t timespan1 = clock();
    clock_t timespan2 = clock();

////    1.插入排序
//    arr = data;
//    cout << "插入排序后：" << endl;
//    timespan1 = clock();
//    InsertSort(arr);
//    timespan2 = clock();
////    print<>(arr);
//    cout << "插入排序耗时:" << (double)(timespan2 - timespan1) << "微秒" << endl;
//
////    2.选择排序
//    arr = data;
//    cout << "选择排序后：" << endl;
//    timespan1 = clock();
//    SelectSort(arr);
//    timespan2 = clock();
////    print<>(arr);
//    cout << "选择排序耗时:" << (double)(timespan2 - timespan1) << "微秒" << endl;
//
////    3.冒泡排序
//    arr = data;
//    cout << "冒泡排序后：" << endl;
//    timespan1 = clock();
//    BubbleSort(arr);
//    timespan2 = clock();
////    print<>(arr);
//    cout << "冒泡排序耗时:" << (double)(timespan2 - timespan1) << "微秒" << endl;
//
////    4.梳排序
//    arr = data;
//    cout << "梳排序后：" << endl;
//    timespan1 = clock();
//    CombSort(arr);
//    timespan2 = clock();
////    print<>(arr);
//    cout << "梳排序耗时:" << (double)(timespan2 - timespan1) << "微秒" << endl;
//
////    5.希尔排序
//    arr = data;
//    cout << "希尔排序后：" << endl;
//    timespan1 = clock();
//    ShellSort<>(arr);
//    timespan2 = clock();
////    print<>(arr);
//    cout << "希尔排序耗时:" << (double)(timespan2 - timespan1) << "微秒" << endl;
//
////    6.堆排序
//    arr = data;
//    cout << "堆排序后：" << endl;
//    timespan1 = clock();
//    HeapSort<>(arr);
//    timespan2 = clock();
////    print<>(arr);
//    cout << "堆排序耗时:" << (double)(timespan2 - timespan1) << "微秒" << endl;
//
////    7.快速排序
//    arr = data;
//    cout << "快速排序后：" << endl;
//    timespan1 = clock();
//    QuickSort<>(arr,0,arr.size()-1);
//    timespan2 = clock();
////    print<>(arr);
//    cout << "快速排序耗时:" << (double)(timespan2 - timespan1) << "微秒" << endl;
//
////    8.归并排序
//    arr = data;
//    cout << "归并排序后：" << endl;
//    timespan1 = clock();
//    mergesort2<>(arr,0,arr.size()-1);
//    timespan2 = clock();
////    print<>(arr);
//    cout << "归并排序耗时:" << (double)(timespan2 - timespan1) << "微秒" << endl;
//
////    9.基数排序
//    arr = data;
//    cout << "基数排序后：" << endl;
//    timespan1 = clock();
//    RadixSort(arr,LENGTHOFARRAY);
//    timespan2 = clock();
////    print<>(arr);
//    cout << "基数排序耗时:" << (double)(timespan2 - timespan1) << "微秒" << endl;
//
////    10.计数排序
//    arr = data;
//    cout << "计数排序后：" << endl;
//    timespan1 = clock();
//    CountingSort<>(arr ,arr.size());
//    timespan2 = clock();
//    print<>(arr);
//    cout << "计数排序耗时:" << (double)(timespan2 - timespan1) << "微秒" << endl;
    return 0;
}