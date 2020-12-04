#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(string numbers) {
	int answer = 0;

	int maxCount = 1;
	for (int i = 0; i < numbers.size(); i++)
	{
		maxCount *= 2;
	}

	vector<int> v;
	for (int i = 1; i < maxCount; i++)
	{
		string numBit = bitset<7>(i).to_string(); //bit size 고정
		numBit = numBit.substr(numBit.size() - numbers.size()); //bit size 보정

		string temp = "";
		for (int bi = 0; bi < numBit.size(); bi++)
		{
			if (numBit[bi] == '1')
				temp += numbers[bi];
		}

		v.push_back(stoi(temp));
	}

	return answer;
}

int main()
{
	solution("817");

	return 0;
}