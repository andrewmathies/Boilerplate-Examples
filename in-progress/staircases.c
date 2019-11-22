// 1017 Staircases

#include <stdio.h>

void main() {
	int n, i, j, bricks, lastHeight, ans = 0;
	int d[n][n];
	memset(d, 0, sizeof(d));

	// filling out first column of dp table
	for (i = 3; i < n; i++) {
		for (j = 2; j < n; j++) {
			if (i % 2 == 0) {
				d[i][j] = i / 2 - 1;
			} else {
				d[i][j] = i / 2;
			}
		}
	}

	d[6][3] = 1;




	scanf("%d", &n);

	lastHeight = 0;
	bricks = n;

	while (bricks > 0) {
		bricks -= lastHeight;		
	}






	printf("%d\n", ans);
}
