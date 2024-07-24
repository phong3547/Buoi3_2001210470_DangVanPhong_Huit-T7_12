//#include <stdio.h>
//#include <ctype.h>
//
//void capitalizeWords(char* str) {
//    int i = 0;
//    int inWord = 0;
//
//    while (str[i] != '\0') {
//        if (isspace(str[i])) {
//            inWord = 0;  // Đang ở khoảng trắng, không phải từ
//        }
//        else {
//            if (!inWord) {
//                str[i] = toupper(str[i]);  // Chữ cái đầu tiên của từ
//                inWord = 1;
//            }
//            else {
//                str[i] = tolower(str[i]);  // Các ký tự còn lại trong từ
//            }
//        }
//        i++;
//    }
//}
//
//int main() {
//    char str[] = "hello world this is a test";
//
//    capitalizeWords(str);
//
//    printf("%s\n", str);
//    return 0;
//}
