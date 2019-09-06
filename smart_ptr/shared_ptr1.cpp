#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> p1 = std::make_shared<int>(64);
    std::shared_ptr<char> p2(new char(8));
    std::shared_ptr<std::string> p3(new std::string("sdhfsnvkjhijeflknvl"));
    std::shared_ptr<int> p4 = p1;
    std::shared_ptr<int> p5 = p4;
    std::cout << "sizeof(p1)=" << sizeof(p1) << ";p1 count=" << p1.use_count() << std::endl;
    std::cout << "sizeof(p2)=" << sizeof(p2) << ";p2 count=" << p2.use_count() << std::endl;
    std::cout << "sizeof(p3)=" << sizeof(p3) << ";p3 count=" << p3.use_count() << std::endl;
    std::cout << "sizeof(p3)=" << sizeof(p4) << ";p4 count=" << p4.use_count() << std::endl;
    std::cout << "sizeof(p3)=" << sizeof(p5) << ";p4 count=" << p5.use_count() << std::endl;
    std::cout << "sizeof(std::shared_ptr<int>)=" << sizeof(std::shared_ptr<int>) << std::endl;
    std::shared_ptr<int> p6 = std::make_shared<int>(10);
    std::array<int,10> arr = {0};
    return 0;
}
