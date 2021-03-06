#include <stdio.h>
#include <algorithm>

long double b[11111];
int a[11111];
int n, m, p, tt, k, i, j;

int main() {
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d %d %d", &m, &n, &p);
    for (i=0;i<n;i++) {
      scanf("%d", &a[i]);
      a[i]--;
    }
    std::sort(a, a+n);
    for (i=0;i<n;i++) b[i] = 1.0;
    for (j=1;j<m;j*=2) {
      for (i=0;i<n;i++) a[i] /= 2;
      k = 0;
      for (i=0;i<n;i++)
        if (i == n-1 || a[i] != a[i+1]) {
          a[k] = a[i];
          b[k++] = b[i]*p*0.01;
        } else {
          a[k] = a[i];
          b[k++] = (b[i]*b[i+1]) + (b[i]*(1-b[i+1])*p*0.01) + ((1-b[i])*b[i+1]*p*0.01);
          i++;
        }
      n = k;
    }
    printf("%.13Lf\n",100*b[0]);
  }
  return 0;
}
