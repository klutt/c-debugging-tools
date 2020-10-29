#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

#define fmt(X) _Generic((X), \
			int: "%d",		\
			double: "%f",	\
			char*: "%s",	\
			char: "%c")



#define f(X) _Generic((X), \
		      int: "%d",		\
		      char* : "%s")


#define p(X) do { char tmp

#define fmt_length (3)
#define ident_length (31)

#define dprint(X) do { char f[fmt_length+ident_length+1] = #X ": "; strcat(f, fmt(X)); printf(f, X); } while(0)
#define dprintln(X) do { dprint(X); puts(""); } while(0)

size_t count_nonprint(const char *str) {
    size_t ret=0;
    for(; *str; str++) 
	if(!isprint(*str)) ret++;
    return ret;
}

#define dprintarr(X, N) do { for(size_t i=0; i<N; i++) dprint(X[i]); } while(0)
//void dprinthex(void *arr, size_t num, size_t

void dprintstrdata(const char *str) {
    printf("Length: %zu\tNon-printables: %zu\n", strlen(str), count_nonprint(str));
    printf("ASCII:\n%s\n", str);
}

#define dprintstr(X) do { printf(" " #X ":"); dprintstrdata(X); } while(0)

int main(void)
{
    int x = 42;
    double y = 360;
    char *s = "Hello";

//    puts(p(s));
//    printf("x:" specifier(x), x);
//    printf("x: " specifier(x), x);
    dprintln(x);
//    dprintln(y);
//    dprintln(s);
    dprintstr(s);
    dprintarr(s, strlen(s));
//    printf("%s\n", specifier(x));
}


    
