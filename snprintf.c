#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	int i;
	char buf[6];
	const char *test_str = "iamthesuperman";

	printf("\n--- init last byte to eol ---\n");
	buf[sizeof(buf)-1] = '\0';
	if( '\0' == buf[(sizeof(buf)-1)] )
		fprintf(stderr, "last byte is eol\n");
	else 
		fprintf(stderr, "last byte is not eol\n");


	printf("\n--- memset buf with 5 ---\n");
	memset(buf, 5, sizeof(buf));
	if( '\0' == buf[(sizeof(buf)-1)] )
		fprintf(stderr, "last byte is eol\n");
	else 
		fprintf(stderr, "last byte is not eol\n");


	printf("\n--- truncate test ---\n");
	printf("snprintf input '%s' (char cnt %d)\n", test_str, strlen(test_str));
	printf("snprintf on buf size '%d'\n", sizeof(buf));
	snprintf(buf, sizeof(buf), test_str);
	if( '\0' == buf[(sizeof(buf)-1)] ) {
		fprintf(stderr, "last byte is eol\n");
		printf("buf: '%s'\n", buf);
	} else 
		fprintf(stderr, "last byte is not eol\n");

	printf("\n");


	i = snprintf(buf, 0, "crazy");
	printf("snprintf on buf size of 0: '%s', i=%d\n", buf, i);
	printf("\n");

	i = snprintf(buf, -1, "crazy");
	printf("snprintf on buf size of -1: '%s', i=%d\n", buf, i);
	printf("\n");

	return 0;
}

