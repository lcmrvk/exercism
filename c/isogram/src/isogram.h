#ifndef ISOGRAM_H
#define ISOGRAM_H

#include <stdbool.h>

#define ALPHABET_SIZE 26
#define ALPHABET_POSOTION(c) (tolower(c) - 'a')

bool is_isogram(const char *phrase);

#endif // ISOGRAM_H
