#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

string toLower(string str) {  // 문자열 중에 대문자가 섞여있을 때 소문자로 변환시켜주는 함수
	string result = str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {    // 대문자가 있으면 소문자로 변경함
			result[i] = str[i] + 32;      // 대문자와 소문자의 아스키 코드값 차이인 32을 더해서 대문자를 소문자로 치환함
		}
	}
	return result;
}
class SongNode
{
private:
	string Song;
	SongNode* nextSong;
public:
	SongNode(string name) {
		Song = name;
		nextSong = nullptr;
	}
	string getSong() {
		return Song;
	}
	SongNode* getNextSong() {
		return nextSong;
	}
	void setNext(SongNode* NSong) {
		nextSong = NSong;
	}
};

class ArtistNode
{
private:
	string Artist;
	ArtistNode* nextArt;
	SongNode* headSong;

public:
	ArtistNode(string name) {
		Artist = name;
		nextArt = nullptr;
		headSong = nullptr;
	}
	void AddSong(string title) {
		SongNode* addsong = new SongNode(title);
		if (headSong == nullptr) {    //SongNode가 비어있을 때 가장 처음 노드를 추가하는 경우
			headSong = addsong;
		}
		else if (headSong != nullptr && title < headSong->getSong()) {  // 곡이 알파벳 순서대로 가장 처음 삽입될 경우
			addsong->setNext(headSong);
			headSong = addsong;
		}
		else if (headSong != nullptr && title > headSong->getSong()) {  // 곡이 알파벳 순서대로 중간에 삽입될 경우
			SongNode* temp = headSong;
			SongNode* work = temp->getNextSong();
			while (work != nullptr && title > temp->getSong()) { 
				if (title < work->getSong()) {
					temp->setNext(addsong);
					addsong->setNext(work);
					break;
				}
				temp = temp->getNextSong();
				work = work->getNextSong();
			}
			if (work == nullptr) {   // 곡 이름이 가장 큰 알파벳일 경우 
				temp->setNext(addsong);
			}
		}
	}
	void printSong() {    // 저장된 Song들을 출력하는 함수
		SongNode* work;
		work = headSong;
		while (work != nullptr) {
			cout << work->getSong();
			work = work->getNextSong();
			if (work != nullptr)
				cout << ", ";
		}
		cout << endl;
	}
	void deleteSong() {   // 생성된 서브 Song 리스트를 삭제하는 함수
		SongNode* temp = headSong;
		while (temp != nullptr) {
			headSong = headSong->getNextSong();
			delete temp;
			temp = headSong;
		}
	}
	string getArtist() {
		return Artist;
	}
	void setnextArt(ArtistNode* sna) {
		nextArt = sna;
	}
	ArtistNode* getnextArt() {
		return nextArt;
	}
};

class MyMusicManagementList
{
public:
	ArtistNode* Head;
	ArtistNode* Tail;
	MyMusicManagementList() {
		Head = nullptr;
	}
	void AddArtist(string artistName, string songName) {   // Artist노드를 추가하는 함수
		ArtistNode* work;
		if (Head == nullptr) {       // 가장 처음 Artist노드를 추가하는 경우
			ArtistNode* newArtist = new ArtistNode(artistName);
			newArtist->AddSong(songName);
			newArtist->setnextArt(Head);

			Head = newArtist;
			Tail = newArtist;
			return;
		}

		work = Head;
		if (work != nullptr && work->getArtist() == artistName) {  // 중복되는 Artist이름의 노드가 이미 존재할 경우 Song을 추가함
			work->AddSong(songName);
			return;
		}
		work = work->getnextArt();
		while (work != nullptr && work != Head) {   // 같은 아티스트가 있으면 새로 추가하지 않고 노래를 묶어서 저장
			if (work->getArtist() == artistName) {
				work->AddSong(songName);
				return;
			}
			work = work->getnextArt();
		}

		ArtistNode* newArtist = new ArtistNode(artistName);   // 새로운 Artist노드를 생성하여 원형 연결리스트에 추가하는 경우
		newArtist->AddSong(songName);
		newArtist->setnextArt(Head);

		Tail->setnextArt(newArtist); // Tail이 새로운 아티스트 노드를 가리키게 함
		Tail = newArtist;       
    }
    void printList() {    // 원형 연결 리스트에 저장된 가수와 곡의 정보를 출력하는 함수
        ArtistNode* work = Head;

		cout << "가수: " << work->getArtist() << " ---> " << "노래 제목: ";
		work->printSong();
		work = work->getnextArt();

        while (work != Head) {
			cout << "가수: " << work->getArtist() << " ---> " << "노래 제목: ";
			work->printSong();
			work = work->getnextArt();
        }
		cout << endl << "MyMusicManagementList 출력완료" << endl;

		/*
		work = work->getnextArt();    // 리스트가 원형으로 연결되어 있는지 확인하는 코드 마지막 노드에서 한번 더 다음 노드로 이동
		cout << "가수: " << work->getArtist() << " ---> " << "노래 제목: ";
		work->printSong();
		*/
    }
	void readtextfile(string filename) {   // Artist와 Song이 저장된 텍스트 파일을 읽어 원형 연결 리스트를 생성하는 함수
		ifstream file(filename);
		if (!file.is_open()) {
			cout << "파일 열기 실패" << endl;
			return;
		}
		string artsong;
		getline(file, artsong);    //  일단 한번 읽어 들여와서 가장 위 줄인 Artist와 Song 목록을 건너뛰고 그 다음줄 부터 노드에 저장
		while (getline(file, artsong)) {
			size_t a = artsong.find('\t');  // 탭문자가 나오는 위치
			size_t b = artsong.find('/');   // 슬래쉬문자가 나오는 위치

			string artist = artsong.substr(0, a);
			string song = artsong.substr(b + 2);  // 슬래쉬 다음 탭문자가 한번 더 있기 때문에 /문자의 위치에서 2만큼 더 이동하여 문자열 끝까지 추출
			song = toLower(song);

			AddArtist(artist, song);		
		}

		file.close();
	}
	void deletelist() {    // 만들어진 원형 리스트와 서브 Song노드에 할당된 메모리를 삭제함
		ArtistNode* temp = Head;
		while (temp != Tail) {
			Head = Head->getnextArt();
			temp->deleteSong();
			delete temp;
			temp = Head;
		}
		temp->deleteSong();
		delete temp;
	}
};

int main()
{
	string Musicfile = "Music_Info.txt";   // Music_Info.txt   // Test case NO.2 file:  listtest.txt
	MyMusicManagementList circuit;   // 클래스 객체 생성

	circuit.readtextfile(Musicfile);   // 노드 생성
	circuit.printList();    // 리스트 출력

	return 0;
}