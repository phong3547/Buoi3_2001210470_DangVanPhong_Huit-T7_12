#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Hàm tạo ma trận vuông ngẫu nhiên
void taoMaTran(int a[MAX][MAX], int n, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = min + rand() % (max - min + 1);
        }
    }
}

// Hàm xuất ma trận
void xuatMaTran(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm xuất các phần tử trên đường chéo chính
void xuatDuongCheoChinh(int a[MAX][MAX], int n) {
    printf("Cac phan tu tren duong cheo chinh: ");
    for (int i = 0; i < n; i++) {
        printf("%4d", a[i][i]);
    }
    printf("\n");
}

// Hàm xuất các phần tử thuộc các đường chéo song song với đường chéo chính
void xuatDuongCheoSongSong(int a[MAX][MAX], int n) {
    printf("Cac phan tu thuoc duong cheo song song voi duong cheo chinh:\n");
    for (int k = 1; k < n; k++) {
        printf("Duong cheo tren, lech %d: ", k);
        for (int i = 0; i < n - k; i++) {
            printf("%4d", a[i][i + k]);
        }
        printf("\n");
    }
    for (int k = 1; k < n; k++) {
        printf("Duong cheo duoi, lech %d: ", k);
        for (int i = k; i < n; i++) {
            printf("%4d", a[i][i - k]);
        }
        printf("\n");
    }
}

// Hàm tìm phần tử max thuộc tam giác trên của đường chéo chính
int maxTamGiacTrenDuongCheoChinh(int a[MAX][MAX], int n) {
    int max = a[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}

// Hàm sắp xếp ma trận tăng dần theo kiểu zic-zắc
void sapXepZigZag(int a[MAX][MAX], int n) {
    int temp[MAX * MAX];
    int idx = 0;

    // Chuyển ma trận thành mảng tạm thời
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[idx++] = a[i][j];
        }
    }

    // Sắp xếp mảng tạm thời
    for (int i = 0; i < idx - 1; i++) {
        for (int j = i + 1; j < idx; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    // Chuyển mảng tạm thời trở lại ma trận theo kiểu zic-zắc
    idx = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                a[i][j] = temp[idx++];
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                a[i][j] = temp[idx++];
            }
        }
    }
}

// Hàm sắp xếp đường chéo chính tăng dần từ trên xuống dưới
void sapXepDuongCheoChinh(int a[MAX][MAX], int n) {
    int temp[MAX];
    for (int i = 0; i < n; i++) {
        temp[i] = a[i][i];
    }

    // Sắp xếp mảng tạm thời
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    // Gán lại giá trị đã sắp xếp cho đường chéo chính
    for (int i = 0; i < n; i++) {
        a[i][i] = temp[i];
    }
}

void menu() {
    int a[MAX][MAX];
    int n, min, max;
    int choice;

    printf("Nhap cap cua ma tran vuong n (n >= 5): ");
    scanf_s("%d", &n);
    printf("Nhap gia tri nho nhat min: ");
    scanf_s("%d", &min);
    printf("Nhap gia tri lon nhat max: ");
    scanf_s("%d", &max);

    if (n < 5) {
        printf("Cap cua ma tran phai >= 5\n");
        return;
    }

    taoMaTran(a, n, min, max);

    do {
        printf("\nMenu:\n");
        printf("1. Tao/xuat ma tran vuong\n");
        printf("2. Xuat cac phan tu tren duong cheo chinh\n");
        printf("3. Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh\n");
        printf("4. Tim phan tu max thuoc tam giac tren cua duong cheo chinh\n");
        printf("5. Sap xep ma tran tang dan theo kieu zic-zac\n");
        printf("6. Sap xep duong cheo chinh tang dan tu tren xuong duoi\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            taoMaTran(a, n, min, max);
            printf("Ma tran ngau nhien:\n");
            xuatMaTran(a, n);
            break;
        case 2:
            printf("Cac phan tu tren duong cheo chinh:\n");
            xuatDuongCheoChinh(a, n);
            break;
        case 3:
            printf("Cac phan tu thuoc duong cheo song song voi duong cheo chinh:\n");
            xuatDuongCheoSongSong(a, n);
            break;
        case 4: {
            int maxTren = maxTamGiacTrenDuongCheoChinh(a, n);
            printf("Phan tu max thuoc tam giac tren cua duong cheo chinh: %d\n", maxTren);
            break;
        }
        case 5:
            printf("Sap xep ma tran tang dan theo kieu zic-zac:\n");
            sapXepZigZag(a, n);
            xuatMaTran(a, n);
            break;
        case 6:
            printf("Sap xep duong cheo chinh tang dan tu tren xuong duoi:\n");
            sapXepDuongCheoChinh(a, n);
            xuatMaTran(a, n);
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le! Vui long nhap lai.\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
