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
	int halfSize = (name.size() / 2);
	while ((count(v.begin(), v.end(), true)) != name.size()) //v�� ��� �κ��� Ž���� �� ����
	{
		if (v[pos] == false)
		{
			answer += CountUpDown(name[pos]);
			v[pos] = true;
		}

		//�¿� Ž��
		for (int nextPos = pos; nextPos < name.size(); nextPos++)
		{
			if (v[nextPos] == false)
			{
				int rightDis = nextPos - pos;
				int leftDis = pos + (name.size() - nextPos);

				answer += min(rightDis, leftDis);
				pos = nextPos;
				break;
			}
		}
	}

	return answer;
}

int main()
{
	solution("AB");

	return 0;
}