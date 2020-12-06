#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//A = 65 Z = 90 N = 78 N보다 큰 값이면 A에서 위로 이동하는게 빠르다

int CountUpDown(char s) //s까지 이동하는 횟수
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
	while ((count(v.begin(), v.end(), true)) != name.size()) //v에 모든 부분을 탐색할 때 까지
	{
		if (v[pos] == false)
		{
			answer += CountUpDown(name[pos]);
			v[pos] = true;
		}

		//좌우 탐색
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