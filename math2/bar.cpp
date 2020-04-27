
int add(int st, int sond) {
	return st + sond;
}
int pwr(int no, char pwr) {
	int res = 1;
	for (char i = 0; i < pwr; i++)
	{
		res *= no;
	}
	return res;
}
