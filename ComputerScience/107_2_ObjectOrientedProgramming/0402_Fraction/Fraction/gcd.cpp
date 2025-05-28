//Intent: 璸衡ㄢ计程そ计
// Pre: ㄢ俱计
// Post: 肚程そ计
int gcd(int num1, int num2)
{
	if (num1 > 0)
	{
		while ((num2 %= num1) && (num1 %= num2)) {}
	}
	return num1 + num2;
}