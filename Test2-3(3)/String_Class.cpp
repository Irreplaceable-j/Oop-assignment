#define _CRT_SECURE_NO_WARNINGS
#include "String_Class.h"
#include <string.h>
#include <iostream>
using namespace std;

namespace oopstd
{
	string::string() {
		s = nullptr;
		len = 0;
	}
	string::string(const char* s) {
		len = strlen(s);     //���̸� ����ؼ� ����
		this->s = new char[len + 1];   //�޸� �����Ҵ�
		strcpy(this->s, s);
	}
	string::string(const string& str) {
		len = str.len;         //��ü�� ������� �״�� ����
		s = new char[len + 1];
		strcpy(s, str.s);   
	}
	string::~string() {
		delete[] s;
	}
	string& string::assign(const string& str) {
		if (this != &str) {  // �ڱ� �ڽŰ��� ������ �����մϴ�.
			delete[] s;  // ���� ���ڿ� ���� ����Ű�� �޸𸮸� �����մϴ�.
			len = str.len;  // ���̸� ����� ���ڿ� ���̷� �����մϴ�.
			s = new char[len + 1];  // ���ο� �޸𸮸� �Ҵ��մϴ�.
			strcpy(s, str.s);  // ����� ���ڿ��� ���� �Ҵ��� �޸𸮿� �����մϴ�.
		}
		return *this;  // ���� ��ü�� ������ ��ȯ�մϴ�.
	}
	char& string::at(size_t pos) {
		return s[pos];
	}
	const char* string::c_str() const {
		return s;
	}
	void string::clear() {
		memset(s, 0, len + 1);        //�η� �ʱ�ȭ �Ǵ��� 0���� �ʱ�ȭ �Ǵ��� Ȯ���ϱ�
	}
	void string::push_back(char c) {
		char* t;
		t = s;
		s = new char[len + 2];
		len = strlen(t);  // ���ڿ��� ���̰� �ٲ�����Ƿ� len�� �ֽ�ȭ

		strcpy(s, t);
		s[len] = c;
		s[len + 1] = '\0';
	}
	int string::compare(const string* str) const {
		return strcmp(s, str->c_str());               // str->s     strncmp(s, str->s, len + 1);
	}
	string& string::replace(size_t pose, size_t len, const string& str) {
		size_t new_len = this->len + str.len - len;   //���ڿ��� ���� ���Ҵ�
		char* after = new char[new_len + 1];
		strncpy(after, s, pose);              //���� ���ڿ� �պκ�
		strncpy(after + pose, str.s, str.len);   //��ü�� ���ڿ�
		strncpy(after + pose + str.len, s + pose + str.len, this->len - pose - len);  //���� ���ڿ��� �޺κ�
		after[new_len] = '\0';
		delete[] s;
		s = after;
		this->len = new_len;
		return *this;
	}
	string string::substr(size_t pos, size_t len) const {
		string sub;                  //���ο� ��ü ����
		sub.s = new char[len + 1];  
		strncpy(sub.s, s + pos, len);
		sub.s[len] = '\0';
		sub.len = len;
		return sub;
	}
	size_t string::find(const string& str, size_t pos = 0) const {
		pos = 0;
		char* ptr = strstr(s + pos, str.s);
		if (ptr == nullptr) {    // ã���� �ϴ� ���ڿ��� ���� ���
			return -1;    //string::npos�� ���� �Ϲ������� -1�̴�.
		}
		return ptr - s;  //������ ������ ���� ã�����ϴ� ���ڿ��� ���۵Ǵ� ��ġ�� ��ȯ��
	}
	int stoi(const string& str, size_t* idx, int base = 10) {
		const char* ptr = str.c_str();
		int a = 0;
		int negative = 0;
		int count = 0;      //���� �� ���ڿ��� ���۵Ǵ� ��ġ�� ������ ����

		if (*ptr == '-')      //����ǥ���� ���� �տ� -���ڸ� �о�帲
		{
			negative = 1;
			ptr++;
			count++;
		}
		while (*ptr != '\0' && (*ptr >= '0' && *ptr <= '9'))  //NULL���� �ƴ� 0���� 9�� ���ڸ��� �޾Ƽ� ������ ��ȯ
		{
			a = (a * 10) + (*ptr - '0');   //'0'��ŭ�� �ƽ�Ű �ڵ尪�� ���༭ ���ڸ� ������ ��ȯ�ϰ� �ڸ����� 1�ڸ��� �÷���
			ptr++;
			count++;
		}

		if (negative)      //-��ȣ�� ���� ��� ���������� ������ �ٲپ���
		{
			a *= -1.0;
		}
		if (idx) {  //idx�� ���� �ƴ϶��
			*idx = count;    //idx���� ��ȯ�� ���� ������ ���� ���ڿ��� ��ġ�� ������
		}
		return a;
	}
	float stof(const string& str, size_t* idx) {
		const char* ptr = str.c_str();
		int loc = 0;    //���� �� ���ڿ��� ���۵Ǵ� ��ġ�� ������ ����

		double result = 0.0;
		double decimal = 0.0;
		int negative = 0;
		int count = 0;
		int ex = 0;    //�Ҽ��� ǥ������� e-�� e+�� ���� ������ ����
		if (*ptr == '-') {    //����ǥ���� ���� �տ� -���ڸ� �о�帲
			negative = 1;
			ptr++;
			loc++;
		}

		while (*ptr != '\0' && (*ptr >= '0' && *ptr <= '9')) {  //str�� ����Ű�� ������ ����� ���� NULL�� �ƴϰ� 0���� 9������ ���ڸ� �о� �帲
			result = (result * 10.0) + static_cast<double>(*ptr - '0');   //���� double������ �ٲٰ� �ڸ����� ������
			ptr++;
			loc++;
		}

		if (*ptr == '.') {  //���ڵ��� �д� ���� �Ҽ����� ������ ��� �Ҽ��� ������ ������ �ٷ�
			ptr++;
			while (*ptr != '\0' && (*ptr >= '0' && *ptr <= '9')) {   //�Ҽ��� ������ ������ double������ ��ȯ
				decimal = (decimal * 10.0) + static_cast<double>(*ptr - '0');
				ptr++;
				count++;
				loc++;
			}
			result += decimal / pow(10.0, count);   //�Ҽ��� ������ ���ڵ� �ڸ����� ���߾� result���� ������
		}
		if (*ptr == 'e' || *ptr == 'E') {  //�ε��Ҽ���ǥ���� ���� ���� ó��
			ptr++;
			if (*ptr == '-') {   //e���� ���ڰ� '-'�� ��� �� �� ����ŭ 10�� �����Ͽ� ����� �ڸ����� ����
				ptr++;
				ex = static_cast<double>(*ptr - '0');
				result /= pow(10.0, ex);
				loc++;
			}

			else if (*ptr == '+') {  //e���� ���ڰ� '+'�� ��� �� �� ����ŭ 10�� �����Ͽ� ���ؼ� �ڸ����� ����
				ptr++;
				ex = static_cast<double>(*ptr - '0');
				result *= pow(10.0, ex);
				loc++;
			}
		}

		if (negative) {    //-��ȣ�� ���� ��� ���������� ������ �ٲپ���
			result *= -1.0;
		}
		if (idx) {
			*idx = loc;
		}
		return result;
	}
	string to_string(int val) {
		string icons = to_string(val);
		return icons;
	}
	string to_string(float val) {
		string fcons = to_string(val);
		return fcons;
	}
}