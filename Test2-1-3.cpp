#include <iostream>
#include <cmath>  //pow()함수를 사용하기 위한 헤더파일 선언
#include "oopstd.h"  //oopstd라는 namespace가 저장된 헤더파일 참조
#include <iomanip>  //setprecision()함수를 사용하기 위한 헤더파일 선언

using namespace std;

namespace oopstd
{
    void* memset(void* ptr, int value, size_t num)  //배열의 값을 특정 값으로 초기화 해주는 함수
    {
        unsigned char* set = static_cast<unsigned char*>(ptr);  //ptr은 void형 포인터 이므로 static_cast연산자를 통해 명시적으로 형변환을 시켜 포언터 p에 그 주소값을 저장함
        
        for (size_t i = 0; i < num; i++)
        {
            set[i] = static_cast<unsigned char>(value);  //바이트 단위로 저장하기 때문에 형변환을 통해 int값을 바이트 단위로 저장함
        }

        return ptr;
    }

    void* memcpy(void* destination, const void* source, size_t num)  //저장된 값을 그대로 복사하는 함수
    {
        unsigned char* des = static_cast<unsigned char*>(destination); //메모리를 1바이트 단위로 복사하기 위해서 unsigned char*형으로 형변환 시킴
        const unsigned char* sou = static_cast<const unsigned char*>(source);

        for (size_t i = 0; i < num; i++)
        {
            des[i] = sou[i];
        }

        return destination;
    }

    int strcmp(const char* str1, const char* str2)  //문자열을 비교하는 함수
    {
        while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) //str1과 str2가 NULL문자가 아니고 서로 같은 문자가 저장되어있을 때 while문을 수행
        {
            str1++;
            str2++;
        }
        return *str1 - *str2;   //str1과 str2에 저장된 문자의 아스키 코드값으로 계산함 두 문자열이 같으면 0을 반환
    }

    int strncmp(const char* str1, const char* str2, size_t num)  //n개까지의 문자를 비교하는 함수
    {
        while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2 && num > 0) //strcmp()함수와는 달리 num까지 문자열을 비교함
        {
            str1++;
            str2++;
            num--;
        }
                                        //num개의 문자열의 비교가 끝나서 while문을 빠져나왔을 경우 num까지는 문자열이 같으므로 0을 반환
        return *str1 - *str2;  //num까지 비교하기 전에 두 문자열중 문자가 서로 다르거나 문자열이 끝날 경우 
    }

    char* strcpy(char* destination, const char* source) //문자열을 복사하는 함수
    {
        while (*source)     //문자열의 끝까지 포인터 값을 증가시키며 복사함
        {
            *destination = *source;
            destination++;
            source++;    

        }
        *destination = '\0';           //복사가 끝나면 끝에 NULL값을 저장함

        return destination;
    }

    char* strncpy(char* destination, const char* source, size_t num)  //n개의 문자를 복사하는 함수
    {
        while (*source != '\0' && num > 0)   //문자열중 num개의 문자만 복사함
        {
            *destination = *source;
            destination++;
            source++;
            num--;
        }

        while (num > 0)   //복사할려는 문자열보다 더 큰값을 num값의 인자로 줬을 때 나머지 값들을 NULL값으로 채움
        {
            *destination = '\0';
            destination++;
            num--;
        }
        return destination;
    }

    size_t strlen(const char* str)  //문자열의 길이를 반환하는 함수
    {
        size_t len = 0;    //길이를 저장할 변수 선언
        while (*str != '\0')   //str이 가리키는 메모리의 값이 NULL이 아닐때까지 len값을 증가시켜 배열의 길이를 반환함
        {
            len++;
            str++;
        }
        return len;
    }

    int atoi(const char* str)  //문자열에 저장된 숫자를 읽고 정수로 변환하는 함수
    {
        int a = 0;
        int negative = 0;

        if (*str == '-')      //음수표현일 때는 앞에 -문자를 읽어드림
        {
            negative = 1;
            str++;
        }

        while (*str != '\0' && (*str >= '0' && *str <= '9'))  //NULL값이 아닌 0부터 9의 문자만을 받아서 정수로 변환
        {
            a = (a * 10) + (*str - '0');   //'0'만큼의 아스키 코드값을 빼줘서 문자를 정수로 변환하고 자릿수를 1자리씩 올려줌
            str++;
        }

        if (negative)      //-부호가 있을 경우 최종적으로 음수로 바꾸어줌
        {
            a *= -1.0;
        }

        return a;
    }

    double atof(const char* str)
    {
        double result = 0.0;    
        double decimal = 0.0;
        int negative = 0;
        int count = 0;
        int ex = 0;    //소수점 표현방식인 e-와 e+의 갑을 저장할 변수
        if (*str == '-')      //음수표현일 때는 앞에 -문자를 읽어드림
        {
            negative = 1;
            str++;
        }

        while (*str != '\0' && (*str >= '0' && *str <= '9'))   //str이 가리키는 공간에 저장된 값이 NULL이 아니고 0부터 9까지의 문자를 읽어 드림
        {
            result = (result * 10.0) + static_cast<double>(*str - '0');   //수를 double형으로 바꾸고 자리수를 맞춰줌
            str++;
        }

        if (*str == '.')   //숫자들을 읽는 도중 소수점이 나왔을 경우 소수점 이하의 수들을 다룸
        {
            str++;
            while (*str != '\0' && (*str >= '0' && *str <= '9'))    //소수점 이하의 수들을 double형으로 변환
            {
                decimal = (decimal * 10.0) + static_cast<double>(*str - '0');
                str++;
                count++;
            }
            result += decimal / pow(10.0, count);   //소수점 이하의 숫자도 자리수를 맞추어 result값에 더해줌
        }

        if (*str == 'e' || *str == 'E')   //부동소수점표현에 대한 예외 처리
        {
            str++;
            if (*str == '-')    //e다음 문자가 '-'일 경우 그 뒤 값만큼 10에 제곱하여 나누어서 자릿수를 맞춤
            { 
                str++;
                ex = static_cast<double>(*str - '0');
                result /= pow(10.0, ex);

            }

            else if (*str == '+')   //e다음 문자가 '+'일 경우 그 뒤 값만큼 10에 제곱하여 곱해서 자릿수를 맞춤
            {
                str++;
                ex = static_cast<double>(*str - '0');
                result *= pow(10.0, ex);
            }
        }

        if (negative)      //-부호가 있을 경우 최종적으로 음수로 바꾸어줌
        {
            result *= -1.0;
        }

        return result;
    }
}

