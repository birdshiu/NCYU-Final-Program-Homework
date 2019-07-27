#include <stdio.h>
#include <stdlib.h>

struct list{
	int data;
	struct list *front, *next;
}; //front(�e��) �O ��ثe�p����� next(���)�O��ثe�j����� 

typedef struct list list;

list *first=NULL, *last, *cur, *trave, *tmp;
//���V�Ĥ@�ӡB���V�̫�@�ӡB���V�s�аO����B�M�X�ΡB
//�Ȧs�Ϋ��� 

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
		printf("�п�J�@�ӥ����: "); 
		scanf("%d", &n);
		if(n<1){
			printf("��J�D����ơA�A�T�w�n������J��?(Y/N):");
			scanf("%s", c);
			if(c[0]=='Y' || c[0]=='y'){
				int i=1;
				printf("�Ҧ�����ƥѤj��p�Ƨǵ��G\n");
				trave=last;
				while(trave!=NULL){
					printf("#%03d: %d\n", i, trave->data);
					trave=trave->front;
					i++;
				}
				i=1;
				printf("�Ҧ�����ƥѤp��j�Ƨǵ��G\n");
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
	
		if(first==NULL){ //�p�G�O�Ĥ@����� 
			cur=(list *)malloc(sizeof(list)); //�}�s�O����Ŷ� 
			first=cur; last=cur; //��first��last���V�s�}���O����Ŷ� 
			cur->data=n; cur->front=NULL; cur->next=NULL; //�� data �� ����г����n 
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
