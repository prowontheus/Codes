#include <iostream>
#include <functional>

// 调用方式参考上面关于函数指针和std::function的例子
// 定义标准的回调接口
class ComputeFunc
{
public:
    virtual int compute(int x, int y) const 
    {
        std::cout << "ComputeFunc::compute" << std::endl;
    }
};

// 实现回调接口
class ComputeAdd : public ComputeFunc
{
public:
    int compute(int x, int y) const override 
    {
        std::cout << "ComputeAdd::compute" << std::endl;
        return x + y; 
    }
};

int compute3(int x, int y, const ComputeFunc& compute)
{
    // 调用接口方法
    std::cout << "compute3" << std::endl;
    return compute.compute(x, y);
}

// 调用方法如下
int main()
{
    ComputeAdd add_func; // 创建一个调用实例
    int sum = compute3(3, 4, add_func); // 传入调用实例
    std::cout << sum << std::endl;
    return 0;
}
