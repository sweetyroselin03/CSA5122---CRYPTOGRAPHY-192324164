#include <stdio.h>
#include <ctype.h>
#include <string.h>
char m[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};
void encrypt(char a, char b) {
    int r1=0,c1=0,r2=0,c2=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++) {
            if(m[i][j]==a) r1=i,c1=j;
            if(m[i][j]==b) r2=i,c2=j;
        }
    if(r1==r2)
        printf("%c%c",m[r1][(c1+1)%5],
                       m[r2][(c2+1)%5]);
    else if(c1==c2)
        printf("%c%c",m[(r1+1)%5][c1],
                       m[(r2+1)%5][c2]);
    else
        printf("%c%c",m[r1][c2],m[r2][c1]);
}
int main() {
    char input[300], p[300];
    int n=0;
    printf("Enter plaintext: ");
    fgets(input,sizeof(input),stdin);
    for(int i=0;input[i];i++) {
        char c=toupper(input[i]);
        if(c>='A' && c<='Z') {
            if(c=='J') c='I';
            p[n++]=c;
        }
    }
    printf("Ciphertext: ");
    for(int i=0;i<n;) {
        char a=p[i++];
        char b;
        if(i>=n)
            b='X';
        else if(p[i]==a)
            b='X';
        else
            b=p[i++];
        encrypt(a,b);
    }
    printf("\n");
    return 0;
}
