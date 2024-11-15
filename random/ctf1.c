#include <stdio.h>
#include <string.h>

void print(unsigned char* encoded) {
     int len = 28;
    for(int i = 13, j = 23; i < j; i++, j--) {
        unsigned char temp = encoded[i];
        encoded[i] = encoded[j];
        encoded[j] = temp;
    }
    
    for(int i = 4, j = 12; i < j; i++, j--) {
        unsigned char temp = encoded[i];
        encoded[i] = encoded[j];
        encoded[j] = temp;
    }
    
    for(int i = 0; i < len; i++) {
        encoded[i] = encoded[i] ^ 0x33;
    }
    

    for(int i = 0; i < len; i++) {
        encoded[i] = encoded[i] - 5;
    }
}

void the_function_that_is_going_to_generate_the_greatest_vhdl_code() {
    unsigned char encoded[] = {
        0x7b, 0x6a, 0x78, 0xb3, 0x48, 0x06, 0x57, 0x44, 0x0b, 0x58, 0x58, 0x49, 0x54, 0x5b, 0x5b, 0x49, 0x4b, 0x57, 0x4f, 0x06, 0x42, 0x58, 0x44, 0x0b, 0x0b, 0x4b, 0x4b, 0xb1
    };
    int len = sizeof(encoded);
    
    print(encoded);
    printf("%s\n", encoded);
}

void printo() {
    printf("ctf{this_surly_the_real_flag}");
}

void secret_fuction_that_prints_the_greatest_vhdl() {
    the_function_that_is_going_to_generate_the_greatest_vhdl_code();
}

void vulnerable_function(char *user_input) {
    char buffer[20];
    strcpy(buffer, user_input);

    void *returnAddr = __builtin_return_address(0);
    printf("Return address: %p\n", returnAddr);
}


int main(int argc, char *argv[]) {
    printf("help fathi in writing vdhl code!\n");
    if (argc != 2) {
        return -1;
    }
    printf("addr of main:%p %p %p\n", (void*)main, (void*)vulnerable_function, (void*)secret_fuction_that_prints_the_greatest_vhdl);
    vulnerable_function(argv[1]);

    if (argc == 0) {
        secret_fuction_that_prints_the_greatest_vhdl();
    }
    return 0;
}

