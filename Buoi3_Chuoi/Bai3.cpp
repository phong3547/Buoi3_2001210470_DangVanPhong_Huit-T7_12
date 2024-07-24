//#include <stdio.h>
//#include <ctype.h>
//
//void normalizeString(char* str) {
//    int i = 0, j = 0;
//    int inWord = 0;
//
//    // Bỏ qua khoảng trắng ở đầu chuỗi
//    while (str[i] != '\0' && isspace(str[i])) {
//        i++;
//    }
//
//    // Xử lý các ký tự còn lại để loại bỏ khoảng trắng thừa giữa các từ
//    while (str[i] != '\0') {
//        if (isspace(str[i])) {
//            if (inWord) {
//                str[j++] = ' ';  // Thay thế khoảng trắng thừa bằng một khoảng trắng đơn
//                inWord = 0;
//            }
//        }
//        else {
//            str[j++] = str[i];
//            inWord = 1;
//        }
//        i++;
//    }
//
//    // Xóa khoảng trắng ở cuối chuỗi
//    if (j > 0 && str[j - 1] == ' ') {
//        j--;
//    }
//
//    str[j] = '\0';  // Kết thúc chuỗi mới
//}
//
//int main() {
//    char str[] = "        Day    la 1 vi du chuoi  ";
//
//    normalizeString(str);
//
//    printf("'%s'\n", str);
//    return 0;
//}
