#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

string toLower(string str) {  // ���ڿ� �߿� �빮�ڰ� �������� �� �ҹ��ڷ� ��ȯ�����ִ� �Լ�
	string result = str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {    // �빮�ڰ� ������ �ҹ��ڷ� ������
			result[i] = str[i] + 32;      // �빮�ڿ� �ҹ����� �ƽ�Ű �ڵ尪 ������ 32�� ���ؼ� �빮�ڸ� �ҹ��ڷ� ġȯ��
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
		if (headSong == nullptr) {    //SongNode�� ������� �� ���� ó�� ��带 �߰��ϴ� ���
			headSong = addsong;
		}
		else if (headSong != nullptr && title < headSong->getSong()) {  // ���� ���ĺ� ������� ���� ó�� ���Ե� ���
			addsong->setNext(headSong);
			headSong = addsong;
		}
		else if (headSong != nullptr && title > headSong->getSong()) {  // ���� ���ĺ� ������� �߰��� ���Ե� ���
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
			if (work == nullptr) {   // �� �̸��� ���� ū ���ĺ��� ��� 
				temp->setNext(addsong);
			}
		}
	}
	void printSong() {    // ����� Song���� ����ϴ� �Լ�
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
	void deleteSong() {   // ������ ���� Song ����Ʈ�� �����ϴ� �Լ�
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
	void AddArtist(string artistName, string songName) {   // Artist��带 �߰��ϴ� �Լ�
		ArtistNode* work;
		if (Head == nullptr) {       // ���� ó�� Artist��带 �߰��ϴ� ���
			ArtistNode* newArtist = new ArtistNode(artistName);
			newArtist->AddSong(songName);
			newArtist->setnextArt(Head);

			Head = newArtist;
			Tail = newArtist;
			return;
		}

		work = Head;
		if (work != nullptr && work->getArtist() == artistName) {  // �ߺ��Ǵ� Artist�̸��� ��尡 �̹� ������ ��� Song�� �߰���
			work->AddSong(songName);
			return;
		}
		work = work->getnextArt();
		while (work != nullptr && work != Head) {   // ���� ��Ƽ��Ʈ�� ������ ���� �߰����� �ʰ� �뷡�� ��� ����
			if (work->getArtist() == artistName) {
				work->AddSong(songName);
				return;
			}
			work = work->getnextArt();
		}

		ArtistNode* newArtist = new ArtistNode(artistName);   // ���ο� Artist��带 �����Ͽ� ���� ���Ḯ��Ʈ�� �߰��ϴ� ���
		newArtist->AddSong(songName);
		newArtist->setnextArt(Head);

		Tail->setnextArt(newArtist); // Tail�� ���ο� ��Ƽ��Ʈ ��带 ����Ű�� ��
		Tail = newArtist;       
    }
    void printList() {    // ���� ���� ����Ʈ�� ����� ������ ���� ������ ����ϴ� �Լ�
        ArtistNode* work = Head;

		cout << "����: " << work->getArtist() << " ---> " << "�뷡 ����: ";
		work->printSong();
		work = work->getnextArt();

        while (work != Head) {
			cout << "����: " << work->getArtist() << " ---> " << "�뷡 ����: ";
			work->printSong();
			work = work->getnextArt();
        }
		cout << endl << "MyMusicManagementList ��¿Ϸ�" << endl;

		/*
		work = work->getnextArt();    // ����Ʈ�� �������� ����Ǿ� �ִ��� Ȯ���ϴ� �ڵ� ������ ��忡�� �ѹ� �� ���� ���� �̵�
		cout << "����: " << work->getArtist() << " ---> " << "�뷡 ����: ";
		work->printSong();
		*/
    }
	void readtextfile(string filename) {   // Artist�� Song�� ����� �ؽ�Ʈ ������ �о� ���� ���� ����Ʈ�� �����ϴ� �Լ�
		ifstream file(filename);
		if (!file.is_open()) {
			cout << "���� ���� ����" << endl;
			return;
		}
		string artsong;
		getline(file, artsong);    //  �ϴ� �ѹ� �о� �鿩�ͼ� ���� �� ���� Artist�� Song ����� �ǳʶٰ� �� ������ ���� ��忡 ����
		while (getline(file, artsong)) {
			size_t a = artsong.find('\t');  // �ǹ��ڰ� ������ ��ġ
			size_t b = artsong.find('/');   // ���������ڰ� ������ ��ġ

			string artist = artsong.substr(0, a);
			string song = artsong.substr(b + 2);  // ������ ���� �ǹ��ڰ� �ѹ� �� �ֱ� ������ /������ ��ġ���� 2��ŭ �� �̵��Ͽ� ���ڿ� ������ ����
			song = toLower(song);

			AddArtist(artist, song);		
		}

		file.close();
	}
	void deletelist() {    // ������� ���� ����Ʈ�� ���� Song��忡 �Ҵ�� �޸𸮸� ������
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
	MyMusicManagementList circuit;   // Ŭ���� ��ü ����

	circuit.readtextfile(Musicfile);   // ��� ����
	circuit.printList();    // ����Ʈ ���

	return 0;
}