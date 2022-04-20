#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char string[100];
char test[65];


void lazy() {
  system(string);
}

void food(int magic) {
  printf("THANK YOU!\n");
  if (magic == 0xdeadbeef) {
    strcat(string, "/bin");
  }
}


void feeling_sick(int magic1, int magic2) {
  printf("1m f33ling s1cK...\n");
  if (magic1 == 0xd15ea5e && magic2 == 0x0badf00d) {
    strcat(string, "/echo 'This message will self destruct in 30 seconds...BOOM!'");
  }
}

void vuln(char *string) {
  char buffer[100] = {0};
  strcpy(buffer, string); 
}

int main(int argc, char** argv) {
  string[0] = 0;


  printf("Tell me what you got?\n");
  scanf("%s", test);
  printf("Tady je ta blbost: %s \n", test);

  printf("m3 hUN6rY...cAn 1 haZ 5H3ll?! f33d mE s0m3 beef\n\n");
  if (argc > 1) {
    vuln(argv[1]);
  } else {
    printf("y0u f0rG0T t0 f33d mE!!!\n");
  }
  return 0;
}