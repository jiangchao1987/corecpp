// append.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // for exit()

using namespace std;

const char* file = "guests.txt";

void show(ifstream* fin);
void show(ifstream& fin);

int main()
{
	// show initial contents
	ifstream fin;
	fin.open(file);

	//show(&fin);
	show(fin);

	// add new names
	ofstream fout(file, ios::out | ios::app);
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output.\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter guest names (enter a blank line to quit):\n";
	string name;
	while (getline(cin, name) && name.size() > 0)
	{
		fout << name << endl;
	}
	fout.close();

	// show revised file
	fin.clear();    // not necessary for some compilers
	fin.open(file);
	//show(&fin);
	show(fin);
	cout << "Done.\n";
	 cin.get();
	return 0;
}

void show(ifstream* fin)
{
	char ch;

	if (fin->is_open())
	{
		cout << "Here are the new contents of the "
			<< file << " file:\n";
		while (fin->get(ch))
			cout << ch;
		fin->close();
	}
}

void show(ifstream& fin)
{
	char ch;
	if (fin.is_open())
	{
		cout << "Here are the new contents of the "
			<< file << " file:\n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}
}
