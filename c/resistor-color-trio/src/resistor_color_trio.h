#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

#define OHMS 0
#define KILOOHMS 1

typedef enum {
  BLACK, BROWN, RED, ORANGE, YELLOW,
  GREEN, BLUE, VIOLET, GREY, WHITE, COLOR_ERROR
} resistor_band_t;

typedef struct {
 	uint32_t value;
 	uint8_t unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t *band);

#endif
