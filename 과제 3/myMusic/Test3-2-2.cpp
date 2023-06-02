#define _CRT_SECURE_NO_WARNINGS
#include"myMusic.h"
#include<iostream>
#include<string>

using namespace std;

void print(myMusic* thing)  // 저장된 음악정보를 출력하는 함수
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
	myMusic* playlist[100];  // 클래스 포인터 배열 선안

	char arr[15] = {};
	int i = 0;
	char str[100];
	char* token;
	string m_title;
	string m_singer;
	string m_album;
	int m_track_no;
	int m_year;

	cout << "명령어 입력(input, find, change, print, exit): ";
	cin >> arr;

	while (1) {
		
		if (!strcmp(arr, "input")) {
			if (i == 100) {  // 최대 용량보다 더 많이 저장할 경우 예외처리
				cout << "myMusic에 더 이상 저장할 공간이 없습니다." << endl;
				cout << "명령어 입력(input, find, change, print, exit): ";
				cin >> arr;
				continue;
			}
			playlist[i] = new myMusic;

			cout << "제목,가수,앨범,발매년도,TrackNo 순으로 입력" << endl;
			cin >> str;
			token = strtok(str, ",");
			playlist[i]->setTitle(token);    // class 멤버 변수에 각 정보를 저장
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

			cout << "검색목록(Title, Singer, Album, Year, TrackNo), 이름 " << endl;
			cin >> find;
			list = strtok(find, ",");
			name = strtok(NULL, ",");

			for (a = 0; a < i; a++) {    // 기존의 음악정보 list에서 찾고자 하는 음악정보를 탐색함
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
			if (a == i) {   // 찾고자 하는 정보가 없을 경우 예외처리
				cout << "존재 하지 않는 목록입니다." << endl;
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

			cout << "검색목록(Title, Singer, Album, Year, TrackNo), 이름 " << endl;
			cin >> find;
			list = strtok(find, ",");
			name = strtok(NULL, ",");

			for (a = 0; a < i; a++) {    // 변경하고자 하는 음악정보 탐색
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
				cout << "존재 하지 않는 목록입니다." << endl;
				cout << "명령어 입력(input, find, change, print, exit): ";
				cin >> arr;
				continue;
			}
			cout << "-----현재 내용-----" << endl;
			print(playlist[a]);          // 변경하고자 하는 음악정보 확인을 위해 출력

			cout << "제목,가수,앨범,발매년도,TrackNo 순으로 입력" << endl;
			cin >> str;
			token = strtok(str, ",");
			playlist[a]->setTitle(token);    // class 멤버 변수에 각 정보를 저장
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
			for (int k = 0; k < i; k++)   // 저장된 모든 음악정보 출력
				print(playlist[k]);   
		}
		else if (!strcmp(arr, "exit")) {
			break;
		}
		else
			cout << "Wrong command!!!" << endl;    // 그외 명령어가 잘못 입력되었을 경우 예외처리

		cout << "명령어 입력(input, find, change, print, exit): ";
		cin >> arr;

	}
	for (int j = 0; j < i; j++) {  // myMusic 객체에 동적할당한 메모리 해제
		delete playlist[j];
	}

	return 0;
}