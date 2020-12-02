//ū�� ����� https://programmers.co.kr/learn/courses/30/lessons/42883
/*
k�� number���� ������ ���� ���� �̴�.
�̶� k��ŭ �����ϰ� ���� ������ ū���� �����ϴ� ���� �ƴ϶�
number�� �տ��� ���� k��ŭ ������ �� ��ü�� ���� ���� �ϴ� ���̴�.

�ٵ� number�� �տ��� ���� k������ŭ ���ؼ� ���߿��� ���� ���� �͸� �����ص� ���� ���´�?!
���ô� ���ߴµ� �׽�Ʈ ���̽��� 3���� ����Ѵ�. �ٸ� ��� �ʿ�.

stack�̿�?

*/

#include <string>
#include <stack>

using namespace std;

string solution(string number, int k) {

	int removeCount = 0;
	stack<char> s;
	for (int ni = 0; ni < number.size(); ni++)
	{
		if (s.empty())
			s.push(number[ni]);
		else if (s.top() >= number[ni])
			s.push(number[ni]);
		else
		{
			while (s.empty() == false && removeCount < k)
			{
				if (s.top() < number[ni])
				{
					s.pop();
					removeCount++;
				}
				else
					break;
			}
			s.push(number[ni]);
		}
	}

	for (removeCount; removeCount < k; removeCount++)
	{
		s.pop();
	}

	string answer = "";
	while (s.empty() == false)
	{
		answer.push_back(s.top());
		s.pop();
	}

	string rAnswer = "";
	for (auto rIter = answer.rbegin(); rIter != answer.rend(); rIter++)
	{
		rAnswer += *rIter;
	}

	return rAnswer;
}

int main()
{
	solution("4177252841", 4);

	return 0;
}

//Ǯ�� ����  https://yabmoons.tistory.com/334