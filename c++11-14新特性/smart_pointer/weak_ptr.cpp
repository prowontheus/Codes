#include <iostream>
#include <memory>

class CB;
class CA
{
public:
    CA() { std::cout << "CA() called! " << std::endl; }
    ~CA() { std::cout << "~CA() called! " << std::endl; }
    void set_ptr(std::shared_ptr<CB>& ptr) { m_ptr_b = ptr; }
    void b_use_count() { std::cout << "b use count : " << m_ptr_b.use_count() << std::endl; }
    void show() { std::cout << "this is class CA!" << std::endl; }
private:
    std::shared_ptr<CB> m_ptr_b;
};

class CB
{
public:
    CB() { std::cout << "CB() called! " << std::endl; }
    ~CB() { std::cout << "~CB() called! " << std::endl; }
    void set_ptr(std::shared_ptr<CA>& ptr) { m_ptr_a = ptr; }
    void a_use_count() { std::cout << "a use count : " << m_ptr_a.use_count() << std::endl; }
    void show() { std::cout << "this is class CB!" << std::endl; }
private:
    std::shared_ptr<CA> m_ptr_a;//会造成循环引用而使得引用计数没办法清零
//	std::weak_ptr<CA> m_ptr_a;
};

void test_refer_to_each_other()
{
    std::shared_ptr<CB> ptr_b(new CB());
    std::shared_ptr<CA> ptr_a(new CA());

    std::cout << "a use count : " << ptr_a.use_count() << std::endl;
    std::cout << "b use count : " << ptr_b.use_count() << std::endl;

    ptr_a->set_ptr(ptr_b);
    ptr_b->set_ptr(ptr_a);

    std::cout << "a use count : " << ptr_a.use_count() << std::endl;
    std::cout << "b use count : " << ptr_b.use_count() << std::endl;
}
void test1()
{
    // 编译错误 // error C2665: “std::weak_ptr<CA>::weak_ptr”: 3 个重载中没有一个可以转换所有参数类型
    // weak_ptr<CA> ptr_1(new CA());

	std::shared_ptr<CA> ptr_1(new CA());

    std::cout << "ptr_1 use count : " << ptr_1.use_count() << std::endl; // 输出：ptr_1 use count : 1

    std::shared_ptr<CA> ptr_2 = ptr_1;

    std::cout << "ptr_1 use count : " << ptr_1.use_count() << std::endl; // 输出：ptr_1 use count : 2
    std::cout << "ptr_2 use count : " << ptr_2.use_count() << std::endl; // 输出：ptr_1 use count : 2

    std::weak_ptr<CA> wk_ptr = ptr_1;

    std::cout << "ptr_1 use count : " << ptr_1.use_count() << std::endl; // 输出：ptr_1 use count : 2
    std::cout << "ptr_2 use count : " << ptr_2.use_count() << std::endl; // 输出：ptr_1 use count : 2

    // 编译错误
    // error C2440 : “初始化”: 无法从“std::weak_ptr<CA>”转换为“std::shared_ptr<CA>”
    // shared_ptr<CA> ptr_3 = wk_ptr;
}

void test2()
{
    std::shared_ptr<CA> ptr_a(new CA());     // 输出：CA() called!
    std::shared_ptr<CB> ptr_b(new CB());     // 输出：CB() called!

    std::cout << "ptr_a use count : " << ptr_a.use_count() << std::endl; // 输出：ptr_a use count : 1
    std::cout << "ptr_b use count : " << ptr_b.use_count() << std::endl; // 输出：ptr_b use count : 1

    std::weak_ptr<CA> wk_ptr_a = ptr_a;
    std::weak_ptr<CB> wk_ptr_b = ptr_b;

    if (!wk_ptr_a.expired())
    {
        wk_ptr_a.lock()->show();        // 输出：this is class CA!
    }

    if (!wk_ptr_b.expired())
    {
        wk_ptr_b.lock()->show();        // 输出：this is class CB!
    }

    // 编译错误
    // 编译必须作用于相同的指针类型之间
    // wk_ptr_a.swap(wk_ptr_b);         // 调用交换函数

    wk_ptr_b.reset();                   // 将wk_ptr_b的指向清空
    if (wk_ptr_b.expired())
    {
        std::cout << "wk_ptr_b is invalid" << std::endl;  // 输出：wk_ptr_b is invalid 说明改指针已经无效
    }

    wk_ptr_b = ptr_b;
    if (!wk_ptr_b.expired())
    {
        wk_ptr_b.lock()->show();        // 输出：this is class CB! 调用赋值操作后，wk_ptr_b恢复有效
    }

    // 编译错误
    // 编译必须作用于相同的指针类型之间
    // wk_ptr_b = wk_ptr_a;


    // 最后输出的引用计数还是1，说明之前使用std::weak_ptr类型赋值，不会影响引用计数
    std::cout << "ptr_a use count : " << ptr_a.use_count() << std::endl; // 输出：ptr_a use count : 1
    std::cout << "ptr_b use count : " << ptr_b.use_count() << std::endl; // 输出：ptr_b use count : 1
}

int main()
{
	test_refer_to_each_other();
//	test1();
//	test2();
	return 0;
}
