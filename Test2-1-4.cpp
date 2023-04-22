#include <iostream>
#include <fstream>

using namespace std;

class Decoding   //DecodingŬ������ �����ϰ� ������
{
private:          //�����̸��� ���� �Ǵ°� ���� ���� ��� ���� ����
	const char* binary;
	const char* alphabet;

public:
	Decoding(const char* binfile, const char* alpfile)
		: binary(binfile), alphabet(alpfile) {}     //�����ڷν� ���� ���ϰ� ���ĺ� ������ �̸��� ���ڷ� ����

	void alpDecode()  //binary�� ����� ���� ���ĺ����� ��ȯ�ϴ� �Լ�
	{
		ifstream infile(binary);  //���� �޾ƿ� binary���� ����
		if (!infile)
		{
			cout << "Failed to open binary.txt" << endl;
			return;
		}

		ofstream outfile(alphabet);  //��ȯ�� ���ĺ��� ����� ������ alphabet���� ����
		if (!outfile)
		{
			cout << "Failed to open alphabet.txt" << endl;
			return;
		}

		int count = 0;
		char ap;      //binary���Ͽ��� �о���� ���ڸ� ������ ����
		const char* alpha = "abcdefghijklmnopqrstuvwxyz"; 

		while (infile.get(ap))  //���Ͽ��� �� ���ھ� �о���� ������ ���� ������ ��� edf�� ��ȯ�Ͽ� while���� ��������
		{
			if (ap == '0')  
			{
				count++;
			}

			if (count == 25)  //z�� 1�̾ƴ� 0���θ� ǥ���� �ڵ��̱� ������ 0�� ������ 25���̸� z�̴�
			{
				outfile << alpha[count];
				count == 0;
			}

			else if (ap == '1')
			{
				outfile << alpha[count];  //0�� ������ ���� ���ĺ��� ������
				count = 0;
			}

		}

		infile.close();    //���� ����� ��ü���� �ݾ���
		outfile.close();
	}

};

int main()
{
	Decoding stp("binary.txt", "alphabet.txt");  //Decoding ��ü ����
	stp.alpDecode();   //��� �Լ� ȣ��

	return 0;
}