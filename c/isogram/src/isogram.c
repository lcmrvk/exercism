#include <stddef.h>
#include <ctype.h>
#include "isogram.h"


#if COMPILE_NO_EXERCISM_TEST == 1
int main(void)
{
	return 0;
}
#endif // COMPILE_NO_EXERCISM_TEST

bool
is_isogram(const char *phrase)
{
	int alphabet[ALPHABET_SIZE] = { 0 };

	if (phrase == NULL)
		return false;

	for ( ; *phrase != '\0'; phrase++) {

		if (!isalpha(*phrase))
			continue;

		if (alphabet[ALPHABET_POSOTION(*phrase)] > 0) {
			return false;
		} else {
			alphabet[ALPHABET_POSOTION(*phrase)]++;
		}
	}

	return true;
}