#include<stdio.h>


typedef  struct{
    int id;
    char color;
    float price;
} car;


void update_car(car *c, char clr){
    c->color = clr;
}


int main(int argc, char **argv){
    
    car mycar;
    update_car(&mycar,'R');

    printf("%c",mycar.color);

    int a = 0;

    int *pa = &a;

    int y = *pa;

    return 0;
}