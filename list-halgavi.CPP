#include<iostream.h>
#include<stdio.h>
class node{
friend class list;
int data;
node *next;
};
class list{
node *head;
public:
list();
list(int n);
//~l/ist(); //mokhareb
int addf(int n);
int addl(int n);
int insert(int n,int k);
int removef();
int removel();
int deleten(int k);
int re(int n);
int r(int n);
int print();
};
//****************************************************************
//list::list(){
//head=0;//meghdare be head nemedeh
//}
//****************************************************************
list::list(int n){
head=new node();//node ejad mekoneh
head->data=n;   //meghdare n mezare to data
head->next=head;
}
//****************************************************************
int list::addf(int n){
node *t;
node *p;         //one eshareh ghar az noa node
t=new node();    //t=one node new
if(!t) return 0;
else {
t->data=n;       //meghdar n bezar to data
//t->next=head;    //meghdar head barabar next mezareh
//head=t;



p=head;
while (p->next!=head)
p=p->next;

p->next=t;
t->next=head;
head=t;
         //eshareh ghar meareh aval saf
return 1;
}
}
//***************************************************************
int list::addl(int n){
node *t;
t=new node;
if(!t)
return 0;
else{

node *k=head;
t->data=n;
t->next=head;
if(head==0)
{
head=t;
return 1;
} else{
while(k->next!=head)
k=k->next;

k->next=t;
t->next=head;
return 1;
}
}
}
//***************************************************************
int list::insert(int n,int k){
if (k==1){addf(n);return 1;}

node *h;
h=head;
int c=1;
while (h->next !=head){
h=h->next;
c++;
}

if(k==c+1 ){ addl(n); return 1;}
if(k>c+1||k<1) return -1;


int i=1;
node *f=head;
node *t;
t=new node();
if(!t) return 0;
else{
t->data=n;
if(head==0)
{
head=t;
t->next=head;
return 1;
}else{
while(i<k-1){
f=f->next;
i++;
}
t->next=f->next;
f->next=t;
return 1;
}
}
}
//*****************************************************************
int list::removef(){
int n=head->data;
node *t;
t=head;
while(t->next!=head)
t=t->next;

t->next=head->next;

//head=head->next;
//delete t;
delete head;
head=t->next;
return n;
}
//*****************************************************************
int list::removel(){
node *p,*q;
p=head;
q=head->next;
if(head==0)return -1;
if(head->next==head){
p=head;
int m=head->data;
head=0;
delete p;
return m;
}else{
while(q->next!=head)
     {
      p=p->next;
      q=q->next;
     }
int m=q->data;
p->next=q->next;
delete q;
return m;
}
}
//*****************************************************************
int list::deleten(int k){
if (k==1)return removef();

node *h;
h=head;
int c=1;
while (h->next !=head){
h=h->next;
c++;
}

if(k==c ){ removel(); return 1;}
if(k>c||k<1) return -1;
node *p,*q;
p=head;
q=head->next;
if(head==0)
return 0;
if(head->next==0){
p=head;
int m=head->data;
head=0;
delete p;
return m;
}else{
int i=1;
while(i<k-1){
p=p->next;
q=q->next;
i++;
}
int m=q->data;
p->next=q->next;
delete q;
return m;
}
}
//****************************************************************
int list::re(int n){
int m;
node *p,*q;
if(head->data==n)
   {
    m=head->data;
    head=head->next;
    delete p;
    return m;
   }
p=head;
q=head;
if(head==0) return 0;
if(head->next==0)
  {
   if(p->data==n)
     {
     m=p->data;
     delete p;
     head=0;
     return m;
     }else{
      return -1;
     }
  }

while(1)
     {
     if(p->data==n)
     break;
     else if(p->next==0){
     return -1;
      }else{
       p=p->next;
      }
      }
while(q->next!=p)       q=q->next;
q->next=p->next;
m=p->data;
delete p;
return m;
}
//****************************************************************
int list::r(int n){
int m;
node *p,*q;
node *t;
t=head;
while(t->next!=0)
{
if(head->data==n)
   {
    m=head->data;
    head=head->next;
    delete p;
    cout<<m;
    continue;
   }
p=head;
q=head;
if(head==0) return 0;
if(head->next==0)
  {
   if(p->data==n)
     {
     m=p->data;
     delete p;
     head=0;
     return m;
     }else{
      return -1;
     }
  }

while(1)
     {
     if(p->data==n)
     break;
     else if(p->next==0){
     return -1;
      }else{
       p=p->next;
      }
      }
while(q->next!=p) q=q->next;
q->next=p->next;
m=p->data;
delete p;
cout<<m;
continue;
}
}
///*********//////************************************************
int list ::print(){
int m;
node *p;
p=head;
while(p->next!=head){
cout<<p->data;
p=p->next;
 }
 cout<<p->data;
}

///*********************//////////////////////////////******************
void main(){
list a(3);
a.addl(10);
 a.addl(20);
 a.insert(5,2);
cout<<a.deleten(1);
//cout<<a.r(10);
//a.print();
}
