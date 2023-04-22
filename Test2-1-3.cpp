#include <iostream>
#include <cmath>  //pow()�Լ��� ����ϱ� ���� ������� ����
#include "oopstd.h"  //oopstd��� namespace�� ����� ������� ����
#include <iomanip>  //setprecision()�Լ��� ����ϱ� ���� ������� ����

using namespace std;

namespace oopstd
{
    void* memset(void* ptr, int value, size_t num)  //�迭�� ���� Ư�� ������ �ʱ�ȭ ���ִ� �Լ�
    {
        unsigned char* set = static_cast<unsigned char*>(ptr);  //ptr�� void�� ������ �̹Ƿ� static_cast�����ڸ� ���� ��������� ����ȯ�� ���� ������ p�� �� �ּҰ��� ������
        
        for (size_t i = 0; i < num; i++)
        {
            set[i] = static_cast<unsigned char>(value);  //����Ʈ ������ �����ϱ� ������ ����ȯ�� ���� int���� ����Ʈ ������ ������
        }

        return ptr;
    }

    void* memcpy(void* destination, const void* source, size_t num)  //����� ���� �״�� �����ϴ� �Լ�
    {
        unsigned char* des = static_cast<unsigned char*>(destination); //�޸𸮸� 1����Ʈ ������ �����ϱ� ���ؼ� unsigned char*������ ����ȯ ��Ŵ
        const unsigned char* sou = static_cast<const unsigned char*>(source);

        for (size_t i = 0; i < num; i++)
        {
            des[i] = sou[i];
        }

        return destination;
    }

