//īī�������� �÷����� https://programmers.co.kr/learn/courses/30/lessons/1829

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int BFS(const vector<vector<int>>& v, vector<vector<bool>>& b, int startX, int startY)
{
	struct pos
	{
		int x = 0;
		int y = 0;
	};

	int index = v[startY][startX];
	int maxSizeOfOneArea = 0;

	queue<pos> q;
	if (b[startY][startX] == false)
	{
		b[startY][startX] = true;
		q.push(pos{ startX, startY });
		maxSizeOfOneArea++;
	}

	while (q.empty() == false)
	{
		pos p = q.front();
		q.pop();
		int x = p.x;
		int y = p.y;

		if (x - 1 >= 0 && b[y][x - 1] == false && v[y][x - 1] == index) //���� Ž��
		{
			b[y][x - 1] = true;
			q.push(pos{ x - 1, y });
			maxSizeOfOneArea++;
		}

		if (x + 1 < v[y].size() && b[y][x + 1] == false && v[y][x + 1] == index) //������ Ž��
		{
			b[y][x + 1] = true;
			q.push(pos{ x + 1, y });
			maxSizeOfOneArea++;
		}

		if (y - 1 >= 0 && b[y - 1][x] == false && v[y - 1][x] == index) //���� Ž��
		{
			b[y - 1][x] = true;
			q.push(pos{ x, y - 1 });
			maxSizeOfOneArea++;
		}

		if (y + 1 < v.size() && b[y + 1][x] == false && v[y + 1][x] == index) //�Ʒ��� Ž��
		{
			b[y + 1][x] = true;
			q.push(pos{ x, y + 1 });
			maxSizeOfOneArea++;
		}
	}

	return maxSizeOfOneArea;
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	vector<vector<bool>> b(picture.size(), vector<bool>(picture.size(), false));

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	for (int y = 0; y < picture.size(); y++)
	{
		for (int x = 0; x < picture[y].size(); x++)
		{
			if (picture[y][x] != 0 && b[y][x] == false)
			{
				answer[0]++;
				answer[1] = max(answer[1], BFS(picture, b, x, y));
			}
		}
	}


	return answer;
}

int main()
{
	vector<vector<int>> a
		= { {1, 1, 1, 0  },
			{1, 2, 2, 0  },
			{ 1, 0, 0, 1 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 0, 3 },
			{ 0, 0, 0, 3 } };

	solution(6, 4, a);

	return 0;
}