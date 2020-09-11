//
// Created by 丁月星 on 2020/8/6.
//
#include <iostream>
#include <vector>
#include <tuple>
#include <chrono>


using std::cout;
using std::endl;
using std::vector;
using std::tuple;

class Solution {
public:
    Solution(){m_vecresult.clear();}
    void twoSum(const vector<int>& nums, int target) {
        m_vecresult.clear();
        for(auto r = nums.cbegin();r != nums.cend();++r)
        {
            for(auto s = r+1;s != nums.cend();++s)
            {
                if(target == *r + *s)
                {
                    tuple<int,int> tp = std::make_tuple(r - nums.cbegin(), s - nums.cbegin());
//                    return {r - nums.cbegin(),s - nums.cbegin()};
                    m_vecresult.push_back(tp);
                }
            }
        }
    }
    void printResult()
    {
        for(auto r:m_vecresult)
            cout << std::get<0>(r) << "," << std::get<1>(r) << endl;
    }

private:
    vector<std::tuple<int,int>> m_vecresult;
};

int main()
{
    const vector<int>& vec = {8,4,2,5,7,10,3,11,15};
    Solution so;
    auto t1=std::chrono::steady_clock::now();
    so.twoSum(vec,15);
    auto t2=std::chrono::steady_clock::now();
//    double dr_s=std::chrono::duration<double>(t2-t1).count();//秒
//    double dr_ms=std::chrono::duration<double,std::milli>(t2-t1).count();//毫秒
    double dr_us=std::chrono::duration<double,std::micro>(t2-t1).count();//微秒
    cout << "程序耗时" << dr_us << endl;
    so.printResult();
    return 0;
}