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
		len = strlen(s);     //길이를 계산해서 저장
		this->s = new char[len + 1];   //메모리 동적할당
		strcpy(this->s, s);
	}
	string::string(const string& str) {
		len = str.len;         //객체의 멤버변수 그대로 복사
		s = new char[len + 1];
		strcpy(s, str.s);   
	}
	string::~string() {
		delete[] s;
	}
	string& string::assign(const string& str) {
		if (this != &str) {  // 자기 자신과의 대입을 방지합니다.
			delete[] s;  // 이전 문자열 값을 가리키던 메모리를 해제합니다.
			len = str.len;  // 길이를 복사된 문자열 길이로 설정합니다.
			s = new char[len + 1];  // 새로운 메모리를 할당합니다.
			strcpy(s, str.s);  // 복사된 문자열을 새로 할당한 메모리에 복사합니다.
		}
		return *this;  // 현재 객체의 참조를 반환합니다.
	}
	char& string::at(size_t pos) {
		return s[pos];
	}
	const char* string::c_str() const {
		return s;
	}
	void string::clear() {
		memset(s, 0, len + 1);        //널로 초기화 되는지 0으로 초기화 되는지 확인하기
	}
	void string::push_back(char c) {
		char* t;
		t = s;
		s = new char[len + 2];
		len = strlen(t);  // 문자열의 길이가 바뀌었으므로 len값 최신화

		strcpy(s, t);
		s[len] = c;
		s[len + 1] = '\0';
	}
	int string::compare(const string* str) const {
		return strcmp(s, str->c_str());               // str->s     strncmp(s, str->s, len + 1);
	}
	string& string::replace(size_t pose, size_t len, const string& str) {
		size_t new_len = this->len + str.len - len;   //문자열의 길이 재할당
		char* after = new char[new_len + 1];
		strncpy(after, s, pose);              //원래 문자열 앞부분
		strncpy(after + pose, str.s, str.len);   //대체할 문자열
		strncpy(after + pose + str.len, s + pose + str.len, this->len - pose - len);  //원래 문자열의 뒷부분
		after[new_len] = '\0';
		delete[] s;
		s = after;
		this->len = new_len;
		return *this;
	}
	string string::substr(size_t pos, size_t len) const {
		string sub;                  //새로운 객체 생성
		sub.s = new char[len + 1];  
		strncpy(sub.s, s + pos, len);
		sub.s[len] = '\0';
		sub.len = len;
		return sub;
	}
	size_t string::find(const string& str, size_t pos = 0) const {
		pos = 0;
		char* ptr = strstr(s + pos, str.s);
		if (ptr == nullptr) {    // 찾고자 하는 문자열이 없을 경우
			return -1;    //string::npos의 값은 일반적으로 -1이다.
		}
		return ptr - s;  //포인터 연산을 통해 찾고자하는 문자열이 시작되는 위치를 반환함
	}
	int stoi(const string& str, size_t* idx, int base = 10) {
		const char* ptr = str.c_str();
		int a = 0;
		int negative = 0;
		int count = 0;      //정수 뒤 문자열이 시작되는 위치를 저장할 변수

		if (*ptr == '-')      //음수표현일 때는 앞에 -문자를 읽어드림
		{
			negative = 1;
			ptr++;
			count++;
		}
		while (*ptr != '\0' && (*ptr >= '0' && *ptr <= '9'))  //NULL값이 아닌 0부터 9의 문자만을 받아서 정수로 변환
		{
			a = (a * 10) + (*ptr - '0');   //'0'만큼의 아스키 코드값을 빼줘서 문자를 정수로 변환하고 자릿수를 1자리씩 올려줌
			ptr++;
			count++;
		}

		if (negative)      //-부호가 있을 경우 최종적으로 음수로 바꾸어줌
		{
			a *= -1.0;
		}
		if (idx) {  //idx가 널이 아니라면
			*idx = count;    //idx에는 변환된 정수 다음에 오는 문자열의 위치를 저장함
		}
		return a;
	}
	float stof(const string& str, size_t* idx) {
		const char* ptr = str.c_str();
		int loc = 0;    //숫자 뒤 문자열이 시작되는 위치를 저장할 변수

		double result = 0.0;
		double decimal = 0.0;
		int negative = 0;
		int count = 0;
		int ex = 0;    //소수점 표현방식인 e-와 e+의 갑을 저장할 변수
		if (*ptr == '-') {    //음수표현일 때는 앞에 -문자를 읽어드림
			negative = 1;
			ptr++;
			loc++;
		}

		while (*ptr != '\0' && (*ptr >= '0' && *ptr <= '9')) {  //str이 가리키는 공간에 저장된 값이 NULL이 아니고 0부터 9까지의 문자를 읽어 드림
			result = (result * 10.0) + static_cast<double>(*ptr - '0');   //수를 double형으로 바꾸고 자리수를 맞춰줌
			ptr++;
			loc++;
		}

		if (*ptr == '.') {  //숫자들을 읽는 도중 소수점이 나왔을 경우 소수점 이하의 수들을 다룸
			ptr++;
			while (*ptr != '\0' && (*ptr >= '0' && *ptr <= '9')) {   //소수점 이하의 수들을 double형으로 변환
				decimal = (decimal * 10.0) + static_cast<double>(*ptr - '0');
				ptr++;
				count++;
				loc++;
			}
			result += decimal / pow(10.0, count);   //소수점 이하의 숫자도 자리수를 맞추어 result값에 더해줌
		}
		if (*ptr == 'e' || *ptr == 'E') {  //부동소수점표현에 대한 예외 처리
			ptr++;
			if (*ptr == '-') {   //e다음 문자가 '-'일 경우 그 뒤 값만큼 10에 제곱하여 나누어서 자릿수를 맞춤
				ptr++;
				ex = static_cast<double>(*ptr - '0');
				result /= pow(10.0, ex);
				loc++;
			}

			else if (*ptr == '+') {  //e다음 문자가 '+'일 경우 그 뒤 값만큼 10에 제곱하여 곱해서 자릿수를 맞춤
				ptr++;
				ex = static_cast<double>(*ptr - '0');
				result *= pow(10.0, ex);
				loc++;
			}
		}

		if (negative) {    //-부호가 있을 경우 최종적으로 음수로 바꾸어줌
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