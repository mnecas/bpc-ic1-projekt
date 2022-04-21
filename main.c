#include <stdio.h>
#include <string.h>

char* not_used = "/bin/sh";
int is_root = 0;

void write_date() {
    system("/bin/date > time_now");
}

void set_root_perm(var){
    if(var){
        setuid(0);
        setgid(0);
    }
}

void vulnerable_function(char* string) {
    char buffer[100];
    set_root_perm(is_root);
    strcpy(buffer, string);
}

int main(int argc, char** argv) {
    vulnerable_function(argv[1]);
    return 0;
}
