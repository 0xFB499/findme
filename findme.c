#include "stdio.h"
#include "string.h"
#include "errno.h"

// why would you use functions when you have macros!? it's funnier

#define print_bits(x){                   \
	unsigned int i__ = 1 << 31;          \
	while(i__){                          \
		putchar(x & i__ ? '1' : '0');    \
		i__ >>= 1;                       \
	}                                    \
	putchar('\n');                       \
}

#define test(i, x) (x & 0xfffff << i) == 0xfb499 << i

int main(int argc, char *argv[]){

	FILE* f = fopen(argv[1], "r");
	if(!f){
		printf("error: %s\n", strerror(errno));
		return -1;
	}
	int x = 0, b, s = 1, t = 0;
	size_t c = 0;
	while(fread(&b, s, 1, f)){
		//printf("%08x <- %x\n", x, b);
		x |= b;
		c+=s;
		s = 1;

		#define print(off) printf("byte 0x%x: ...%X...\n", c+off, x)
		if(test(12, x) || test(8, x)){
			t++;
			pri(-2);
		}else if(test(4, x) || test(0, x)){
			t++;
			s++;
			print(-3);
			x <<= 8;
		}
		x <<= 8;
		b = 0;
	}
	fclose(f);
	if(t){
		printf("Read 0x%zx bytes:\nFound myself %d times on %s\n", c, t, argv[1]);
	}
	return 0;
}
