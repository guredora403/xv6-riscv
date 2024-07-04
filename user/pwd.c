#include "kernel/types.h"
#include "kernel/fs.h"
#include "kernel/stat.h"
#include "user/user.h"

// ディレクトリ名を格納する配列
char dirs[128][15];

void main(){
    int depth = 0;
    int fd;
    // カレントディレクトリのstat
    struct stat st;
    // ディレクトリエントリ
    struct dirent de;
    if((fd = open(".", 0)) < 0){
        printf("current dir open error!");
        exit(1);
    }
    if((fstat(fd, &st) < 0)){
        printf("current dir stat error!");
        exit(1);
    }
    while(st.ino != ROOTINO){
        int parent_fd;
        struct stat parent_st;
        if((parent_fd = open("..", 0)) < 0){
            printf("parent dir open error!");
            exit(1);
        }
        if(fstat(parent_fd, &parent_st) < 0){
            printf("parent dir stat error!");
            exit(1);
        }
        while(read(parent_fd, &de, sizeof(de)) == sizeof(de)){
            if(de.inum == st.ino){
                strcpy(dirs[depth], de.name);
                depth++;
                break;
            }
        }
        close(fd);
        chdir("..");
        fd = parent_fd;
        st = parent_st;
    }
    close(fd);
    printf("/");
    for(int i = depth - 1; i >= 0; i--){
        printf("%s/", dirs[i]);
    }
    printf("\n");
    exit(0);
}