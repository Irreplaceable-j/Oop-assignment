#include<iostream>

using namespace std;

char* my_strtok(char* str)
{
	static char* tok = str;   // tok의 값을 한번만 초기화
	char* ptr = tok;

	if (*tok == '\0')   // 문자열의 마지막을 가리켜 더 이상 추출할 문자열이 없을 경우 NULL값 반환
		return NULL;

	while (*tok != '\0') {  
		if (*tok == '@' || *tok == '.') {  //'@'문자 또는 '.'문자를 인식할 때 해당 인덱스에 문자를 널문자로 바꿈
			*tok = '\0';
			tok++;
			break;
		}
		tok++;
	}
	return ptr;  // 문자열의 시작값을 반환함
}

int main()
{
	char email[100] = {}; // 널값으로 문자열 배열 초기화
	char* temp;
	cout << "이메일을 입력해주세요!" << endl;
	cin >> email;

	temp = my_strtok(email);  // 일단 한번 수행해서 temp에 주소값을 저장함
	cout << temp << endl;

	while (1) {    // 문자열의 끝에 도달해 temp에 NULL값이 저장되면 출력을 멈춤
		temp = my_strtok(email);
		if (temp == NULL)
			break;
		cout << temp << endl;
	}

	return 0;
}