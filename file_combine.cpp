#include "iostream"
#include "fstream"
#include "algorithm"
#include "windows.h"
#include "vector"
using namespace std;

char const FileName[21][3] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "temp" };
vector<int> v(500001);

void filemerge(int pos1, int pos2, int pos3)
{
	fstream fs1 (FileName[pos1], fstream::in);
	fstream fs2 (FileName[pos2], fstream::in);
	fstream fsout (FileName[pos3], fstream::out);

	int a1, a2;

	fs1 >> a1;
	fs2 >> a2;

	int check = 0;

	while (1)
	{
		if (a1 < a2)
		{
			fout << a1 << "\n";
			fs1 >> a1;
		}
		else
		{
			fout << a2 << "\n";
			fs2 >> a2;
		}

		if (fs1.eof())
		{
			check = 1;
			break;
		}
		if (fs2.eof())
		{
			check = 2;
			break;
		}
	}

	if (check == 1)
	{
		fout << a2 << "\n";
		while (!fs2.eof())
		{
			fs2 >> a2;
			fout << a2 << "\n";
		}
	}

	if (check == 2)
	{
		fout << a1;
		while (!fs1.eof())
		{
			fs1 >> a1;
			fout << a1 << "\n";
		}
	}

	fs1.close();
	fs2.close();
	fout.close();
}

int main(int argc, char const *argv[])
{

	return 0;
}