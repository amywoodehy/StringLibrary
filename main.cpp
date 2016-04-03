#include <iostream>
#include <cstdlib>


namespace TrimPointer {
    using namespace TrimPointer;

    int get_length(char* s){
        int i = 0;
        while(*(s+i) != '\0') {
            i++;
        }
        return i;
    }

    char* ltrim(char* s) {
        int len = get_length(s);
        char *output_string = (char *) malloc((size_t) len);
        bool flag = true;
        int j=0;
        for(int i=0; i<len; i++) {
            if(flag) {
                if(*(s + i) != ' ') {
                    flag = false;
                    i--;
                }
            } else {
                *(output_string + j) = *(s+i);
                j++;
            }
        }
        return output_string;
    }

    char* rtrim(char* s) {
        int len = get_length(s);
        int len_before_spaces = len;
        for (; len_before_spaces > 0; len_before_spaces--) {
            char c = *(s+len_before_spaces);
            if(c != ' ' && c != '\0') {
                len_before_spaces++;
                break;
            }
        }

        if(len_before_spaces >= len or len_before_spaces == 0) {
            std::cerr << "NO need to right trim" << std::endl;
            return s;
        }

        char *output_string = (char *) malloc((size_t) len_before_spaces);
        for(int i=0; i < len_before_spaces; i++)
            *(output_string + i) = *(s + i);

        //*(output_string + len_before_spaces + 1) = '\0';
        return output_string;
    }

    char* trim(char* string) {
        if(string == 0)
            std::cerr << "zero pointer";

        if(get_length(string) == 0)
            std::cerr << "zero length string";

        return ltrim(rtrim(string));
    }

    void trim(char* input, char* output) {
        output = ltrim(rtrim(input));
    }
};

namespace TrimArray{
    using namespace TrimArray;
    char* trim(char* s){
        int len = TrimPointer::get_length(s);

        int left = 0;
        int right = len;
        for(int i=0; i<len; i++) {
            if(s[i] == ' ')
                left++;
            else
                break;
        }

        for(int i=len; i>0; i--) {
            if(s[i] == ' ' or s[i] == '\0')
                right--;
            else
                break;
        }

        int length = right - left;
        if(length > len or length == 0)
            return s;

        char* output = (char *) malloc((size_t) length+1);
        for(int i=0; i <= length; i++)
            output[i] = s[left+i];
        output[length+1] = '\0';
        return output;
    }
}

int main() {
//    char str[] = "a";
//    std::cout << TrimPointer::trim(str) << "<" << std::endl;
//    std::cout << TrimArray::trim(str) << "<" << std::endl;
    char both_trim[] = "    hello world!   ";
    std::cout << TrimPointer::trim(both_trim) << "<" << std::endl;
    std::cout << TrimArray::trim(both_trim) << "<" << std::endl;
    char left_trim[] = "   Hello left Trim!";
    std::cout << TrimPointer::trim(left_trim) << "<" << std::endl;
    std::cout << TrimArray::trim(left_trim) << "<" << std::endl;
    char right_trim[] = "Hello Right Trim!       ";
    std::cout << TrimPointer::trim(right_trim) << "<" << std::endl;
    std::cout << TrimArray::trim(right_trim) << "<" << std::endl;
//    std::cin.getline(str, '$');
//    std::cout << TrimPointer::trim((char*) str) << "<" << std::endl;
//    std::cout << TrimArray::trim((char*) str) << "<" << std::endl;
    return 0;
}
