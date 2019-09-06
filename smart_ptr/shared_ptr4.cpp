#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> p)
{
    std::cout << p.use_count() << std::endl;
}

int main()
{
    std::shared_ptr<int> p = std::make_shared<int>(10);
    std::cout << p.use_count() << std::endl;
    foo(p);
    std::cout << p.use_count() << std::endl;
    return 0;
}
