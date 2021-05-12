#include <stdio.h>
#include <stdlib.h>

void plano(int tx, int ty, int x, int y){
    int ix, iy;

    for(iy=0; iy<=ty; iy++){
        if(iy>0) printf("\n");
        for(ix=1; ix<=tx; ix++){
            if(ix==x && iy==y){
                printf("R");
                ix++;
            }
            printf("-");
        }
    }
    printf("\n");
}

void movement(int tx, int ty, int *x, int *y){
    int i; char dir;

    if((*x>=0 && *y>=0) && (*x<=tx && *y<=ty)) printf("posit valida\n");

    while(scanf("%c %d", &dir, &i) != EOF){ // ^C para terminar o loop
        if(dir=='N'){
            *y -= i;
            if(*y>ty) *y = ty;
            system("cls");
            plano(tx, ty, *x, *y);
        }
        if(dir=='S'){
            *y += i;
            if(*y<0) *y = 0;
            system("cls");
            plano(tx, ty, *x, *y);
        }
        if(dir=='O'){
            *x -= i;
            if(*x<0) *x = 0;
            system("cls");
            plano(tx, ty, *x, *y);
        }
        if(dir=='L'){
            *x += i;
            if(*x>tx) *x = tx;
            system("cls");
            plano(tx, ty, *x, *y);
        }
    }
}

int main(){
    int nx, ny;
    int tx, ty, x, y;

    scanf("%d %d", &tx, &ty); // tam tab
    scanf("%d %d", &x, &y); // posit robot

    plano(tx, ty, x, y);
    movement(tx, ty, &x, &y);

    return 0;
}
