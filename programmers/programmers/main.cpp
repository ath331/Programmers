//소수 찾기 https://programmers.co.kr/learn/courses/30/lessons/42839

#include <string>
#include <cmath>

using namespace std;

bool Visit[10000000];
bool Select[10];
int Answer;

bool IsSosu(int num)
{
	if (num == 0 || num == 1)
		return false;

	for (int i = 2; i < sqrt(num); i++) //최대값을 루트로 판별? 참조 https://yabmoons.tistory.com/336
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

void DFS(int Cnt, string S, string Res)
{
    if (Res != "" && Visit[stoi(Res)] == false)
    {
        int Num = stoi(Res);
        Visit[Num] = true;
        if (IsSosu(Num) == true)
            Answer++;
    }

    for (int i = 0; i < S.length(); i++)
    {
        if (Select[i] == true) 
            continue;

        Select[i] = true;
        DFS(Cnt + 1, S, Res + S[i]);
        Select[i] = false;
    }
}

int solution(string numbers) {
    DFS(0, numbers, "");

	return Answer;
}

int main()
{
	solution("17");

	return 0;
}