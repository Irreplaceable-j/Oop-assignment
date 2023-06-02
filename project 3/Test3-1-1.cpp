#include<iostream>
#include<string>

using namespace std;

struct Node {
	string str;
	Node* next = nullptr;
};

string toLower(string str) {  // 문자열 중에 대문자가 섞여있을 때 소문자로 변환시켜주는 함수
	string result = str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {    // 대문자가 있으면 소문자로 변경함
			result[i] = str[i] + 32;      // 대문자와 소문자의 아스키 코드값 차이인 32을 더해서 대문자를 소문자로 치환함
		}
	}
	return result;
}
void Merge_List(Node* p1, Node* p2, Node* p3)
{
	Node* head = nullptr;
	Node* off = nullptr;   // 삭제할 노드를 임시저장해 놓는 포인터
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
		else if (p1 != nullptr && p2 != nullptr && p1->str < p2->str) {  // p1에 저장된 문자열이 p2의 문자열 보다 더 작을 때
			temp = p1->str;
			off = p1;
			p1 = p1->next;
			delete off;
		}
		else if (p1 != nullptr && p2 != nullptr && p1->str >= p2->str) {  // p1에 저장된 문자열이  p2의 문자열 보다 더 클 때
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
			if (work->str == "" && work->next == nullptr) {   // 가정처음 노드 하나를 만들때
				p3->str = temp;
				break;
			}
			if (low < toLower(work->str)) {   // 문자열이 제일 작을 경우
				p3->str = temp;
				p3->next = head;
				head = p3;
				break;
			}
		    else if (work->next != nullptr && low >= toLower(work->str) && low < toLower(pre->str)) {  // 문자열이 중간에 들어가는 경우 
				p3->str = temp;
				p3->next = pre;
				work->next = p3;
				break;
			}
			else if (work->next == nullptr) {  // 문자열이 가장 마지막에 들어갈 경우
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
	while (work != nullptr) {      // 결과 출력
		cout << work->str << " ";
		work = work->next;
	}
	work = head;
	while (work != nullptr) {   // 동적할당된 메모리 해제
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

	cout << "Input>>" << endl << "Input list 1: ";   // list 1를 만드는 과정
	getline(cin, input);
	for (int i = 0; i <= input.length(); i++) {
		if (input[i] == ' ' || input[i] == '\0')   //공백문자까지 입력받은 문자열을 띄어쓰기 단위로 문자열을 쪼개어 노드에 저장
		{
			Node* list1 = new Node;

			list1->str = temp;
			temp.clear();       // string을 최기화해줌

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
			temp += input[i];  // 문자를 하나씩 저장함
	}
	
	cout << "Input list 2: ";    // list 2를 만드는 과정
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
	Merge_List(head1, head2, list3);    // 노드들을 병합하여 알파벳 순으로 정렬해주는 함수 호출
	cout << endl;

	return 0;
}