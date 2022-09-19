#include <stdio.h>
/* Author: José Rodolfo (jric2002) */
/* Declaration */
int main() {
  short int n;
  short int xi, yi, zi;
  short int xr, yr, zr;
  scanf("%hi", &n);
  xr = yr = zr = 0;
  while (n--) {
    scanf("%hi %hi %hi", &xi, &yi, &zi);
    printf("xi: %hi\tyi: %hi\tzi: %hi\n", xi, yi, zi);
    xr += xi;
    yr += yi;
    zr += zi;
  }
  printf("\n");
  printf("xr: %hi\n", xr);
  printf("yr: %hi\n", yr);
  printf("zr: %hi\n", zr);
  return 0;
}
/* Definition */