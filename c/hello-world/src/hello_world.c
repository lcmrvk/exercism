#include "hello_world.h"

#if COMPILE_NO_EXERCISM_TEST == 1
int main(void)
{
	return 0;
}
#endif // COMPILE_NO_EXERCISM_TEST

const char *hello(void)
{
    return "Hello, World!";
}
