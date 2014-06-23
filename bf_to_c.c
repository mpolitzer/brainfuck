#if 0
gcc -Wall -std=c99 -pedantic -O2 $CFLAGS $LIBS $0 -o ${0%.c}
exit $?
#endif
#include <stdio.h>

char *prefix =
"#include <stdio.h>\n"
"\n"
"char array[1000];\n"
"\n"
"int main(void) {\n"
"char *p = array;\n";

char *postfix =
"return 0;\n"
"}";

int main(int argc, char *argv[])
{
	int ch;

	puts(prefix);
	while ((ch = getchar()) != EOF) {
		switch (ch) {
		case '>': puts("++p;");            break;
		case '<': puts("--p;");            break;
		case '+': puts("++*p;");           break;
		case '-': puts("--*p;");           break;
		case '.': puts("putchar(*p);");    break;
		case ',': puts("*p = getchar();"); break;
		case '[': puts("while (*p) {");    break;
		case ']': puts("}");               break;
		default:                           break;
		}
	}
	puts(postfix);
	return 0;
}
