#include <stdio.h>

int dienso(int a[9][9], int h, int c);
int kiemtrachuoi(int h[], int n, int a);
int tongchuoi(int h[], int n);
int kiemtralap(int a[9][9]);
void nhapmang(int a[9][9]);
void xuatmang(int a[9][9]);
int vitrihop(int a);

int main()
{
    int a[9][9];
//    int a[9][9] =
//    {
//        {1,3,0,4,0,6,5,0,0},
//        {0,6,0,0,5,0,3,8,1},
//        {2,0,7,8,0,1,9,4,0},
//        {0,4,0,0,2,0,0,0,0},
//        {7,0,6,0,8,0,0,5,0},
//        {0,2,0,3,7,9,0,1,4},
//        {0,0,0,9,0,0,1,0,0},
//        {0,0,0,5,6,8,0,2,0},
//        {0,7,0,2,0,3,0,0,9},
//    };
    printf("Nhap mang 9x9 phan tu\n");
    nhapmang(a);
    printf("Doi trong giay lat\n");
    while (kiemtralap(a)) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (a[i][j] == 0) {
                    if (dienso(a, i, j) != 0) {
                        a[i][j] = dienso(a, i, j);
                    }
                }
            }
        }
    }

    xuatmang(a);
    return 0;
}

int dienso(int a[9][9], int h, int c) {
    int hang[9], n = 0;
    for (int i=0; i<9; i++) {
        if (a[h][i] != 0) {
            hang[n] = a[h][i];
            n++; // n la so phan tu trong mang
        }
    }

    int lhang = n;
    for (int i=0; i<9; i++) {
        if (a[i][c] != 0) {
            if (kiemtrachuoi(hang, lhang, a[i][c]) == 0) {
                hang[n] = a[i][c];
                n++;
            }
        }
    }

    int h_box = vitrihop(h);
    int c_box = vitrihop(c);

    lhang = n;
    for (int i=h_box-3; i<h_box; i++) {
        for (int j=c_box-3; j<c_box; j++) {
            if (a[i][j] != 0) {
                if (kiemtrachuoi(hang, lhang, a[i][j]) == 0) {
                    hang[n] = a[i][j];
                    n++;
                }
            }
        }
    }

//    for (int i=0; i<n; i++) {
//        printf("%d\n", hang[i]);
//    }

    if (n != 8) return 0;
    else return (45 - tongchuoi(hang, n));
}

// So sanh so nao chua co trong mang da lay duoc, chua co = 0 (=0 thi minh cho phep them so do vao mang), co roi = 1
int kiemtrachuoi(int h[], int n, int a) {
    int kt = 0;
    for (int i=0; i<n; i++) {
        if (a == h[i]) {
            kt = 1;
            break;
        }
    }
    return kt;
}

int kiemtralap(int a[9][9]) {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (a[i][j] == 0) return 1;
        }
    }
    return 0;
}

int tongchuoi(int h[], int n) {
    int S = 0;
    for (int i = 0; i<n; i++) {
        S = S + h[i];
    }
    return S;
}

int vitrihop(int a) {
    if (a < 3) return 3;
    else if (a < 6) return 6;
    else return 9;
}

void nhapmang(int a[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void xuatmang(int a[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
