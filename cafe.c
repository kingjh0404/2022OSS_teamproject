#include "cafe.h"

int selectMenu(){
    int menu;
    printf("\n*** 제품 관리 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 이름검색\n");
    printf("7. 가격검색\n");
    printf("8. 카페 종류 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
void listProduct(Product *p,int count){

    printf("\nNo. Name          type price\n");
    printf("================================\n");
    for(int i=0; i<count; i++){
        if( p[i].num == -1 || p[i].price == -1 ) continue;
        printf("%2d.", i+1);
        readProduct(p[i]);
    }
    printf("\n");
}

int selectDataNo(Product *p, int count){
    int no;
    listProduct(p,count);
    printf("번호는 (취소:0)?");
    scanf("%d",&no);
    getchar();
    return no;
}

//배열데이터를 파일에 저장하는 함수
void saveData(Product *p, int count){
 
    FILE* fp;
   //중량 가격 제품명
   fp= fopen("cafe.txt","wt");
   fprintf(fp,"=====================\n");
   fprintf(fp,"이름   가격  종류(음료일때만 V 표시)\n");
       for(int i=0; i<count; i++){
      if(p[i].price==-1 && p[i].num ==-1) continue; 
      fprintf(fp,"%s ",p[i].name);
      fprintf(fp,"%d   ",p[i].price);
        //fprintf(fp,"%s ",p[i].name);
      if(p[i].num==0) {
        fprintf(fp,"V \n"); 
      }
      else fprintf(fp,"\n");
    
  
    }
   
    fclose(fp);
    printf("저장됨!\n");
}


//파일에서 데이터 불러오는 함수
int loadData(Product *p){
   int count=0;

   FILE*fp;
    fp = fopen("cafe.txt","rt");
   //파일 내용을 읽어와서 배열에 값 추가하기
    for(int i=0; i<100; i++){
       if(feof(fp)) break; 
        fprintf(fp,"%s",p[i].name);
       if(p->num==0) fputs("음료\n", fp); 
 else fputs("디저트\n", fp); 
 fprintf(fp,"%d\n",p[i].price);
      }



    fclose(fp);
   printf("=> 로딩 성공!\n");
   return count;
}

void searchName(Product *p,int count){ 
  int scnt =0; // 검색을 했을 때, 검색된 데이터가 없음 
  char search[200]; 
  printf("검색할 이름? "); 
  scanf("%s",search); 
  printf("*****************\n"); 
  for(int i=0; i<count; i++){ 
    if(p[i].price==-1) continue; 
    if(strstr(p[i].name,search)){ 
    printf("%2d. ",i+1); 
    readProduct(p[i]); 
    scnt++; 
    } 
  } 
 if(scnt==0) printf("=>검색된 데이터 없음!"); 
 printf("\n"); 
} 
void searchprice(Product *p, int count){ 
   int scnt =0; // 검색을 했을 때, 검색된 데이터가 없음 
   int search; 
   printf("검색할 가격? "); 
   scanf("%d",&search); 
   printf("*****************\n"); 
  for(int i=0; i<count; i++){ 
   if(p[i].price==-1) continue; 
   if(p[i].price==search){ 
   printf("%2d. ",i+1); 
   readProduct(p[i]); 
   scnt++; 
   } 
   } 
   if(scnt==0) printf("=>검색된 데이터 없음!"); 
   printf("\n"); 
} 
void searchkind(Product *p, int count){ 
  int scnt =0; // 검색을 했을 때, 검색된 데이터가 없음 
  char search[200]; 
  printf("검색할 카페종류 "); 
  scanf("%s",search); 
  printf("*****************\n"); 
  for(int i=0; i<count; i++){ 
    if(p[i].price==-1) continue; 
    if(p[i].num==0){ 
    if(strstr("음료",search)){ 
      printf("%2d",i+1); 
      readProduct(p[i]); 
      scnt++; 
    } 
  } 
  else{ 
    if(strstr("디저트",search)){ 
    printf("%2d",i+1); 
    readProduct(p[i]); 
    scnt++; 
    } 
  } 
 }
}
