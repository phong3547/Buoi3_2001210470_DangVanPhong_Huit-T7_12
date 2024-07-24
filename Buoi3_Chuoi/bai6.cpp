#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 100
#define MAX_TEXT_LENGTH 1000
#define MAX_PATTERN_LENGTH 100

// Hàm nhập danh sách sinh viên
void inputStudents(char students[][MAX_NAME_LENGTH], int* count) {
    printf("Nhap so luong sinh vien: ");
    scanf_s("%d", count);
    getchar(); // Đọc ký tự newline còn sót lại

    for (int i = 0; i < *count; i++) {
        printf("Nhap ten sinh vien %d: ", i + 1);
        fgets(students[i], MAX_NAME_LENGTH, stdin);
        students[i][strcspn(students[i], "\n")] = '\0'; // Xóa ký tự newline
    }
}

// Hàm hiển thị danh sách sinh viên
void displayStudents(const char students[][MAX_NAME_LENGTH], int count) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < count; i++) {
        printf("Sinh vien %d: %s\n", i + 1, students[i]);
    }
}

// Hàm tìm tất cả các vị trí của chuỗi con P trong chuỗi T
void bruteForceSearch(const char* T, const char* P) {
    int n = strlen(T);
    int m = strlen(P);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (T[i + j] != P[j]) {
                break;
            }
        }
        if (j == m) {
            printf("Chuoi '%s' duoc tim thay tai vi tri %d.\n", P, i);
        }
    }
}

int main() {
    char students[MAX_STUDENTS][MAX_NAME_LENGTH];
    int count;
    char text[MAX_TEXT_LENGTH];
    char pattern[MAX_PATTERN_LENGTH];
    FILE* file;
    FILE* filePointer = NULL;

    // Phần nhập và hiển thị danh sách sinh viên
    inputStudents(students, &count);
    displayStudents(students, count);

    // Nhập chuỗi T từ bàn phím
    printf("\nNhap chuoi T: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Xóa ký tự newline

    // Nhập chuỗi P từ bàn phím
    printf("Nhap chuoi P: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Xóa ký tự newline

    // Tìm kiếm chuỗi P trong chuỗi T từ bàn phím
    printf("\nTim kiem chuoi '%s' trong chuoi '%s':\n", pattern, text);
    bruteForceSearch(text, pattern);

    // Đọc chuỗi T từ file
    if (fopen_s(&filePointer, "textfile.txt", "r") != 0) {
        perror("Loi khi mo file");
        return 1;
    }
    fgets(text, sizeof(text), filePointer);
    fclose(filePointer);

    // Xóa ký tự newline nếu có
    text[strcspn(text, "\n")] = '\0';

    // Nhập chuỗi P từ bàn phím
    printf("Nhap chuoi P: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Xóa ký tự newline

    // Tìm kiếm chuỗi P trong chuỗi T từ file
    printf("\nTim kiem chuoi '%s' trong chuoi '%s':\n", pattern, text);
    bruteForceSearch(text, pattern);

    return 0;
}