int main()
{
    char like[] = "after like";
    char love[] = "after love";
    char empty[] = "empty";
    char i[] = "202304";
    char f[] = "23.845175757575";
    char fe[] = "1.414213e-3";
    int I = 0;
    double F = 0;
        
    char num1[10] = { 'a', 'b', 'c', 'd', 'e'};
    char num2[10] = { 'A', 'B', 'C', 'D', 'E'};

    cout << "num1에 저장된 문자열: " << num1 << endl;
    cout << "num2에 저장된 문자열: " << num2 << endl;

    oopstd::memset(num1, 65, sizeof(num1) - 1);  //문자 'A'의 아스키 코드값인 65로 초기화
    cout << "A의 아스키 코드값인 65로 num1 초기화: " <<num1 << endl;
    oopstd::memcpy(num1, num2, 3);       //문자열 num1에 num2문자열을 앞에서 3개만 복사 (ABC)
    cout << "num1에 num2문자를 앞에서 3개만 복사: " << num1 << endl;

    cout << "like에 저장된 문자열: " << like << endl;
    cout << "love에 저장된 문자열: " << love << endl;

    cout << "두 문자열 비교" << endl;
    if(!oopstd::strcmp(like, love))   //전제 문자열을 비교
        cout << "same" << endl;
    else
        cout << "different" << endl;

    cout << "두 문자열을 앞에서 5개만 비교" << endl;
    if (!oopstd::strncmp(like, love, 5))   //문자열을 앞에서 5개만 비교 
        cout << "same" << endl;
    else
        cout << "different" << endl;

    cout << "empty에 저장된 문자열: " << empty << endl;
    oopstd::strcpy(like, empty);     //empty에 저장된 문자열 전체를 배열 like에 복사
    cout << "like문자열에 empty문자열 전체 카피" << endl;
    cout << like << endl;
    oopstd::strncpy(love, empty, 3); //empty에 저장된 문자열중 앞에서 3개의 문자만 배열 love에 복사
    cout << "앞에서 3개만 복사하여 love문자열에 저장: " << love << endl;

    I = oopstd::strlen(love);    //문자열의 길이를 계산함
    cout << "love문자열의 길이: " << I << endl;

    I = oopstd::atoi(i);  //"202304"문자열을 정수형으로 바꾸어 저장하고 출력
    cout << I << endl;

    F = oopstd::atof(f);  //"23.845175757575"문자열을 소수점 이하 9번째 자리에서 반올림하여 소수점 이하 8개를 표현함
    cout << fixed << setprecision(8) <<F << endl;

    F = oopstd::atof(fe);
    cout << fixed << setprecision(9) << F << endl;  //자리수를 9까지 출력함
    return 0;
}

