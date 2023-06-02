#include<iostream>
#include<string>

using namespace std;

struct Node {
	string str;
	Node* next = nullptr;
};

string toLower(string str) {  // ���ڿ� �߿� �빮�ڰ� �������� �� �ҹ��ڷ� ��ȯ�����ִ� �Լ�
	string result = str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {    // �빮�ڰ� ������ �ҹ��ڷ� ������
			result[i] = str[i] + 32;      // �빮�ڿ� �ҹ����� �ƽ�Ű �ڵ尪 ������ 32�� ���ؼ� �빮�ڸ� �ҹ��ڷ� ġȯ��
		}
	}
	return result;
}
void Merge_List(Node* p1, Node* p2, Node* p3)
{
	Node* head = nullptr;
	Node* off = nullptr;   // ������ ��带 �ӽ������� ���� ������
	Node* work = nullptr;
	string temp;

	while (p1 != nullptr || p2 != nullptr)
	{
		p3 = new Node;
		if (head == nullptr)
			head = p3;

		if (p1 == nullptr) {
			temp = p2->str;
			off = p2;
			p2 = p2->next;
			delete off;
		}
		else if (p2 == nullptr) {
			temp = p1->str;
			off = p1;
			p1 = p1->next;
			delete off;
		}
		else if (p1 != nullptr && p2 != nullptr && p1->str < p2->str) {  // p1�� ����� ���ڿ��� p2�� ���ڿ� ���� �� ���� ��
			temp = p1->str;
			off = p1;
			p1 = p1->next;
			delete off;
		}
		else if (p1 != nullptr && p2 != nullptr && p1->str >= p2->str) {  // p1�� ����� ���ڿ���  p2�� ���ڿ� ���� �� Ŭ ��
			temp = p1->str;
			temp = p2->str;
			off = p2;
			p2 = p2->next;
			delete off;
		}

		Node* pre;
		string low = toLower(temp);

		work = head;
		pre = work->next;

		while (work != nullptr) {
			if (work->str == "" && work->next == nullptr) {   // ����ó�� ��� �ϳ��� ���鶧
				p3->str = temp;
				break;
			}
			if (low < toLower(work->str)) {   // ���ڿ��� ���� ���� ���
				p3->str = temp;
				p3->next = head;
				head = p3;
				break;
			}
		    else if (work->next != nullptr && low >= toLower(work->str) && low < toLower(pre->str)) {  // ���ڿ��� �߰��� ���� ��� 
				p3->str = temp;
				p3->next = pre;
				work->next = p3;
				break;
			}
			else if (work->next == nullptr) {  // ���ڿ��� ���� �������� �� ���
				p3->str = temp;
				work->next = p3;
				break;
			}
			pre = pre->next;
			work = work->next;

		}
	}
	cout << endl << "Output>>" << endl << "Result: ";
	work = head;
	while (work != nullptr) {      // ��� ���
		cout << work->str << " ";
		work = work->next;
	}
	work = head;
	while (work != nullptr) {   // �����Ҵ�� �޸� ����
		work = work->next;
		delete head;
		head = work;
	}
}
int main()
{
	string input;
	string temp;

	Node* head1 = nullptr;
	Node* head2 = nullptr;
	Node* work = nullptr;
	Node* list3 = nullptr;

	cout << "Input>>" << endl << "Input list 1: ";   // list 1�� ����� ����
	getline(cin, input);
	for (int i = 0; i <= input.length(); i++) {
		if (input[i] == ' ' || input[i] == '\0')   //���鹮�ڱ��� �Է¹��� ���ڿ��� ���� ������ ���ڿ��� �ɰ��� ��忡 ����
		{
			Node* list1 = new Node;

			list1->str = temp;
			temp.clear();       // string�� �ֱ�ȭ����

			if (head1 == nullptr) {
				head1 = list1;
				work = list1;
			}
			else {
				work->next = list1;
				work = list1;
			}
		}
		else
			temp += input[i];  // ���ڸ� �ϳ��� ������
	}
	
	cout << "Input list 2: ";    // list 2�� ����� ����
	getline(cin, input);
	for (int i = 0; i <= input.length(); i++) {
		if (input[i] == ' ' || input[i] == '\0')
		{
			Node* list2 = new Node;

			list2->str = temp;
			temp.clear();

			if (head2 == nullptr) {
				head2 = list2;
				work = list2;
			}
			else {
				work->next = list2;
				work = list2;
			}
		}
		else
			temp += input[i];
	}
	Merge_List(head1, head2, list3);    // ������ �����Ͽ� ���ĺ� ������ �������ִ� �Լ� ȣ��
	cout << endl;

	return 0;
}