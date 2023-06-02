#include<iostream>

using namespace std;

char* my_strtok(char* str)
{
	static char* tok = str;   // tok�� ���� �ѹ��� �ʱ�ȭ
	char* ptr = tok;

	if (*tok == '\0')   // ���ڿ��� �������� ������ �� �̻� ������ ���ڿ��� ���� ��� NULL�� ��ȯ
		return NULL;

	while (*tok != '\0') {  
		if (*tok == '@' || *tok == '.') {  //'@'���� �Ǵ� '.'���ڸ� �ν��� �� �ش� �ε����� ���ڸ� �ι��ڷ� �ٲ�
			*tok = '\0';
			tok++;
			break;
		}
		tok++;
	}
	return ptr;  // ���ڿ��� ���۰��� ��ȯ��
}

int main()
{
	char email[100] = {}; // �ΰ����� ���ڿ� �迭 �ʱ�ȭ
	char* temp;
	cout << "�̸����� �Է����ּ���!" << endl;
	cin >> email;

	temp = my_strtok(email);  // �ϴ� �ѹ� �����ؼ� temp�� �ּҰ��� ������
	cout << temp << endl;

	while (1) {    // ���ڿ��� ���� ������ temp�� NULL���� ����Ǹ� ����� ����
		temp = my_strtok(email);
		if (temp == NULL)
			break;
		cout << temp << endl;
	}

	return 0;
}