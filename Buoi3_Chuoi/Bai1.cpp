//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//
//// Hàm kiểm tra chuỗi có chứa toàn ký số không
//int kiemTraToanKySo(const char s[]) {
//    for (int i = 0; s[i] != '\0'; i++) {
//        if (!isdigit((unsigned char)s[i])) {
//            // Nếu có ký tự không phải là số, trả về 0
//            return 0;
//        }
//    }
//    // Nếu tất cả các ký tự đều là số, trả về 1
//    return 1;
//}
//
//int main() {
//    char s[100];
//
//    // Nhập chuỗi từ người dùng
//    printf("Nhap chuoi: ");
//    fgets(s, sizeof(s), stdin);
//
//    // Loai bo ky tu newline o cuoi chuoi neu co
//    size_t len = strlen(s);
//    if (len > 0 && s[len - 1] == '\n') {
//        s[len - 1] = '\0';
//    }
//
//    // Kiem tra chuoi va in ket qua
//    if (kiemTraToanKySo(s)) {
//        printf("Chuoi chua toan ky so.\n");
//    }
//    else {
//        printf("Chuoi khong chua toan ky so.\n");
//    }
//
//    return 0;
//}
