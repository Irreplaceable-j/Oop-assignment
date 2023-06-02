#include<iostream>
#include<cstdlib>

using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
};

void PrintList(Node* Head) {   // 가장 처음 노드를 인자로 받아 노드들에 저장된 값들을 출력하는 함수
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

    for (int i = 0; i < 16 && work != nullptr; i++) {    // 노드들의 값 배열에 복사
        list[i] = work->value;
        work = work->next;
    }

    int len = 16;
    int temp, i, j;

    for (i = 1; i < len; i++) {   // insert정렬 알고리즘을 통해 배열에 저장된 값들을 내림차순으로 정렬함
        temp = list[i];
        j = i - 1;

        for (; j >= 0 && list[j] < temp; j--) {
            list[j + 1] = list[j];
        }

        list[j + 1] = temp;
    }

    work = head;
    for (int i = 0; i < 16 && work != nullptr; i++) {   // 정렬된 배열을 다시 노드에 저장
        work->value = list[i];
        work = work->next;
    }
}

Node* Binary_Search(Node* Head, int n) {   // 정렬된 노드들을 이진탐색을 통해 찾고자하는 value를 찾는 함수
    if (!Head) {
        return nullptr;
    }
    int count = 0;
    Node* low = Head;
    Node* high = nullptr;
    Node* mid = Head;
    Node* work = Head;

    while (true) {    // 맨처음 초기 설정 노드의 개수를 파악하여 중간위치가 어디인지 count변수를 통해 확인함
        work = work->next;
        count++; 
        if (work->next == nullptr) {
            high = work;
            break;
        }
            
    }
    count /= 2;    // 찾을 범위를 절반으로 줄이기 위함
    PrintList(low);

    while (low != high) {   // 범위를 줄여가면서 low가 high 와 같은 노드를 가리키면 멈춤
        mid = low;
        for (int i = 0; i < count; i++) {
            mid = mid->next;
        }
        if (mid->value == n) {  // mid의 값이 서치 벨류와 같으면 함수 종료후 노드 반환
            cout << "search 성공" << endl;
            return mid;
        }
        else if (mid->value > n) {   // 오른쪽으로 이동
            work = mid->next;
            if (n < mid->value && n > work->value) {  // 중간 값이 아닌 mid값과 그 다음 값의 사이에 해당하는 search value일 경우
                int m = mid->value - n;
                int w = n - work->value;    // 노드 값 간의 절대 차이를 최소화 하는 가장 가까운 노드를 반환
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
        else if (mid->value < n) {  // 왼쪽으로 이동
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
        cout << "List: ";      // 찾을 범위를 절반으로 줄이면서 찾는 과정을 출력함
        while (work != high) {
            cout << work->value << "  ";
            work = work->next;
        }
        cout << work->value << "  ";
        cout << endl;
    }
}

int main() {
    srand(time(NULL));    // 시드 설정

    Node* head = nullptr;
    Node* work = nullptr;

    int arr[16] = { -1 };
    int j = 0;
    int num;
 
    for (int i = 0; i < 16; i++) {    // 난수 발생후 중복되는 값들을 제거하면서 무작위 정수를 배열에 임시 저장
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

    for (int i = 0; i < 16; i++) {  // 노드들에 중복되지 않는 난수들 저장
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
    cout << "정렬되지 않은 원래 노드" << endl;
    PrintList(head);


    insertionSort(head);  // 난수들이 저장된 노드들을 삽입정렬 알고리즘을 통해서 내림차순으로 정렬하는 함수
    cout << "내림차순으로 삽입정렬된 노드" << endl;
    PrintList(head);

    num = rand() % 201;   // 찾을 값을 임의로 설정

    cout << "찾고자 하는 Search value: " << num << endl;


    Node* temp = Binary_Search(head, num);

    if (temp->value != num) {
        cout << "search value를 찾지 못하였습니다" << endl << "근사값: " << temp->value << endl;
    }
    else {
        cout << "search value를 찾았습니다" << endl << "search value: " << temp->value << endl;
    }

    return 0;
}


