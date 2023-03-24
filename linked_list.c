#include<stdio.h>
#include<stdlib.h>


struct node{
      int data;
      struct node *next;
};


void display(struct node*);
struct node* create(struct node*,int);
struct node*insert(struct node*);
struct node*delete(struct node*);
struct node*reverse(struct node*,int);

int main(){
      int n;
      printf("enter size of linked list : ");
      scanf("%d",&n);
      struct node *head,*temp;
      head = (struct node *)malloc(sizeof(struct node));
      create(head,n);
      int choice,status=0;
      printf("------------------------------------------------------------\nchoices are : \n1. display\n2. insert\n3. delete\n4. reverse\n5. exit\n"
      "------------------------------------------------------------");
      while(status==0){
            printf("\nenter choice : ");
            scanf("%d",&choice);
            switch(choice){
                  case 1:
                  display(head);
                  break;
                  case 2:
                  head=insert(head);
                  n=n+1;
                  display(head);
                  break;
                  case 3:
                  head=delete(head);
                  n=n-1;
                  display(head);
                  break;
                  case 4:
                  reverse(head,n);
                  display(head);
                  break;
                  case 5:
                  status=1;
            }
      }
}


void display(struct node*head){
      int i;
      struct node *temp;
      temp=head;
      while (temp!=NULL)
      {
          printf("%d \t",temp->data);
          temp=temp->next;
      }
}


struct node* create(struct node* head,int n){
      int ele,i;
      struct node *temp;
      temp=head;
      for (i=0;i<n;i++){
            if(i!=n-1){
                  printf("enter element %d : ",i);
                  scanf("%d",&ele);
                  temp->data=ele;
                  temp->next=(struct node*)malloc(sizeof(struct node));
                  temp=temp->next;
            }
            else{
                  printf("enter element %d : ",i);
                  scanf("%d",&ele);
                  temp->data=ele;
                  temp->next=NULL;
            }
      }
}


struct node*insert(struct node*head){
      int count=0,pos,ele;
      printf("enter position to insert : ");
      scanf("%d",&pos);
      printf("enter element to be inseted : ");
      scanf("%d",&ele);
      struct node *temp=head,*newnode;
      newnode =(struct node*)malloc(sizeof(struct node));
      newnode->data=ele;
      if (pos==0){
            newnode->next=temp;
            head=newnode;
            return head;
      }
      else{
      while(temp!=NULL){
            if (count==pos-1){
                  newnode->next=temp->next;
                  temp->next=newnode;
                  break;
            }
            temp=temp->next;
            count++;
      }
      }
      return head;
}


struct node*delete(struct node* head){
      int pos,count;
      printf("enter position to delete : ");
      scanf("%d",&pos);
      struct node *temp=head,*del;
      if (pos==0){
            return head->next;
      }
      else{
            while(temp!=NULL){
                  if (count==pos-1){
                        del=temp->next;
                        temp->next=temp->next->next;
                        free(del);
                        break;
                  }
                  count++;
                  temp=temp->next;
            }
      }
      return head;
}


struct node*reverse(struct node*head,int n){
      int darr[n],datele,i;
      struct node* temp=head;
      for(i=0;i<n;i++){
            darr[i]=temp->data;
            temp=temp->next;
      }
      temp=head;
      if (n==2){
            datele=temp->data;
            temp->data=temp->next->data;
            temp->next->data=datele;
      }
      else{
      for(i=0;i<n;i++){
            temp->data=darr[n-1-i];
            temp=temp->next;
      }
      }
      return head;
}