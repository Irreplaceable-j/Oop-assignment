#pragma once

namespace oopstd {

	class string
	{
	public:
		string();
		string(const char* s);
		string(const string& str);
		~string();

		string& assign(const string& str);    //str을 할당하는 함수
		char& at(size_t pos);                 //해당 pos위치에 있는 문자 반환
		const char* c_str() const;            
		void clear();                       //저장된 문자열 지우기
		void push_back(char c);              //
		int compare(const string* str) const;

		string& replace(size_t pose, size_t len, const string& str);
		string substr(size_t pos, size_t len) const;
		size_t find(const string& str, size_t pos) const;

	private:
		char* s;
		size_t len;

	};

	int stoi(const string& str, size_t* idx, int base);
	float stof(const string& str, size_t* idx);

	string to_string(int val);
	string to_string(float val);
}