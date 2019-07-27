#include <stdio.h>
#include <stdlib.h>

struct list{
	int data;
	struct list *front, *next;
}; //front(前個) 是 比目前小的資料 next(後個)是比目前大的資料 

typedef struct list list;

list *first=NULL, *last, *cur, *trave, *tmp;
//指向第一個、指向最後一個、指向新創記憶體、尋訪用、
//暫存用指標 

void FreeData(){
	trave=first;
	while(trave!=NULL){
		tmp=trave;
		trave=trave->next;
		free(tmp);
	}
}
 
int main(){
	char c[3];
	int n, total=0;
	while(1){
		printf("請輸入一個正整數: "); 
		scanf("%d", &n);
		if(n<1){
			printf("輸入非正整數，你確定要結束輸入嗎?(Y/N):");
			scanf("%s", c);
			if(c[0]=='Y' || c[0]=='y'){
				int i=1;
				printf("所有正整數由大到小排序結果\n");
				trave=last;
				while(trave!=NULL){
					printf("#%03d: %d\n", i, trave->data);
					trave=trave->front;
					i++;
				}
				i=1;
				printf("所有正整數由小到大排序結果\n");
				trave=first;
				while(trave!=NULL){
					printf("#%03d: %d\n", i, trave->data);
					trave=trave->next;
					i++;
				}
				break;
			}
			else if(c[0]=='n' || c[0]=='N') continue;
			else continue;
		}
	
		if(first==NULL){ //如果是第一筆資料 
			cur=(list *)malloc(sizeof(list)); //開新記憶體空間 
			first=cur; last=cur; //把first跟last指向新開的記憶體空間 
			cur->data=n; cur->front=NULL; cur->next=NULL; //給 data 值 把指標都指好 
		}
		else{
			if(n <= first->data){
				cur=(list *)malloc(sizeof(list));
				cur->data=n;
				first->front=cur;
				cur->next=first;
				cur->front=NULL;
				first=cur;
			}
			else{
				trave=first->next;
				while(trave!=NULL){
					if(trave->data >= n){
						cur=(list*)malloc(sizeof(list));
						cur->data=n;
						trave->front->next=cur;
						cur->front=trave->front;
						cur->next=trave;
						trave->front=cur;
						break;
					}
					trave=trave->next;
				}
				if(trave==NULL){
					cur=(list *)malloc(sizeof(list)); cur->data=n;
					cur->front=last; cur->next=NULL;
					last->next=cur;
					last=cur;
				}
			}
		}
	}
	FreeData();
	return 0;
}
