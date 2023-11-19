#include "Header.h"
string open_brackets = "([{<";
string close_brackets = ")]}>";

void task1(string in,int len) {
	cout << "Task1" << endl;
	// ќбработать строку:
	// in : carpet
	// out: ractep
	Stack<char> out1;
	Stack<char> out2;
	
	for (int i = 0; i < len/2; i++) {
		out1.Push(in[i]);

	}
	cout << out1;
	for (int j = len / 2; j < len; j++) {
		out2.Push(in[j]);
	}
	cout << out2<<endl;
	
}
void task2(string st, int len) {
	cout << "Task2" << endl;
	// ¬ернуть количество зданий, которые увидит человек,
	// если задан вектор условных высот этих зданий, сто€щих в р€д перед смотр€щим человеком
	int maxx = (int)st[0];
	int count = 1;
	Stack<char>s;
	s.Push((int)st[0]);
	for (int i = 1; i < len; i++) {
		int chislo = (int)st[i];
		if (chislo > maxx) {
			count++;
			maxx = chislo;
		}
	}
	cout << count<<endl;
}
void task3(int n) {
	cout << "Task3" << endl;
	// ¬ывести все натуральные делители числа в приведенном формате:
	// in:  100
	// out: 1 | 100 | 2 | 50 | 4 | 25 | 5 | 20 | 10 | 10
	Stack<int> s;
	int nRoot = std::sqrt(n);
	while (nRoot > 0) {
		if (n % nRoot == 0) {
			s.Push(nRoot);
			s.Push(n / nRoot);
		}
		nRoot--;
	}
	cout << s<< endl;

}

void task4(string s) {
	cout << "Task4" << endl;
	// ѕроверить на корректность переданную строку, состо€щую из скобок.
	// ≈сли есть ошибка - false;
	// если все верно - true + количество пар скобок в последовательности

	int counter = 0;
	Stack<char> st;
	for (char sym : s) {
		if (open_brackets.find(sym) != string::npos)
		{
			st.Push(sym);
		}
		else {
			int ind = close_brackets.find(sym);
			if (ind == string::npos) 
				throw invalid_argument("error");
			else {
				if ((st.isEmpty()) || (st.top() != open_brackets[ind])) { 
					cout << "false";
					return; 
				}
				else {
					st.Pop();
					counter++;
				}
			}
		}
	}
	if (st.Size() == 0)
	{
		cout << "true (" << counter << " pairs" << ")";
	}
		
	else
	{
		cout << "false";
	}
}

int main() {
	task1("carpet", 6);
	task2("152", 3);
	task3(100);
	task4("({[]})({}");
}
