#include <math.h>
#include <stdio.h>
#include "armstrong_numbers.h"

#if COMPILE_NO_EXERCISM_TEST == 1
#define VERIFY_ARMSTRONG_N(num) (printf("%d is : %s\n", (num), (is_armstrong_number((num))  ? "false" : "true" )))
int
main(void)
{
	int ok0 = 0;
	int ok1 = 9;
	int ok2 = 153;
	int nok1 = 154;

	VERIFY_ARMSTRONG_N(ok0);
	VERIFY_ARMSTRONG_N(ok1);
	VERIFY_ARMSTRONG_N(ok2);
	VERIFY_ARMSTRONG_N(nok1);

}
#endif // COMPILE_NO_EXERCISM_TEST

int
get_power(int zero_out)
{
	int power = 0;
	while(zero_out) {
		zero_out /= 10;
		power++;
	}

	return power;
}

int
is_armstrong_number(int candidate)
{
	int result = 0;
	int copy = candidate;
	int power = get_power(candidate);

	while(copy) {
		int part = copy % 10;
		result += (int) pow(part, power);
		copy /= 10;
	}

	return (candidate == result) ? 1 : 0;
}
