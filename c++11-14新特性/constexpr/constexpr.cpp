#define LEN 10

int len_foo() {
    return 5;
}

int main() {
    char arr_1[10];
    char arr_2[LEN];
    int len = 5;
    char arr_3[len+5];          // 非法
    const int len_2 = 10;
    char arr_4[len_2+5];        // 合法
    char arr_5[len_foo()+5];  // 非法

    return 0;
}
