#ifndef DARTS_H
#define DARTS_H

#define MISS_POINTS 0
#define OUTER_CIRCLE 10
#define OUTER_CIRCLE_POINTS 1
#define MIDDLE_CIRCLE 5
#define MIDDLE_CIRCLE_POINTS 5
#define INNER_CIRCLE 1
#define INNER_CIRCLE_POINTS 10
#define DISTANCE_ERROR -1

typedef struct
{
	double x;
	double y;	
} coordinate_t;

int score(coordinate_t hit);

#ifndef _MATH_H
 #include <math.h>
#endif

#define COORD_DIFF(coordinate_t_1, coordinate_t_2, c) (pow((coordinate_t_1.c) - (coordinate_t_2.c), 2))
#define EUCLIDIAN_DISTANCE(coordinate_t_1, coordinate_t_2) \
			(sqrt( COORD_DIFF(coordinate_t_1, coordinate_t_2, x)  \
				+ COORD_DIFF(coordinate_t_1, coordinate_t_2, y)))

#define VERIFY_COORDS(x, y) (printf( "(" #x "," #y ")"  ": %d\n", score( (coordinate_t) {x, y}) ))


#endif // DARTS_H
