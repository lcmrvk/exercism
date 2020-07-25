#include <stdint.h>
#include "resistor_color_duo.h"

#define COLOR_ARRAY_MAX_SIZE 2

#if COMPILE_NO_EXERCISM_TEST == 1
int main(void)
{
	return 0;
}
#endif // COMPILE_NO_EXERCISM_TEST


static const resistor_band_t color_values[] = {
	BLACK, BROWN, RED, ORANGE, YELLOW,
	GREEN, BLUE, VIOLET, GREY, WHITE, COLOR_ERROR
};


resistor_band_t color_code(const resistor_band_t *color) {

	uint16_t result = 0;

	for (int i = 0; i < COLOR_ARRAY_MAX_SIZE; ++i) {
		result += color_values[color[i]];
		if (i < COLOR_ARRAY_MAX_SIZE - 1)
			result *= 10;
	}

	return result;
}
