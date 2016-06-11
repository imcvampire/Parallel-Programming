#include "iostream"
#include "fstream"
#include "algorithm"
#include "windows.h"
#include "vector"
using namespace std;

char filename[20][3] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20" };

void file(int pos)
{
	vector<int> v(10000000);

	for (int i = 0; i < 10000000; ++i)
	{
		v[i] = rand();
	}

	sort(v.begin(), v.end());

	fstream file;
	file.open(filename[pos], fstream::out);

	for (int i = 0; i < 10000000; ++i)
	{
		file << v[i] << endl;
	}

	file.close();
}

int main(int argc, char const *argv[])
{
	int i = 0;
	while (i < 20)
	{
		DWORD   dwThreadIdArray[2];
		HANDLE  hThreadArray[2];

		hThreadArray[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) file, (int *) i, 0, &dwThreadIdArray[0]);
		i += 1;

		hThreadArray[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) file, (int *) i, 0, &dwThreadIdArray[1]);
		i += 1;

		WaitForMultipleObjects(2, hThreadArray, TRUE, INFINITE);
	}


	return 0;
}