// vuln.c
#include <stdio.h>
#include <string.h>

void print(unsigned char* encoded) __attribute__((section(".text.print")));
void the_function_that_is_going_to_generate_the_greatest_vhdl_code() __attribute__((section(".text.gen")));
void printo() __attribute__((section(".text.printo")));
void secret_fuction_that_prints_the_greatest_vhdl() __attribute__((section(".text.secret"))) __attribute__((used));
void check_vhdl_code(char *user_input, int debug) __attribute__((section(".text.vuln")));

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

void printflag() {
    printf("ctf{th1s_surly_th3_r34l_fl4g}");
}

void secret_fuction_that_prints_the_greatest_vhdl() {
    the_function_that_is_going_to_generate_the_greatest_vhdl_code();
}

void check_vhdl_code(char *user_input, int debug) {
    char buffer[20];
    strcpy(buffer, user_input);

    printf("invalid virelog code!\n");

    if (debug) {
        void *returnAddr = __builtin_return_address(0);
        printf("Return address: %p\n", returnAddr);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Help Fathi write VHDL code! Your mission is to create the ultimate VHDL TP. A TP that no chatbot can solve and no student can understand! \n");
        return -1;
    }
    if (strcmp(argv[0], "./debugging-fathi-challenge") == 0) {
        printf("addr of main:%p %p\n", (void*)main, (void*)check_vhdl_code);
        check_vhdl_code(argv[1], 1);
    } else {
        check_vhdl_code(argv[1], 0);
    }
    if (argc == 0) {
        printflag();
    }
    return 0;
}