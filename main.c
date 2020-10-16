#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define ElemType char

typedef struct Node{
	ElemType data;
	struct Node* next;
} Node,*LinkList;

//初始化链表
void initList(LinkList *L){
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
}

//头插法创建顺序表
void createFromHead(LinkList L){
	Node *s;
	char c;
	int flag = 1;
	while(flag){
		c = getchar();
		if(c!='$'){
			s = (Node*)malloc(sizeof(Node));
			s->data = c;
			s->next = L->next;
			L->next = s;
		}
		else{
			flag = 0;
		}
	
	}
}

//插入元素操作
int insertElement(LinkList L,int i,ElemType e){
	Node *pre, *s;
	int k;
	if(i<=0){
		printf("插入的位置[%d]不合法!\n",i);
		return ERROR;
	}
	pre = L;
	for(k=0;pre!=NULL&&k<i-1;k++){
		pre=pre->next;
	}
	if(pre == NULL){
		printf("插入的位置[%d]不合法!\n",i);
		return ERROR;
	}
	s = (Node*)malloc(sizeof(Node));
	s->data = e;
	s->next = pre->next;
	pre->next = s;
	return OK;
}

//查找元素操作
int Locate(LinkList L,ElemType e){
	int k;
	Node *pre;
	pre = L;
	
	for(k=0;pre->next!=NULL;k++){
		if(pre->data == e){
			printf("表中内容为[%c]的元素位置为%d\n",e,k-1);
			return OK;
		}
		pre=pre->next;
	}
	printf("元素未找到!\n");
	return ERROR;
}

//删除元素操作
int delElement(LinkList L,int i,ElemType *e){
	Node *pre,*r;
	int k;
	pre = L;
	for(k=0;pre->next!=NULL&&k<i-1;k++){
		pre=pre->next;
	}
	if(i<=0 ||pre == NULL){
		printf("删除的位置[%d]不合法!\n",i);
		return ERROR;
	}
	r = pre->next;
	pre->next = r->next;
	*e = r->data;
	free(r);
	printf("成功删除了位置%d的元素，元素内容为[%c]\n",i,*e);
	return OK;
	
}

//打印顺序表
void printList(LinkList L){
	Node *p;
	p = L->next;
	printf("[");
	while(p->next!=NULL){
		printf("%c,",p->data);
		p=p->next;
	}
	printf("%c]\n",p->data);
}

//主函数
void main(){

	//初始化变量
	ElemType e1,e2,e3,e4,e5;
	LinkList L;
	
	//初始化顺序表L
	initList(&L);

	//创建顺序表L，默认内容为{1,2,3,5,7},长度为5
	printf("请输入任意字符，$表示结尾：\n");
	createFromHead(L);

	//打印顺序表原始内容
	printf("顺序表原始内容：\n");
	printList(L);

	//执行插入元素操作，并打印结果
	printf("\n开始执行插入操作:\n");
	insertElement(L,0,'Z');
	printf("完成插入后表内容为:\n");
	printList(L);
	insertElement(L,7,'X');
	printf("完成插入后表内容为:\n");
	printList(L);
	insertElement(L,6,'C');
	printf("完成插入后表内容为:\n");
	printList(L);
	insertElement(L,1,'V');
	printf("完成插入后表内容为:\n");
	printList(L);
	insertElement(L,3,'N');
	printf("完成插入后表内容为:\n");
	printList(L);

	//执行查找元素操作
	printf("\n开始执行查找操作:\n");
	Locate(L,'A');
	Locate(L,'B');
	Locate(L,'C');
	Locate(L,'D');
	Locate(L,'O');
	
	//执行删除元素操作
	printf("\n开始执行删除操作:\n");
	delElement(L,3,&e1);
	printf("完成删除后表内容为:\n");
	printList(L);
	delElement(L,1,&e2);
	printf("完成删除后表内容为:\n");
	printList(L);
	delElement(L,5,&e3);
	printf("完成删除后表内容为:\n");
	printList(L);
	delElement(L,0,&e4);
	printf("完成删除后表内容为:\n");
	printList(L);
	delElement(L,7,&e5);
	printf("完成删除后表内容为:\n");
	printList(L);
	
	
	

}
