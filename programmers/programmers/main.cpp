#include <iostream>
#include <string>
using namespace std;

int main()
{

	while (true)
	{
		int temp = 0;
		cout << "1 : 이진 -> 그레이 2 : 그레이 -> 이진" << endl;
		cin >> temp;
		int i;
		int input[4], cont[4];

		cout << "수  입력 : ";
		for (int i = 0; i < 4; i++)
			cin >> input[i];

		cont[0] = input[0];
		for (i = 0; i < 3; i++)
		{
			switch (temp)
			{
			case 1:
				if (input[i] == input[i + 1])
					cont[i + 1] = 0;
				else
					cont[i + 1] = 1;
				break;

			case 2:
				if (input[i + 1] == cont[i])
					cont[i + 1] = 0;
				else
					cont[i + 1] = 1;
				break;
			default:
				break;
			}
		}

		cout << "변환코드 : ";
		for (int i = 0; i < 4; i++)
			printf("%d ", cont[i]);
		cout << endl;
	}
}