#include "resistor_color.h"

static const resistor_band_t color_values[] = { 
	BLACK, BROWN, RED, ORANGE, YELLOW,
	GREEN, BLUE, VIOLET, GREY, WHITE, COLOR_ERROR
};

resistor_band_t color_code(resistor_band_t color) {

	if (color >= BLACK && color <= WHITE)
		return color_values[color];

	return COLOR_ERROR;
}

const resistor_band_t * colors() {
	return color_values;
}