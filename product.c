#include "product.h"

int createProduct(Product *p){
    printf("\n");
    printf("제품명은? ");
    scanf("%s",p->name);

    printf("종류는? (음료면 0,디저트면 1)");
    scanf("%d",&p->num);

    printf("가격은? ");
    scanf("%d",&p->price);
    
    printf("==> 추가됨\n"); 
    return 1;
}

void readProduct(Product p){
    printf("%-15s %d %4d원\n",p.name,p.num,p.price);
}

int updateProduct(Product *p){

    printf("\n");
    printf("제품명은? ");
    scanf("%s",p->name);

    printf("종류는?  (음료면 0,디저트면 1) ");
    scanf("%d",&p->num);

    printf("가격은? ");
    scanf("%d",&p->price);
    printf("==> 수정됨!\n");
    return 1;
};

int deleteProduct(Product *p){
    p->num=-1;
    p->price=-1;
    printf("==> 삭제됨!\n");
    return 0;
}
