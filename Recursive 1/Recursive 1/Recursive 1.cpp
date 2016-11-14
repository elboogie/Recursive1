// Recursive 1.cpp : Defines the entry point for the console application.
//

// Read numbers from user, then corresponds it to a alphabet and output all 
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>



using std::cin;
using std::cout;


constexpr char _0 = '0';
std::vector<std::vector<char>> values;

void Add_Number(const std::string & s, int branch_index = -1, int step_index = 0)
{
	int b_i = branch_index;
	int index = step_index;

	if (b_i == -1)
	{
		values.push_back(std::vector<char>());
		b_i = 0;
	}
	else
	{
		std::vector<char> v(values[branch_index]);
		char c1 = (s[index - 2] - _0) * 10;
		char c2 = s[index - 1] - _0;
		v.push_back(c1 + c2);
		values.push_back(v);
		b_i = values.size() - 1;
	}



	char ch1{};
	while (index < s.size())
	{
		ch1 = s[index] - _0;
	
		if (index + 1 < s.size() && ((s[index] - _0) *10 + s[index + 1] - _0 <= 'z' - 'a'))
		{
			char ch2 = s[index + 1] - _0;
			if (ch1 + ch2 <= 'z' - 'a')
			{ 
				// create new branch
				Add_Number(s, b_i, index + 2);
			}
		}

		values[b_i].push_back(ch1);
		++index;
	}
}


void Print_Letters()
{
	for (auto x : values)
	{
		for (char y : x)
		{
			char yy = y + 'a';
			cout << yy << " ";
		}
		cout << std::endl;
	}
}



int main()
{
	std::string input;
	std::getline(cin, input);
	
	
	Add_Number(input);

	Print_Letters();

	const int v1{};
	auto& var = v1;

	char ch;
	cin >> ch;
    return 0;
}

