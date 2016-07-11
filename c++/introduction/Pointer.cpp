#include <cstdio>
#include <cstdlib>

void update(int *a, int *b) {
	int tmp = *a;
	*a = (*a) + (*b);
	*b = abs((*b) - tmp);
}

int main() {
	int a, b;
	int *pa = &a, *pb = &b;

	scanf("%d %d", &a, &b);
	update(pa, pb);
	printf("%d\n%d", a, b);

	return 0;
}
