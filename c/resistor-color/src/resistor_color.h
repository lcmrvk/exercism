#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H


typedef enum {
	BLACK, BROWN, RED, ORANGE, YELLOW,
	GREEN, BLUE, VIOLET, GREY, WHITE, COLOR_ERROR
} resistor_band_t;


resistor_band_t color_code(resistor_band_t color);
const resistor_band_t * colors();

#endif
