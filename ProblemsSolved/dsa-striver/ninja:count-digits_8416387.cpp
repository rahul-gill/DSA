int countDigits(int n){
	int cnt = 0;
	int i = n;
	while(i > 0) {
		int digit = i % 10;
		if(digit != 0 && n % digit == 0) ++cnt;
		i /= 10;
	}
	return cnt;
}
