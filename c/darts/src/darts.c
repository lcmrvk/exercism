#include <stdio.h>
#include "darts.h"

#define COMPILE_NO_EXERCISM_TEST 0
#define DEBUG 0

#if COMPILE_NO_EXERCISM_TEST == 1
int main(void)
{

	VERIFY_COORDS(9, 9);
	VERIFY_COORDS(0, 10);
	VERIFY_COORDS(-5, 0);
	VERIFY_COORDS(0, -1);
	VERIFY_COORDS(0, 0);
	VERIFY_COORDS(-0.1, -0.1);
	VERIFY_COORDS(0.7, 0.7);
	VERIFY_COORDS(0.8, -0.8);
	VERIFY_COORDS(-3.5, 3.5);
	VERIFY_COORDS(-3.6, -3.6);
	VERIFY_COORDS(-7.0, 7.0);
	VERIFY_COORDS(7.1, -7.1);
	VERIFY_COORDS(-0.5, -4.0);

	return 0;
}
#endif // COMPILE_NO_EXERCISM_TEST

int
score(coordinate_t hit)
{
	coordinate_t origin = {0, 0};
	double distance = EUCLIDIAN_DISTANCE(origin, hit);

	#if DEBUG == 1
		printf("distance is: %f | ", distance);
	#endif // DEBUG

	if (distance > OUTER_CIRCLE) {
		return MISS_POINTS;
	}
	else if (distance > MIDDLE_CIRCLE) {
		return OUTER_CIRCLE_POINTS;
	}
	else if (distance > INNER_CIRCLE) {
		return MIDDLE_CIRCLE_POINTS;
	}
	else {
		return INNER_CIRCLE_POINTS;
	}

	return DISTANCE_ERROR;

}