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
		values.push_back(v);
		b_i = values.size() - 1;
	}

	

	char ch1{};
	while (index < s.size())
	{
		ch1 = s[index] - '0';
		values[b_i].push_back(ch1);

		if (index + 1 < s.size() && s[index] + s[index + 1] <= 'z')
		{
			// create new branch
			Add_Number(s, b_i, index+2);

		}

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

	char ch;
	cin >> ch;
    return 0;
}

