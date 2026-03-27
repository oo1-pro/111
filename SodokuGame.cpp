#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CODE_LEN 4

void clearInput() {
    while (getchar() != '\n');
}

int main() {
	int signIn=0;
	char id[] = "admin";
    char pw[] = "123456";

    char inputId[20];
    char inputPw[20];
    printf("请输入账号：");
    scanf("%s", inputId);
    
    printf("请输入密码：");
    scanf("%s", inputPw);

    if(strcmp(inputId, id) != 0 || strcmp(inputPw, pw) !=0) {
        printf("\n账号或密码错误！登录失败！\n");
        return 0;
    }

    printf("\n账号密码正确！请进行人机验证！\n\n");
    char pool[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char code[CODE_LEN + 1];
    char input[20];
    
    int i;
    
    srand((unsigned)time(NULL));

    for(i = 0; i < CODE_LEN; i++) {
        code[i] = pool[rand() % strlen(pool)];
    }
    code[CODE_LEN] = '\0';
    printf("请证明你不是AI\n");

    for(i = 0; i < CODE_LEN; i++) {
        if(rand() % 2)    printf("- ");
        else    printf("  ");
    }
    printf("\n");

    for(i = 0; i < CODE_LEN; i++) {
        printf("%c", code[i]);
        if(rand() % 3 == 0)   printf("| ");
        else   printf("  ");
    }
    printf("\n");

    for(i = 0; i < CODE_LEN; i++) {
        if(rand() % 2) printf("- ");
        else printf("  ");
    }
    printf("\n");

    printf("请输入验证码：");
    scanf("%s", input);
    clearInput(); 
    
    int cnt=1;
    while(cnt<3){
        if(!strcmp(input, code)) {
            printf("\n验证成功！看来你确实是人类！！\n");
            signIn=1;
            break;
        } else {
            printf("请再次输入验证码（你还有%d次机会）：",3-cnt);
            scanf("%s", input);
            clearInput();
            cnt++; 
        }
    }
    
    if(cnt>=3) {
        printf("\n验证失败！你是人机！！\n");
        return 0;
    }

    if(signIn==1){
        printf("欢迎来到Sudoku Game!\n");
        int win;
        int full;
        
        while(1){
        	
            int sodoku[3][3]={0};
            int used[3][3]={0};	
            
            for(int i = 0;i<9;i++){
                printf("请输入放置的数字，和数字的坐标（数字 x,y）：");
                
                int num;
                int x;
                int y;
                int ret = scanf("%d %d,%d",&num,&x,&y);
                
                if(ret != 3){
                    printf("\n输入格式错误！\n");
                    clearInput();
                    i--;
                    continue;
                }

                if (x < 0 || x > 2 || y < 0 || y > 2) {
                    printf("\n坐标错误！只能是 0、1、2\n");
                    clearInput(); 
                    i--;
                    continue;
                }
                if (num < 1 || num > 3) {
                    printf("\n数字错误！只能是1、2、3！\n");
                    clearInput(); 
                    i--;
                    continue;
                }
                if (used[x][y] == 1) {
                    printf("\n该位置已有数字！\n");
                    clearInput(); 
                    i--;
                    continue;
                }			
                used[x][y]=1;
                sodoku[x][y]=num;	
            }
            
            full=1;
            for(int i = 0;i<3;i++){
                for(int j = 0;j<3;j++){
                    if(used[i][j]!=1){
                        full=0;
                        break; 
                    }
                }
            }  
            win=1;
            for(int  i = 0;i<3;i++){
                int count[4]={0};
                for(int j = 0;j<3;j++){
                    count[sodoku[i][j]]++;
                }
                if(count[1]!=1||count[2]!=1||count[3]!=1){
                    win=0;
                    break;
                    
                }
            }
            
            for(int  i = 0;i<3;i++){
                int count[4]={0};			
                for(int j = 0;j<3;j++){
                    count[sodoku[j][i]]++;
                }
                if(count[1]!=1||count[2]!=1||count[3]!=1){
                    win=0;
                    break;
                }
            }
            
            if(win == 1){
                printf("\n恭喜通关！\n");
                break;
            }
            
            int isGoOn;
            printf("\n你失败了！继续游戏请输入1，退出请输入0：");
            scanf("%d",&isGoOn);
            clearInput();
            
            if(isGoOn == 0){
                printf("\n游戏结束！\n");
                break;
            }
        }	
    }
    return 0;
}
	
