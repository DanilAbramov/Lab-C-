#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//Цикл
bool isPolindromFor(string word)
{
	string backWord;
	int index = 0;

	for (int i = word.size() - 1; i >= 0; i--)
	{
		backWord += word[i];
	}
	
	return (word == backWord);
	
}
//Встроенные функции
bool isPolindromFunc(string word)
{
	string backWord = word;
	reverse(word.begin(), word.end());

	if (word == backWord)
	{
		return true;
	}
	return false;
}

bool IsLargeStrings(const vector<string>& words)
{
	for (auto str : words)
	{
		if (str.size() > 100)
		{
			return true;
		}
	}
	return false;
}

vector<string> isPolindromFilter(const vector<string>& words, int length)
{
	vector<string> result;
	if (words.size() < 100 && !IsLargeStrings(words)) {
		for (const auto str : words)
		{
			if (isPolindromFunc(str) && str.size() >= length) {
				result.push_back(str);
			}
		}
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	string word;
	cout << "Введите слово\n";
	std::getline(std::cin, word);

	cout << "Строка полиндром (через цикл):" << isPolindromFor(word) << "\n";
	cout << "Строка полиндром (встроенные методы):" << isPolindromFunc(word) << "\n";

	vector<string> result = isPolindromFilter(vector<string>{"abacaba", "aba"}, 2);

	cout << "\nisPolindromFilter results:";

	for (auto str : result)
	{
		cout << str << ", ";
	}
}