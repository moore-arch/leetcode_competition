bool judgeSquareSum(int c) {
	long left = 0;
	long right = sqrt(c);
	bool res = false;
	while (left <= right) {
		long temp = left*left + right*right;
		if (temp < c) {
			++left;
		} else if (temp > c) {
			--right;
		} else {
			res = true;
			break;
		}
	}
	return res;
}