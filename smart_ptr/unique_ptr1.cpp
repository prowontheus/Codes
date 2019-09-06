#include <iostream>
#include <memory>

template<typename T, typename ...Args>
std::unique_ptr<T> make_unique( Args&& ...args ) {
    return std::unique_ptr<T>( new T( std::forward<Args>(args)...));
}

int main()
{
    auto pointer1 = make_unique<int>(10);
    auto pointer2 = make_unique<int>(42);
    std::unique_ptr<char> pointer3(new char(3));
    std::cout << *pointer1 << std::endl;
    std::cout << *pointer2 << std::endl;
    std::cout << *pointer3 << std::endl;
//    std::cout << pointer1.use_count() << pointer2.use_count() << std::endl;
    pointer1 = std::move(pointer2);
//    std::cout << pointer1.use_count() << pointer2.use_count() << std::endl;
    std::cout << *pointer1 << std::endl;
    //std::cout << *pointer2 << std::endl;
    std::cout << *pointer3 << std::endl;
    return 0;
}
