//큰수 만들기 https://programmers.co.kr/learn/courses/30/lessons/42883
/*
k는 number에서 제거할 수의 갯수 이다.
이때 k만큼 제거하고 남은 수에서 큰수를 도출하는 것이 아니라
number의 앞에서 부터 k만큼 제거한 그 자체의 수를 도출 하는 것이다.

근데 number의 앞에서 부터 k갯수만큼 비교해서 그중에서 가자 작은 것만 삭제해도 답이 나온다?!
예시는 맞추는데 테스트 케이스가 3개만 통과한다. 다른 방법 필요.

stack이용?

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

//풀이 참고  https://yabmoons.tistory.com/334