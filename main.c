#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *bash_cmd = "/bin/sh";

void write_date()
{
    system("/bin/date > error_time");
}

void set_root_perm(int var)
{
    if (var)
    {
        setuid(0);
        setgid(0);
    }
}

void write_to_file(char *string)
{
    char buffer[100];
    strcpy(buffer, string);
    FILE *fptr = fopen("data", "w+");

    if (fptr == NULL)
    {
        write_date();
    }
    else{
        fprintf(fptr, "%s", string);
        fclose(fptr);
    }
}

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        write_to_file(argv[1]);
        return 0;
    }
    return 1;
}
