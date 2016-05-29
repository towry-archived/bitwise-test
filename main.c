#include <stdio.h>

void test_bitwise();

void 
print_bits(size_t const size, void const * const ptr)
{
	unsigned char *b = (unsigned char*) ptr;
	unsigned char byte;
	int i, j;

	for (i=size-1;i>=0;i--)
	{
		for (j=7;j>=0;j--)
		{
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	printf("\n");
}


void 
test_print_bits() 
{
	int i = 2;
	print_bits(sizeof(i), &i);
}


#ifdef TEST_PRINT 

int 
main(int argc, char *argv[]) 
{
	test_print_bits();
}
#else

int 
main(int argc, char *argv[])
{
	test_bitwise();
}
#endif


void 
test_bitwise() 
{
	printf("exclude two flags:\n");
	printf("255: 11111111\n");
	printf("flag1: 8: 1000\n");
	printf("flag2: 13: 1101\n");

	int all = 255;
	int flag1 = 8;
	int flag2 = 13;

	printf("all: %d, ", all);
	print_bits(sizeof(all), &all);


	int or = flag1 | flag2;
	printf("flag1 | flag2: %d, ", or);
	print_bits(sizeof(or), &or);

	int verse = ~(or);
	printf("~(flag1 | flag2): %d, ", verse);
	print_bits(sizeof(verse), &verse);

	int rval = all & ~(flag1 | flag2);
	printf("result: ");
	print_bits(sizeof(rval), &rval);
	printf("\n");
}
