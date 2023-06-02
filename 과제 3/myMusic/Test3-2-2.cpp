#define _CRT_SECURE_NO_WARNINGS
#include"myMusic.h"
#include<iostream>
#include<string>

using namespace std;

void print(myMusic* thing)  // ����� ���������� ����ϴ� �Լ�
{
	cout << "Title: " << thing->getTitle() << endl;
	cout << "Singer: " << thing->getSinger() << endl;
	cout << "Album: " << thing->getAlbum() << endl;
	cout << "Year: " << thing->getYear() << endl;
	cout << "Track No: " << thing->getTrackNo() << endl;
	cout << "-----------------" << endl;
}

int main()
{
	myMusic* playlist[100];  // Ŭ���� ������ �迭 ����

	char arr[15] = {};
	int i = 0;
	char str[100];
	char* token;
	string m_title;
	string m_singer;
	string m_album;
	int m_track_no;
	int m_year;

	cout << "��ɾ� �Է�(input, find, change, print, exit): ";
	cin >> arr;

	while (1) {
		
		if (!strcmp(arr, "input")) {
			if (i == 100) {  // �ִ� �뷮���� �� ���� ������ ��� ����ó��
				cout << "myMusic�� �� �̻� ������ ������ �����ϴ�." << endl;
				cout << "��ɾ� �Է�(input, find, change, print, exit): ";
				cin >> arr;
				continue;
			}
			playlist[i] = new myMusic;

			cout << "����,����,�ٹ�,�߸ų⵵,TrackNo ������ �Է�" << endl;
			cin >> str;
			token = strtok(str, ",");
			playlist[i]->setTitle(token);    // class ��� ������ �� ������ ����
			token = strtok(NULL, ",");
			playlist[i]->setSinger(token);
			token = strtok(NULL, ",");
			playlist[i]->setAlbum(token);
			token = strtok(NULL, ",");
			playlist[i]->setYear(stoi(token));
			token = strtok(NULL, ",");
			playlist[i]->setTrackNo(stoi(token));
			i++;
		}
		else if (!strcmp(arr, "find")) {
			char find[64];
			char* list;
			char* name;
			int a;

			cout << "�˻����(Title, Singer, Album, Year, TrackNo), �̸� " << endl;
			cin >> find;
			list = strtok(find, ",");
			name = strtok(NULL, ",");

			for (a = 0; a < i; a++) {    // ������ �������� list���� ã���� �ϴ� ���������� Ž����
				if (!strcmp(list, "Title")) {
					if (!strcmp(name, playlist[a]->getTitle()))
						break;
				}
				else if (!strcmp(list, "Singer")) {
					if (!strcmp(name, playlist[a]->getSinger()))
						break;
				}
				else if (!strcmp(list, "Album")) {
					if (!strcmp(name, playlist[a]->getAlbum())) 
						break;
				}
				else if (!strcmp(list, "Year")) {
					if (stoi(name) == playlist[a]->getYear())
						break;
				}
				else if (!strcmp(list, "TrackNo")) {
					if (stoi(name) == playlist[a]->getTrackNo())
						break;
				}
			}
			if (a == i) {   // ã���� �ϴ� ������ ���� ��� ����ó��
				cout << "���� ���� �ʴ� ����Դϴ�." << endl;
				continue;
			}
			cout << "-----Find-----" << endl;
			print(playlist[a]);
		}

		else if (!strcmp(arr, "change")) {
			char find[64];
			char* list;
			char* name;
			int a;

			cout << "�˻����(Title, Singer, Album, Year, TrackNo), �̸� " << endl;
			cin >> find;
			list = strtok(find, ",");
			name = strtok(NULL, ",");

			for (a = 0; a < i; a++) {    // �����ϰ��� �ϴ� �������� Ž��
				if (!strcmp(list, "Title")) {
					if (!strcmp(name, playlist[a]->getTitle()))
						break;
				}
				else if (!strcmp(list, "Singer")) {
					if (!strcmp(name, playlist[a]->getSinger()))
						break;
				}
				else if (!strcmp(list, "Album")) {
					if (!strcmp(name, playlist[a]->getAlbum()))
						break;
				}
				else if (!strcmp(list, "Year")) {
					if (stoi(name) == playlist[a]->getYear())
						break;
				}
				else if (!strcmp(list, "TrackNo")) {
					if (stoi(name) == playlist[a]->getTrackNo())
						break;
				}
			}
			if (a == i) {
				cout << "���� ���� �ʴ� ����Դϴ�." << endl;
				cout << "��ɾ� �Է�(input, find, change, print, exit): ";
				cin >> arr;
				continue;
			}
			cout << "-----���� ����-----" << endl;
			print(playlist[a]);          // �����ϰ��� �ϴ� �������� Ȯ���� ���� ���

			cout << "����,����,�ٹ�,�߸ų⵵,TrackNo ������ �Է�" << endl;
			cin >> str;
			token = strtok(str, ",");
			playlist[a]->setTitle(token);    // class ��� ������ �� ������ ����
			token = strtok(NULL, ",");
			playlist[a]->setSinger(token);
			token = strtok(NULL, ",");
			playlist[a]->setAlbum(token);
			token = strtok(NULL, ",");
			playlist[a]->setYear(stoi(token));
			token = strtok(NULL, ",");
			playlist[a]->setTrackNo(stoi(token));
	
		}
		else if (!strcmp(arr, "print")) {
			cout << "-----print-----" << endl;
			for (int k = 0; k < i; k++)   // ����� ��� �������� ���
				print(playlist[k]);   
		}
		else if (!strcmp(arr, "exit")) {
			break;
		}
		else
			cout << "Wrong command!!!" << endl;    // �׿� ��ɾ �߸� �ԷµǾ��� ��� ����ó��

		cout << "��ɾ� �Է�(input, find, change, print, exit): ";
		cin >> arr;

	}
	for (int j = 0; j < i; j++) {  // myMusic ��ü�� �����Ҵ��� �޸� ����
		delete playlist[j];
	}

	return 0;
}