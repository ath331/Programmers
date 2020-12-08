//H - Index https://programmers.co.kr/learn/courses/30/lessons/42747

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end());

	for (int i = 0; i < citations[citations.size() - 1]; i++)
	{
		int num = i;
		if (num < 1)
			continue;

		int underNum = std::count_if(citations.begin(), citations.end(),
			[num](int elem) { return elem >= num; });

		if (underNum >= num)
		{
			int namugi = std::count_if(citations.begin(), citations.end(),
				[num](int elem) { return elem <= num; });
			if (namugi <= num)
			{
				answer = max(answer, num);
			}
		}
	}

	return answer;
}

int main()
{
	vector<int> citations = { 3,0,6,1,5 };
	solution(citations);

	return 0;
}