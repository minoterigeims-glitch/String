

#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

class String
{
private:
	char* str;
	int size;
	static int count;

public:
	String() : String(80)
	{
		
	}
	String(int size_) {
		size = size_;
		str = new char[size + 1];
		str[0] = '\0';
		count++;
	}
	String(const char* text) {
		const int len = strlen(text);
		size = len;
		str = new char[size + 1];
		strcpy_s(str, size + 1, text);
		count++;
	}
	~String() {
		delete[] str;
		
		
	}
	void Input() {
		char buffer[1024];
		cout << "Введіть текст: ";
		cin.getline(buffer, 1024);
		const int len = strlen(buffer);
		size = len;
		delete[] str;
		str = new char[size + 1];
		strcpy_s(str, size + 1, buffer);

	}
	void Print() const {
		cout << "Текст: " << str << endl;
	}
	static int GetCount() {
		return count;
	}
	
	
	

};
int String::count = 0;





int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	String text1;
	String text2(150);
	String text3("Hello world");

	text1.Input();

	text1.Print();
	text3.Print();

	cout << "Кількість створених об'єктів: "<< String::GetCount() << endl;
    
}


