#include "String_Class.h"
#include <iostream>

using namespace oopstd;

int main() {
    // string 객체 생성
    string s1("hello");
    string s2("world");
    
    // assign 함수 테스트
    s1.assign(s2);
    std::cout << "s1 after assign s2: " << s1.c_str() << std::endl;

    // at 함수 테스트
    s1.at(0) = 'H';
    std::cout << "s1 after changing first letter: " << s1.c_str() << std::endl;

    // clear 함수 테스트
    s1.clear();
    std::cout << "s1 after clear: " << s1.c_str() << std::endl;
    
    // push_back 함수 테스트
    s1.assign(s2);
    s1.push_back('o');
    std::cout << "s1 after push_back: " << s1.c_str() << std::endl;
    
    // compare 함수 테스트
    std::cout << "s1 compare to s2: " << s1.compare(&s2) << std::endl;

    // replace 함수 테스트
    s1.replace(0, 2, s2);
    std::cout << "s1 after replace: " << s1.c_str() << std::endl;

    // substr 함수 테스트
    string s3 = s1.substr(3, 2);
    std::cout << "s3: " << s3.c_str() << std::endl;

    // find 함수 테스트
    size_t pos = s1.find(s2, 0);
    std::cout << "position of s2 in s1: " << pos << std::endl;

    

    size_t sz;
    string s4("12345hello");
    int a = 0;
    a = stoi(s4, &sz, 10);
    std::cout << a << " " << sz << std::endl;

    string s5("12.345hello");

    float b = 0;
    b = stof(s5, &sz);

    std::cout << b << " " << sz;

    return 0;
}