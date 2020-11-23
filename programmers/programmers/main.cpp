//멀쩡한 사각형 https://programmers.co.kr/learn/courses/30/lessons/62048

using namespace std;

int gcd(int a, int b) //최대 공약수출력 https://twpower.github.io/69-how-to-get-gcd-and-lcm
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long solution(int w, int h) {
	long long total = (long long)w * (long long)h;

	return total - (w + h - gcd(w, h));
}

int main()
{
	solution(8, 12);

	return 0;
}

//풀이 주소 https://taesan94.tistory.com/55