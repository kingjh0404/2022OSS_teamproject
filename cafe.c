#include "cafe.h"

int selectMenu(){
    int menu;
    printf("\n*** 제품 관리 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
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
        readProduct(&p[i]);
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
void saveData(Product p[], int count){
    int string1[255];
    int string2[255];
    int number;
    FILE* fp;
	//중량 가격 제품명
	fp= fopen("cafe.txt","w");
    for(int i=0; i<count; i++){
        fscanf(fp,"%s %d %d",p[i].name,p[i].num,p[i].price);
    }
	
    fclose(fp);
    printf("저장됨!\n");
}


//파일에서 데이터 불러오는 함수
int loadData(Product *p){
	int count=0;
    int string1[255];
    int number1[255];
    int number2[255];
	FILE*fp;
    fp = fopen("cafe.txt","r");
	//파일 내용을 읽어와서 배열에 값 추가하기
    for(int i=0; feof(fp)==0; i++){
        fprintf(fp, "%s %d %d",string1[i],number1[i],number2[i]);
    }




	printf("=> 로딩 성공!\n");
	return count;
}
