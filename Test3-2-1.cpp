#include<iostream>
#include<cstdlib>

using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
};

void PrintList(Node* Head) {   // ���� ó�� ��带 ���ڷ� �޾� ���鿡 ����� ������ ����ϴ� �Լ�
    cout << "List: ";
    while (Head != nullptr) {
        cout << Head->value << "  ";
        Head = Head->next;
    }
    cout << endl << endl;
}

void insertionSort(Node*& head) {
    int list[16] = { 0 };
    Node* work = head;

    for (int i = 0; i < 16 && work != nullptr; i++) {    // ������ �� �迭�� ����
        list[i] = work->value;
        work = work->next;
    }

    int len = 16;
    int temp, i, j;

    for (i = 1; i < len; i++) {   // insert���� �˰����� ���� �迭�� ����� ������ ������������ ������
        temp = list[i];
        j = i - 1;

        for (; j >= 0 && list[j] < temp; j--) {
            list[j + 1] = list[j];
        }

        list[j + 1] = temp;
    }

    work = head;
    for (int i = 0; i < 16 && work != nullptr; i++) {   // ���ĵ� �迭�� �ٽ� ��忡 ����
        work->value = list[i];
        work = work->next;
    }
}

Node* Binary_Search(Node* Head, int n) {   // ���ĵ� ������ ����Ž���� ���� ã�����ϴ� value�� ã�� �Լ�
    if (!Head) {
        return nullptr;
    }
    int count = 0;
    Node* low = Head;
    Node* high = nullptr;
    Node* mid = Head;
    Node* work = Head;

    while (true) {    // ��ó�� �ʱ� ���� ����� ������ �ľ��Ͽ� �߰���ġ�� ������� count������ ���� Ȯ����
        work = work->next;
        count++; 
        if (work->next == nullptr) {
            high = work;
            break;
        }
            
    }
    count /= 2;    // ã�� ������ �������� ���̱� ����
    PrintList(low);

    while (low != high) {   // ������ �ٿ����鼭 low�� high �� ���� ��带 ����Ű�� ����
        mid = low;
        for (int i = 0; i < count; i++) {
            mid = mid->next;
        }
        if (mid->value == n) {  // mid�� ���� ��ġ ������ ������ �Լ� ������ ��� ��ȯ
            cout << "search ����" << endl;
            return mid;
        }
        else if (mid->value > n) {   // ���������� �̵�
            work = mid->next;
            if (n < mid->value && n > work->value) {  // �߰� ���� �ƴ� mid���� �� ���� ���� ���̿� �ش��ϴ� search value�� ���
                int m = mid->value - n;
                int w = n - work->value;    // ��� �� ���� ���� ���̸� �ּ�ȭ �ϴ� ���� ����� ��带 ��ȯ
                if (m <= w) {
                    return mid;
                }
                else
                    return work;
            }
            low = mid->next;
            count /= 2;
            for (int i = 0; i < count; i++) {
                mid = mid->next;
            }
        }
        else if (mid->value < n) {  // �������� �̵�
            work = mid->next;
            if (n < mid->value && n > work->value) {
                int m = mid->value - n;
                int w = n - work->value;
                if (m <= w) {
                    return mid;
                }
                else
                    return work;
            }
            high = mid;
            count /= 2;
            for (int i = 0; i < count; i++) {
                mid = mid->next;
            }
        }

        work = low;
        cout << "List: ";      // ã�� ������ �������� ���̸鼭 ã�� ������ �����
        while (work != high) {
            cout << work->value << "  ";
            work = work->next;
        }
        cout << work->value << "  ";
        cout << endl;
    }
}

int main() {
    srand(time(NULL));    // �õ� ����

    Node* head = nullptr;
    Node* work = nullptr;

    int arr[16] = { -1 };
    int j = 0;
    int num;
 
    for (int i = 0; i < 16; i++) {    // ���� �߻��� �ߺ��Ǵ� ������ �����ϸ鼭 ������ ������ �迭�� �ӽ� ����
        num = rand() % 201;
        while (1) {
            for (j = 0; j < 16; j++) {
                if (arr[j] == num) {
                    break;
                }
            }
            if (j != 16) {
                num = rand() % 201;
            }
            else
                break;
        }
        arr[i] = num;
    }

    for (int i = 0; i < 16; i++) {  // ���鿡 �ߺ����� �ʴ� ������ ����
        Node* New = new Node;
        New->value = arr[i];

        if (head == nullptr) {
            head = New;
            work = New;
        }
        else {
            work->next = New;
            work = New;
        }
    }
    cout << "���ĵ��� ���� ���� ���" << endl;
    PrintList(head);


    insertionSort(head);  // �������� ����� ������ �������� �˰����� ���ؼ� ������������ �����ϴ� �Լ�
    cout << "������������ �������ĵ� ���" << endl;
    PrintList(head);

    num = rand() % 201;   // ã�� ���� ���Ƿ� ����

    cout << "ã���� �ϴ� Search value: " << num << endl;


    Node* temp = Binary_Search(head, num);

    if (temp->value != num) {
        cout << "search value�� ã�� ���Ͽ����ϴ�" << endl << "�ٻ簪: " << temp->value << endl;
    }
    else {
        cout << "search value�� ã�ҽ��ϴ�" << endl << "search value: " << temp->value << endl;
    }

    return 0;
}


