#include <iostream>
#include <memory>
using namespace std;

int main()
{
    shared_ptr<int> p1 = make_shared<int>(64);
    shared_ptr<char> p2(new char(8));
    shared_ptr<string> p3(new string("d!"));
    shared_ptr<int> p4 = p1;
    shared_ptr<int> p5 = p4;
    std::cout << "sizeof(p1)=" << sizeof(*p1) << ";p1 count=" << p1.use_count() << endl;
    std::cout << "sizeof(p2)=" << sizeof(*p2) << ";p2 count=" << p2.use_count() << endl;
    std::cout << "sizeof(p3)=" << sizeof(*p3) << ";p3 count=" << p3.use_count() << endl;
    std::cout << "sizeof(p3)=" << sizeof(*p4) << ";p4 count=" << p4.use_count() << endl;
    std::cout << "sizeof(p3)=" << sizeof(*p5) << ";p4 count=" << p5.use_count() << endl;
    return 0;
}
