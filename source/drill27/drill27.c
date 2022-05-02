#include <stdio.h>

void f(char* p, int x){
	printf("p is \"%s\" and x is %d.\n", p, x);
}

int main() {
	printf("Hello world!\n");
	
	char s_1[] = "Hello";
	char s_2[] = "World!";
	printf("%s %s\n", s_1, s_2);
	
	f("foo",7);
	f("alma",12);
	f("abc",1);
	
	return 0;
}
