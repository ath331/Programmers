#include <iostream>
#include <string>
using namespace std;

int main()
{

	while (true)
	{
		int temp = 0;
		cout << "1 : ���� -> �׷��� 2 : �׷��� -> ����" << endl;
		cin >> temp;
		int i;
		int input[4], cont[4];

		cout << "��  �Է� : ";
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

		cout << "��ȯ�ڵ� : ";
		for (int i = 0; i < 4; i++)
			printf("%d ", cont[i]);
		cout << endl;
	}
}