#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sh_ptr = std::make_shared<int>(10);
    std::cout << "sh_ptr count=" <<sh_ptr.use_count() << std::endl;

    std::weak_ptr<int> wp(sh_ptr);
    std::cout << "sh_ptr count=" << sh_ptr.use_count() << std::endl;
    std::cout << "wp count=" << wp.use_count() << std::endl;

    if(!wp.expired())
    {
    std::shared_ptr<int> sh_ptr2 = wp.lock(); //get another shared_ptr
    *sh_ptr = 100;
    std::cout << "wp count=" << wp.use_count() << std::endl;
    std::cout << "sh_ptr count=" << sh_ptr.use_count() << ";*sh_ptr=" << *sh_ptr << std::endl;
    std::cout << "sh_ptr2 count=" <<sh_ptr2.use_count() << ";*sh_ptr2=" << *sh_ptr << std::endl;
    }
    //delete memory
}
