#include <stdio.h>

char* local_array() {
    char s3[1024] = {'a', 'b'};
    printf(s3);
    return s3;
}

int main() {
    char* s = local_array();
    printf(s);
    return 0;
}
