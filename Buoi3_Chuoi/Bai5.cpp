//#include <stdio.h>
//#include <string.h>
//
//void splitName(const char* fullName, char* lastName, char* firstName) {
//    // Sao chép chuỗi họ tên vào một biến tạm để xử lý
//    char buffer[256];
//    strcpy_s(buffer, sizeof(buffer), fullName);
//
//    // Tìm khoảng trắng cuối cùng để phân tách họ lót và tên
//    char* lastSpace = strrchr(buffer, ' ');
//    if (lastSpace != NULL) {
//        // Cắt phần tên
//        strcpy_s(firstName, sizeof(buffer), lastSpace + 1);
//
//        // Xóa phần tên khỏi chuỗi tạm
//        *lastSpace = '\0';
//
//        // Cắt phần họ lót
//        strcpy_s(lastName, sizeof(buffer), buffer);
//    }
//    else {
//        // Nếu không tìm thấy khoảng trắng, coi toàn bộ chuỗi là tên
//        strcpy_s(firstName, sizeof(buffer), fullName);
//        lastName[0] = '\0'; // Họ lót rỗng
//    }
//}
//
//int main() {
//    char fullName[256];
//    char lastName[256];
//    char firstName[256];
//
//    // Nhập chuỗi họ tên
//    printf("Nhap chuoi ho ten: ");
//    fgets(fullName, sizeof(fullName), stdin);
//    fullName[strcspn(fullName, "\n")] = '\0'; // Xóa ký tự '\n' ở cuối chuỗi nếu có
//
//    // Cắt chuỗi họ tên thành họ lót và tên
//    splitName(fullName, lastName, firstName);
//
//    // Xuất kết quả
//    printf("Ho lot: '%s'\n", lastName);
//    printf("Ten: '%s'\n", firstName);
//
//    return 0;
//}
