#include <stdio.h>
#include <stdlib.h>

long int* lookup;

long int pattern(int n) {
  if (n==0) return 1;
  else if (n < 0) return 0;
  else if (lookup[n] != 0) return lookup[n]; 
  else {
    lookup[n] = pattern(n-1) + pattern(n-2);
    return lookup[n];
  }
}

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
        lookup = (long int*) malloc((n+1) * sizeof(long int));
        int i;
        for (i=0; i <=n; i++) lookup[i] = 0;
	printf("%ld\n", pattern(n));
//        for (i=0; i <=n;i++) printf("%ld\n", lookup[i]);
	return 0;
}
