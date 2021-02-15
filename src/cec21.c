#include <R.h>
#include <stdio.h>
#include <stdlib.h>

void cec21_basic_func(double *x, double *f, int nx, int mx, int func_num);
void cec21_bias_func(double *x, double *f, int nx, int mx, int func_num);
void cec21_bias_rot_func(double *x, double *f, int nx, int mx, int func_num);
void cec21_bias_shift_rot_func(double *x, double *f, int nx, int mx,int func_num);
void cec21_rot_func(double *x, double *f, int nx, int mx, int func_num);
void cec21_shift_func(double *x, double *f, int nx, int mx, int func_num);
void cec21_shift_rot_func(double *x, double *f, int nx, int mx, int func_num);
void cec21_bias_shift_func(double *x, double *f, int nx, int mx,
                             int func_num);

double *OShift, *M, *y, *z, *x_bound;
int ini_flag = 0, n_flag, func_flag, *SS;
char *extdata;

    void
    cec21(char **extdatadir, int *suitenum, int *i, double *X, int *row,
            int *col, double *f) {
  int r, c;
  double *x;

  extdata = *extdatadir;

  x = (double *)malloc(*col * sizeof(double));

  for (r = 0; r < *row; r++) {
    R_CheckUserInterrupt();

    for (c = 0; c < *col; c++) {
      x[c] = X[r + *row * c];
    }
    switch (*suitenum) {
    case 1:
      cec21_basic_func(x, &f[r], *col, 1, *i);
    case 2:
      cec21_bias_func(x, &f[r], *col, 1, *i);
    case 3:
      cec21_bias_rot_func(x, &f[r], *col, 1, *i);
    case 4:
      cec21_bias_shift_rot_func(x, &f[r], *col, 1, *i);
    case 5:
      cec21_rot_func(x, &f[r], *col, 1, *i);
    case 6:
      cec21_shift_func(x, &f[r], *col, 1, *i);
    case 7:
      cec21_shift_rot_func(x, &f[r], *col, 1, *i);
    case 8:
      cec21_bias_shift_func(x, &f[r], *col, 1, *i);
    /*default:*/
      /*printf("what: %d\n", *suitenum);*/
      /*printf("\nError: There are only 8 test suits\n");*/
      /*break;*/
    }
  }

  free(x);
}
