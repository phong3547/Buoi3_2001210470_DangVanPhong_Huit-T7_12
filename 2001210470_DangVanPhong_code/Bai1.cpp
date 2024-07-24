//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <stdbool.h>
//
//#define MAX 100
//
//// Hàm tạo ma trận ngẫu nhiên
//void taoMaTran(int a[MAX][MAX], int m, int n, int min, int max) {
//    srand(time(NULL));
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            a[i][j] = min + rand() % (max - min + 1);
//        }
//    }
//}
//
//// Hàm xuất ma trận
//void xuatMaTran(int a[MAX][MAX], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("%4d", a[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//// Hàm tính tổng giá trị từng dòng
//void tongGiaTriTungDong(int a[MAX][MAX], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        int tong = 0;
//        for (int j = 0; j < n; j++) {
//            tong += a[i][j];
//        }
//        printf("Tong gia tri dong %d: %d\n", i + 1, tong);
//    }
//}
//
//// Hàm xuất phần tử lớn nhất trên từng cột
//void phanTuLonNhatTrenTungCot(int a[MAX][MAX], int m, int n) {
//    for (int j = 0; j < n; j++) {
//        int max = a[0][j];
//        for (int i = 1; i < m; i++) {
//            if (a[i][j] > max) {
//                max = a[i][j];
//            }
//        }
//        printf("Phan tu lon nhat tren cot %d: %d\n", j + 1, max);
//    }
//}
//
//// Hàm xuất các phần tử thuộc các đường biên
//void xuatPhanTuDuongBien(int a[MAX][MAX], int m, int n) {
//    printf("Phan tu duong bien: ");
//    for (int j = 0; j < n; j++) {
//        printf("%4d", a[0][j]);
//    }
//    for (int i = 1; i < m; i++) {
//        printf("%4d", a[i][n - 1]);
//    }
//    if (m > 1) {
//        for (int j = n - 2; j >= 0; j--) {
//            printf("%4d", a[m - 1][j]);
//        }
//    }
//    if (n > 1) {
//        for (int i = m - 2; i > 0; i--) {
//            printf("%4d", a[i][0]);
//        }
//    }
//    printf("\n");
//}
//
//// Hàm kiểm tra phần tử cực đại
//bool laPhanTuCucDai(int a[MAX][MAX], int i, int j, int m, int n) {
//    int xungQuanh[8][2] = {
//        {-1, -1}, {-1, 0}, {-1, 1},
//        {0, -1},          {0, 1},
//        {1, -1}, {1, 0}, {1, 1}
//    };
//    for (int k = 0; k < 8; k++) {
//        int ni = i + xungQuanh[k][0];
//        int nj = j + xungQuanh[k][1];
//        if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[i][j] <= a[ni][nj]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//// Hàm xuất các phần tử cực đại
//void xuatPhanTuCucDai(int a[MAX][MAX], int m, int n) {
//    printf("Phan tu cuc dai: ");
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (laPhanTuCucDai(a, i, j, m, n)) {
//                printf("%4d", a[i][j]);
//            }
//        }
//    }
//    printf("\n");
//}
//
//// Hàm xuất dòng chỉ chứa số chẵn
//void xuatDongChiChuaSoChan(int a[MAX][MAX], int m, int n) {
//    bool coDongSoChan = false;
//    for (int i = 0; i < m; i++) {
//        bool chiChuaSoChan = true;
//        for (int j = 0; j < n; j++) {
//            if (a[i][j] % 2 != 0) {
//                chiChuaSoChan = false;
//                break;
//            }
//        }
//        if (chiChuaSoChan) {
//            coDongSoChan = true;
//            printf("Dong %d chi chua so chan: ", i + 1);
//            for (int j = 0; j < n; j++) {
//                printf("%4d", a[i][j]);
//            }
//            printf("\n");
//        }
//    }
//    if (!coDongSoChan) {
//        printf("Khong co dong chi chua so chan.\n");
//    }
//}
//
//// Hàm sắp xếp mảng a tăng theo từng dòng
//void sapXepMangTangTheoTungDong(int a[MAX][MAX], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n - 1; j++) {
//            for (int k = j + 1; k < n; k++) {
//                if (a[i][j] > a[i][k]) {
//                    int temp = a[i][j];
//                    a[i][j] = a[i][k];
//                    a[i][k] = temp;
//                }
//            }
//        }
//    }
//}
//
//// Hàm hiển thị menu và xử lý lựa chọn
//void menu() {
//    int a[MAX][MAX];
//    int m, n;
//    int min, max;
//    int choice;
//
//    printf("Nhap so dong m: ");
//    scanf_s("%d", &m);
//    printf("Nhap so cot n: ");
//    scanf_s("%d", &n);
//    printf("Nhap gia tri nho nhat min: ");
//    scanf_s("%d", &min);
//    printf("Nhap gia tri lon nhat max: ");
//    scanf_s("%d", &max);
//
//    taoMaTran(a, m, n, min, max);
//
//    do {
//        printf("\nMenu:\n");
//        printf("1. Tao va xuat ma tran\n");
//        printf("2. Tinh va xuat tong gia tri tung dong\n");
//        printf("3. Xuat phan tu lon nhat tren tung cot\n");
//        printf("4. Xuat cac phan tu duong bien\n");
//        printf("5. Xuat cac phan tu cuc dai\n");
//        printf("6. Xuat dong chi chua so chan\n");
//        printf("7. Sap xep mang tang theo tung dong\n");
//        printf("8. Thoat\n");
//        printf("Chon chuc nang: ");
//        scanf_s("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            printf("Ma tran ngau nhien:\n");
//            xuatMaTran(a, m, n);
//            break;
//        case 2:
//            printf("Tong gia tri tung dong:\n");
//            tongGiaTriTungDong(a, m, n);
//            break;
//        case 3:
//            printf("Phan tu lon nhat tren tung cot:\n");
//            phanTuLonNhatTrenTungCot(a, m, n);
//            break;
//        case 4:
//            printf("Phan tu duong bien:\n");
//            xuatPhanTuDuongBien(a, m, n);
//            break;
//        case 5:
//            printf("Phan tu cuc dai:\n");
//            xuatPhanTuCucDai(a, m, n);
//            break;
//        case 6:
//            printf("Dong chi chua so chan:\n");
//            xuatDongChiChuaSoChan(a, m, n);
//            break;
//        case 7:
//            printf("Sap xep mang tang theo tung dong:\n");
//            sapXepMangTangTheoTungDong(a, m, n);
//            xuatMaTran(a, m, n);
//            break;
//        case 8:
//            printf("Thoat chuong trinh.\n");
//            break;
//        default:
//            printf("Lua chon khong hop le. Vui long chon lai.\n");
//        }
//    } while (choice != 8);
//}
//
//int main() {
//    menu();
//    return 0;
//}
