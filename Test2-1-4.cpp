#include <iostream>
#include <fstream>

using namespace std;

class Decoding   //Decoding클래스를 선언하고 정의함
{
private:          //파일이름이 변경 되는걸 막기 위해 멤버 변수 선언
	const char* binary;
	const char* alphabet;

public:
	Decoding(const char* binfile, const char* alpfile)
		: binary(binfile), alphabet(alpfile) {}     //생성자로써 이진 파일과 알파벳 파일의 이름을 인자로 받음

	void alpDecode()  //binary에 저장된 값을 알파벳으로 변환하는 함수
	{
		ifstream infile(binary);  //값을 받아올 binary파일 열기
		if (!infile)
		{
			cout << "Failed to open binary.txt" << endl;
			return;
		}

		ofstream outfile(alphabet);  //변환한 알파벳을 출력할 파일인 alphabet파일 열기
		if (!outfile)
		{
			cout << "Failed to open alphabet.txt" << endl;
			return;
		}

		int count = 0;
		char ap;      //binary파일에서 읽어들인 문자를 저장할 변수
		const char* alpha = "abcdefghijklmnopqrstuvwxyz"; 

		while (infile.get(ap))  //파일에서 한 문자씩 읽어오며 파일의 끝에 도달할 경우 edf을 반환하여 while문을 빠져나감
		{
			if (ap == '0')  
			{
				count++;
			}

			if (count == 25)  //z는 1이아닌 0으로만 표현된 코드이기 때문에 0의 개수가 25개이면 z이다
			{
				outfile << alpha[count];
				count == 0;
			}

			else if (ap == '1')
			{
				outfile << alpha[count];  //0의 개수에 따라 알파벳을 저장함
				count = 0;
			}

		}

		infile.close();    //파일 입출력 객체들을 닫아줌
		outfile.close();
	}

};

int main()
{
	Decoding stp("binary.txt", "alphabet.txt");  //Decoding 객체 생성
	stp.alpDecode();   //멤버 함수 호출

	return 0;
}