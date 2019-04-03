#include<stdio.h>
#include<malloc.h>
typedef struct link{
int info;
struct link *next;
struct link *prev;
}node;

node *head=NULL;
node *new,*p=NULL;


void delpos();
void addbeg();
void deleteend();
void deletebeg();
void insertplace();
void addnode();
void viewall();
void main()
{
int ch;
do
{
printf("\n1.add node\n2.viewall\n3.insertplace\n4.deletebeg\n5.deleteend\n6.addbeg\n7.delpos\n");
scanf("%d",&ch);
switch(ch)
{
case 1:addnode();
break;
case 2:viewall();
break;
case 3:insertplace();
break;
case 4:deletebeg();
break;
case 5:deleteend();
break;
case 6:addbeg();
break;
case 7:delpos();
break;
}
}while(1);
}
void addnode()
{
new=(node *)malloc(sizeof(node));
scanf("%d",&new->info);
if(head==NULL)
{
new->prev=NULL;
head=new;
}
else
{
p->next=new;
new->prev=p;
}
new->next=NULL;
p=new;
}

void viewall()
{
node *t;
t=head;
while(t!=NULL)
{
printf("%d ",t->info);
t=t->next;
}
}

void insertplace()
{
node *t;
t=head;
int pos,i=1;
scanf("%d",&pos);
while(t!=NULL && i!=pos)
{
p=t;
t=t->next;
i++;
}
new=(node*)malloc(sizeof(node));
scanf("%d",&new->info);
p->next=new;
t->prev=new;
new->next=t;
new->prev=p;

}

void deletebeg()
{
node *t;
t=head;
head=head->next;
head->prev=NULL;
free(t);
}

void deleteend()
{
node *t;
t=NULL;
while(t->next!=NULL)
{
p=t;
t=t->next;
}
p->next=NULL;
free(t);
}

void addbeg()
{
node *t;
t=head;
new=(node*)malloc(sizeof(node));
scanf("%d",&new->info);

new->prev=NULL;
new->next=head;
head=new;

}


void delpos()
{
node *t;
t=head;
int i=1,pos;
scanf("%d",&pos);
while(t!=NULL && i!=pos)
{
p=t;
t=t->next;
i++;
}

p->next=t->next;
t->next->prev=p;
free(t);
}


void delend()
{
node *t;
t=head;
while(t->next!=NULL)
{
t=t->next;
p=t;
}
p->next=NULL;
free(t);
}




