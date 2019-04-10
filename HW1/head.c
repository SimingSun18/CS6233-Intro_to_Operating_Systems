#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void processFile(int fd, char *fileName, int endLine){
    int i, n;
    int lineNum = 0;
    while((n = read(fd, buf, sizeof(buf))) > 0){
        for (i = 0; i <= n; i++){
            printf(1, "%c", buf[i]);
            if (buf[i] == '\n'){
                lineNum++;
                if (lineNum == endLine){
                    exit();
                }
            }
        }
    }
    if (n < 0){
        printf(1, "head: read error\n");
    }
}
int main(int argc, char *argv[]){
    int fd, i;
    int line = 10;
    char *filename = "";
    if (argc <= 1){
        processFile(0, "", 10);
        exit();
    }else {
        for (i = 1; i < argc; i++){
            char temp = *argv[i];
            if (temp == '-'){
                argv[i]++;
                line = atoi(argv[i]);
            }else{
                if ((fd = open(argv[i], 0)) < 0){
                    printf(1, "File %s can't open\n", argv[i]);
                    exit();
                }
            }
        }
        processFile(fd, filename, line);
        close(fd);
        exit();
    }
}
