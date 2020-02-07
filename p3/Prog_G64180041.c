/****************************************************************/
/* L INKED L IST P ROGRAM B Y : A KHILESH K UMAR S RIVASTAVA */
/****************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
{
    int info;
    struct node *next;
};
typedef struct node* NODEPTR;
NODEPTR list=NULL;
/* Function Prototyping */
NODEPTR getnode(void);
void freenode(NODEPTR);
void insbeg(int);
void insafter(int,int);
void insend(int);
int delbeg();
int delafter(int);
int delend();
void traverse();
void hapusK(int);
void cetak_genap();
void inbeforeend(int);
void countAll();


/*Main Function*/
int main()
{
    // NODEPTR p;
    int x,c,y;
     char ch;
    begin:
    printf("1. Insert in the beginning\n");
    printf("2. Insert after a node\n");
    printf("3. Insert in the end\n");
    printf("4. Delete from the beginning\n");
    printf("5. Delete after a node\n");
    printf("6. Delete from the end\n");
    printf("7. Traverse\n");
    printf("8. Delete in index\n");
    printf("9. Print even index\n");
    printf("10. Insert before end\n");
    printf("11. Count\n");
    printf("12. exit\n");
    printf("===========================\n");
    printf("Enter your choice\t");
    scanf("%d",&c);
    switch(c)
    {
        case 1: 
            printf("\nEnter the element to be inserted ");
            scanf("%d",&x);
            insbeg(x); 
            break;
        case 2:
            printf("\nEnter the element to be inserted after which node ");
            scanf("%d",&y);
            printf("\nEnter the element to be inserted ");
            scanf("%d",&x);
            insafter(y,x); 
            break;
        case 3: 
            printf("\nEnter the element to be inserted ");
            scanf("%d",&x);
            insend(x); 
            break;
        case 4: 
            printf("The deleted item is:=> %d",delbeg());
            break;
        case 5: 
            printf("\nEnter the element to be inserted after which node");
            scanf("%d",&y);
            printf("The deleted item is:=> %d",delafter(y)); 
            break;
        case 6: 
            printf("The deleted item is:=> %d",delend()); 
            break;
        case 7: 
            traverse(); 
            break;
        case 8:
            printf("\nEnter index which element want to delete ");
            scanf("%d", &x);
            hapusK(x); 
            break;
        case 9: 
            cetak_genap(); 
            break;
        case 10: 
            printf("\nEnter the element to be inserted before end ");
            scanf("%d",&x);
            inbeforeend(x); 
            break;
        case 11: 
            countAll(); 
            break;
        case 12: 
            exit(1);
        default: 
            printf("\nWrong choice");
            break;
    }
    printf("\nDo you wish to continue? (y/n)");
    fflush(stdin);
    scanf("%c",&ch);if(ch=='y'||ch=='Y')
    goto begin;
    exit(1);
}
/*********************************************/
NODEPTR getnode(void)
{
    NODEPTR p;
    p=(NODEPTR)malloc(sizeof(struct node));
    return p;
}
/*********************************************/
void freenode(NODEPTR p)
{
    free(p);
}
/*********************************************/
void traverse()
{
    NODEPTR p=list;
    printf("\nThe Linked List is\n");
    while(p!=NULL)
    {
        printf("\t%d",p->info);
        p=p->next;
    }
}
/*********************************************/
void insafter(int y,int x)
{
    NODEPTR p,q;
    q=getnode();
    q->info=x;
    for(p=list;p->info!=y&&p!=NULL;p=p->next)
    ;
    q->next=p->next;
    p->next=q;
}
/*********************************************/
void insbeg(int x)
{
    NODEPTR p;
    p=getnode();
    p->info=x;
    p->next=list;
    list=p;
}
/*********************************************/
void insend(int x)
{
    NODEPTR p=list,q;
    q=getnode();
    q->info=x;
    q->next=NULL;
    while(p->next!=NULL)
    p=p->next;
    p->next=q;
}
/*********************************************/
int delbeg()
{
    NODEPTR p;
    int x;
    p=list;
    list=p->next;
    x=p->info;
    freenode(p);
    return x;
}
/*********************************************/
int delafter(int y)
{
    NODEPTR p=list,q;
    int x;
    for(p=list;p->info!=y&&p!=NULL;p=p->next);
    q=p->next;
    q->next=p->next;
    x=p->info;
    freenode(p);
    return x;
}
/*********************************************/
int delend()
{
    NODEPTR p=list,q=NULL;
    int x;
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    q->next=NULL;
    x=p->info;
    freenode(p);
    q->next=NULL;
    return x;
}
/*********************************************/
void hapusK(int k)
{
    int n = 1;
    NODEPTR p = list, q=NULL;
    while(p != NULL && n != k)
    {
        n++;
        q = p;
        p = p->next;
    }

    q->next = p->next;
    freenode(p);

    // printf("%d\n", n);
}
/*********************************************/
void cetak_genap()
{
    NODEPTR p = list;
    if(p != NULL)
    {
        p = p->next;
        while(p != NULL)
        {
            printf("%d ", p->info);
            if(p->next != NULL)
                p = p->next->next;
            else
                break;
        }
    }
}
/*********************************************/
void inbeforeend(int input){
    printf("%d\n", input);
    NODEPTR p = list, q = NULL, BARU = getnode();
    while(p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    BARU->info = input;
    BARU->next = p;
    q->next = BARU;
}
/*********************************************/
void countAll()
{
    int n = 0;
    NODEPTR p = list;
    while(p != NULL)
    {
        n++;
        p = p->next;
    }
    printf("%d\n", n);
}
/*********************************************/
