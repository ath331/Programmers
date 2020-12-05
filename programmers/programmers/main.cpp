//�� �ʰ� https://programmers.co.kr/learn/courses/30/lessons/42626

//make_heap�����ٰ� �ȵǼ� �켱���� ť�� �ϱ��ߴµ� �� �ȴ���

#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> PQ;
    for (int i = 0; i < scoville.size(); i++) PQ.push(scoville[i]);

    while (PQ.top() < K && PQ.size() > 1)
    {
        int First = PQ.top();
        PQ.pop();

        int Second = PQ.top();
        PQ.pop();

        PQ.push(First + (Second * 2));
        answer++;
    }

    if (PQ.top() < K) return -1;
    return answer;
}

int main()
{
	vector<int> scoville = { 1,2,3,9,10,12};
	solution(scoville, 7);

	return 0;
}

//Ǯ�� ����: https://yabmoons.tistory.com/333 [�幮's Coding World..]