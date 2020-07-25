#include <stdint.h>
#include <math.h>

#include "resistor_color_trio.h"


#if COMPILE_NO_EXERCISM_TEST == 1
int main(void)
{
	return 0;
}
#endif // COMPILE_NO_EXERCISM_TEST


resistor_value_t color_code(resistor_band_t *band) {

	resistor_value_t result;

	result.value = (10 * band[0] + band[1]) * pow(10, band[2]);
	if (result.value < 1000)  {
		result.unit = OHMS;
	} else {
		result.value /= 1000;
		result.unit = KILOOHMS;
	}

	return result;
}