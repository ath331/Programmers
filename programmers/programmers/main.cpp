#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//A = 65 Z = 90 N = 78 N���� ū ���̸� A���� ���� �̵��ϴ°� ������

int CountUpDown(char s) //s���� �̵��ϴ� Ƚ��
{
	int count = 0;

	if (s == 'A')
		return 0;

	else if (s <= 'N')
		return s - 'A';

	else if (s > 'N')
		return 13 - ((s - 'A') - 13);

	return 0;
}

int solution(string name) {
	int answer = 0;

	vector<bool> v;
	for (auto c : name)
	{
		if (c != 'A')
			v.push_back(false);
		else
			v.push_back(true);
	}

	int pos = 0;
	while ((count(v.begin(), v.end(), true)) != name.size()) //v�� ��� �κ��� Ž���� �� ����
	{
		int leftSearchDis = 0; //�������� Ž�������� ���� ����� �ε��������� �Ÿ�
		int rightSearchDis = 0; //���������� Ž�������� ���� ����� �ε��������� �Ÿ�

		for (int i = pos;; i++)
		{
			if (i >= v.size())
				i = 0;

			if (v[i] == false)
				rightSearchDis = i - pos;
		}

		for (int i = pos;; i--)
		{
			if (i < 0)
				i = v.size() - 1;

			if (v[i] == false)
				leftSearchDis = i - pos;
		}

		if (leftSearchDis < rightSearchDis)
		{
			for (int i = 0; i < leftSearchDis; i++)
			{
				pos--;
				if (pos < 0)
					i = v.size() - 1;
			}

			answer += leftSearchDis;
			v[pos] = true;
		}
		else
		{
			for (int i = 0; i < rightSearchDis; i++)
			{
				pos++;
				if (i >= v.size())
					i = 0;
			}

			answer += rightSearchDis;
			v[pos] = true;
		}
	}

	return answer;
}

int main()
{
	solution("AB");

	return 0;
}