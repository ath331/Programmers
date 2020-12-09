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
	while ((count(v.begin(), v.end(), true)) != name.size()) //v에 모든 부분을 탐색할 때 까지
	{
		int leftSearchDis = 0; //왼쪽으로 탐색했을때 가장 가까운 인덱스까지의 거리
		int rightSearchDis = 0; //오른쪽으로 탐색했을때 가장 가까운 인덱스까지의 거리

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