    int strcmp(const char* str1, const char* str2)  //���ڿ��� ���ϴ� �Լ�
    {
        while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) //str1�� str2�� NULL���ڰ� �ƴϰ� ���� ���� ���ڰ� ����Ǿ����� �� while���� ����
        {
            str1++;
            str2++;
        }
        return *str1 - *str2;   //str1�� str2�� ����� ������ �ƽ�Ű �ڵ尪���� ����� �� ���ڿ��� ������ 0�� ��ȯ
    }

    int strncmp(const char* str1, const char* str2, size_t num)  //n�������� ���ڸ� ���ϴ� �Լ�
    {
        while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2 && num > 0) //strcmp()�Լ��ʹ� �޸� num���� ���ڿ��� ����
        {
            str1++;
            str2++;
            num--;
        }
                                        //num���� ���ڿ��� �񱳰� ������ while���� ���������� ��� num������ ���ڿ��� �����Ƿ� 0�� ��ȯ
        return *str1 - *str2;  //num���� ���ϱ� ���� �� ���ڿ��� ���ڰ� ���� �ٸ��ų� ���ڿ��� ���� ��� 
    }

    char* strcpy(char* destination, const char* source) //���ڿ��� �����ϴ� �Լ�
    {
        while (*source)     //���ڿ��� ������ ������ ���� ������Ű�� ������
        {
            *destination = *source;
            destination++;
            source++;    

        }
        *destination = '\0';           //���簡 ������ ���� NULL���� ������

        return destination;
    }

    char* strncpy(char* destination, const char* source, size_t num)  //n���� ���ڸ� �����ϴ� �Լ�
    {
        while (*source != '\0' && num > 0)   //���ڿ��� num���� ���ڸ� ������
        {
            *destination = *source;
            destination++;
            source++;
            num--;
        }

        while (num > 0)   //�����ҷ��� ���ڿ����� �� ū���� num���� ���ڷ� ���� �� ������ ������ NULL������ ä��
        {
            *destination = '\0';
            destination++;
            num--;
        }
        return destination;
    }

    size_t strlen(const char* str)  //���ڿ��� ���̸� ��ȯ�ϴ� �Լ�
    {
        size_t len = 0;    //���̸� ������ ���� ����
        while (*str != '\0')   //str�� ����Ű�� �޸��� ���� NULL�� �ƴҶ����� len���� �������� �迭�� ���̸� ��ȯ��
        {
            len++;
            str++;
        }
        return len;
    }

    int atoi(const char* str)  //���ڿ��� ����� ���ڸ� �а� ������ ��ȯ�ϴ� �Լ�
    {
        int a = 0;
        int negative = 0;

        if (*str == '-')      //����ǥ���� ���� �տ� -���ڸ� �о�帲
        {
            negative = 1;
            str++;
        }

        while (*str != '\0' && (*str >= '0' && *str <= '9'))  //NULL���� �ƴ� 0���� 9�� ���ڸ��� �޾Ƽ� ������ ��ȯ
        {
            a = (a * 10) + (*str - '0');   //'0'��ŭ�� �ƽ�Ű �ڵ尪�� ���༭ ���ڸ� ������ ��ȯ�ϰ� �ڸ����� 1�ڸ��� �÷���
            str++;
        }

        if (negative)      //-��ȣ�� ���� ��� ���������� ������ �ٲپ���
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
        int ex = 0;    //�Ҽ��� ǥ������� e-�� e+�� ���� ������ ����
        if (*str == '-')      //����ǥ���� ���� �տ� -���ڸ� �о�帲
        {
            negative = 1;
            str++;
        }

        while (*str != '\0' && (*str >= '0' && *str <= '9'))   //str�� ����Ű�� ������ ����� ���� NULL�� �ƴϰ� 0���� 9������ ���ڸ� �о� �帲
        {
            result = (result * 10.0) + static_cast<double>(*str - '0');   //���� double������ �ٲٰ� �ڸ����� ������
            str++;
        }

        if (*str == '.')   //���ڵ��� �д� ���� �Ҽ����� ������ ��� �Ҽ��� ������ ������ �ٷ�
        {
            str++;
            while (*str != '\0' && (*str >= '0' && *str <= '9'))    //�Ҽ��� ������ ������ double������ ��ȯ
            {
                decimal = (decimal * 10.0) + static_cast<double>(*str - '0');
                str++;
                count++;
            }
            result += decimal / pow(10.0, count);   //�Ҽ��� ������ ���ڵ� �ڸ����� ���߾� result���� ������
        }

        if (*str == 'e' || *str == 'E')   //�ε��Ҽ���ǥ���� ���� ���� ó��
        {
            str++;
            if (*str == '-')    //e���� ���ڰ� '-'�� ��� �� �� ����ŭ 10�� �����Ͽ� ����� �ڸ����� ����
            { 
                str++;
                ex = static_cast<double>(*str - '0');
                result /= pow(10.0, ex);

            }

            else if (*str == '+')   //e���� ���ڰ� '+'�� ��� �� �� ����ŭ 10�� �����Ͽ� ���ؼ� �ڸ����� ����
            {
                str++;
                ex = static_cast<double>(*str - '0');
                result *= pow(10.0, ex);
            }
        }

        if (negative)      //-��ȣ�� ���� ��� ���������� ������ �ٲپ���
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

    cout << "num1�� ����� ���ڿ�: " << num1 << endl;
    cout << "num2�� ����� ���ڿ�: " << num2 << endl;

    oopstd::memset(num1, 65, sizeof(num1) - 1);  //���� 'A'�� �ƽ�Ű �ڵ尪�� 65�� �ʱ�ȭ
    cout << "A�� �ƽ�Ű �ڵ尪�� 65�� num1 �ʱ�ȭ: " <<num1 << endl;
    oopstd::memcpy(num1, num2, 3);       //���ڿ� num1�� num2���ڿ��� �տ��� 3���� ���� (ABC)
    cout << "num1�� num2���ڸ� �տ��� 3���� ����: " << num1 << endl;

    cout << "like�� ����� ���ڿ�: " << like << endl;
    cout << "love�� ����� ���ڿ�: " << love << endl;

    cout << "�� ���ڿ� ��" << endl;
    if(!oopstd::strcmp(like, love))   //���� ���ڿ��� ��
        cout << "same" << endl;
    else
        cout << "different" << endl;

    cout << "�� ���ڿ��� �տ��� 5���� ��" << endl;
    if (!oopstd::strncmp(like, love, 5))   //���ڿ��� �տ��� 5���� �� 
        cout << "same" << endl;
    else
        cout << "different" << endl;

    cout << "empty�� ����� ���ڿ�: " << empty << endl;
    oopstd::strcpy(like, empty);     //empty�� ����� ���ڿ� ��ü�� �迭 like�� ����
    cout << "like���ڿ��� empty���ڿ� ��ü ī��" << endl;
    cout << like << endl;
    oopstd::strncpy(love, empty, 3); //empty�� ����� ���ڿ��� �տ��� 3���� ���ڸ� �迭 love�� ����
    cout << "�տ��� 3���� �����Ͽ� love���ڿ��� ����: " << love << endl;

    I = oopstd::strlen(love);    //���ڿ��� ���̸� �����
    cout << "love���ڿ��� ����: " << I << endl;

    I = oopstd::atoi(i);  //"202304"���ڿ��� ���������� �ٲپ� �����ϰ� ���
    cout << I << endl;

    F = oopstd::atof(f);  //"23.845175757575"���ڿ��� �Ҽ��� ���� 9��° �ڸ����� �ݿø��Ͽ� �Ҽ��� ���� 8���� ǥ����
    cout << fixed << setprecision(8) <<F << endl;

    F = oopstd::atof(fe);
    cout << fixed << setprecision(9) << F << endl;  //�ڸ����� 9���� �����
    return 0;
}

