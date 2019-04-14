#include <stdio.h>
#include <stdlib.h>

int main() {
	int b[] = {2, 4, 2, 8};
	int *p, *q, *r;

	p = &b[0];
	q = &b[1];
	r = &b[2];

	printf("%d, %d, %d, %d\n", *p, b[1], b[2], b[3]);

	int a2 = (p < q < r);
	printf("%s: %d\n", "p < q < r", a2);

	int b2 = (p != r && *p == *r);
	printf("%s: %d\n", "p != r && *p == *r", b2);

	int c2 = (q-b == &b[3] - &p[1]);
	printf("%s: %d\n", "q-b == &b[3] - &p[1]", c2);

	int d2 = (p[1] == r[-1]);
	printf("%s: %d\n", "p[1] == r[-1]", d2);

	int e2 = (&r[-2] == &b[0]);
	printf("%s: %d\n", "&r[-2] == &b[0]", e2);

	int f2 = (q-p+q-p == q+q-p-p);
	printf("%s: %d\n", "q-p+q-p == q+q-p-p", f2);

	return 0;
}