#include<iostream>
#include<stdio.h>  
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct node
{
	struct node *previous;
	int data;
	struct node *next;
}*head, *last;

void insert_begning(int value)
{	struct node *var,*temp;
	var=new node;
	var->data=value;
	if(head==NULL)
	  {
	head=var;
head->previous=NULL;
head->next=NULL;
last=head;
  }
else  	  {
temp=var;
temp->previous=NULL;
temp->next=head;
head->previous=temp;
head=temp;
	  }}

void insert_end(int value)
{
struct node *var,*temp;
var=new node;
var->data=value;
if(head==NULL)
	  {
head=var;
head->previous=NULL;
head->next=NULL;
last=head;
	  }
else
	  {
last=head;
while(last!=NULL)
{
temp=last;
last=last->next;
}
last=var;
temp->next=last;
last->previous=temp;
last->next=NULL;
}
}
int insert_after(int value, int loc)
{
struct node *temp,*var,*temp1;
var=new node;
var->data=value;
if(head==NULL)
	  {
head=var;
head->previous=NULL;
head->next=NULL;
	  }
else
	  {
temp=head;
while(temp!=NULL && temp->data!=loc)
  {
temp=temp->next;
  }
if(temp==NULL)
{
cout<<"\n is not present in list "<<loc;
	  }
else
{
temp1=temp->next;
temp->next=var;
var->previous=temp;
var->next=temp1;
temp1->previous=var;
  }
	  }
last=head;
while(last->next!=NULL)
  {
last=last->next;
}
return 0;
}
int delete_from_end()
{
struct node *temp;
temp=last;
if(temp->previous==NULL)
{
delete temp;
head=NULL;
last=NULL;
return 0;
}
cout<<"\nData deleted from list is \n"<<last->data;
last=temp->previous;
last->next=NULL;
delete temp;
return 0;
}
int delete_from_start()
{
struct node *temp;
if(head==NULL)
cout<<"empty list";
else
{
temp=head;
head=head->next;
head->previous=NULL;
delete temp;

return 0;
  }
cout<<"\nData deleted from list is \n"<<last->data;
last=temp->previous;
last->next=NULL;
delete temp;
return 0;
}
int delete_from_middle(int value)
{
struct node *temp,*var,*t, *temp1;
temp=head;
while(temp!=NULL)
{
if(temp->data == value)
{
if(temp->previous==NULL)
{
free(temp);
head=NULL;
last=NULL;
return 0;
}
else
{
	var->next=temp1;
	temp1->previous=var;
delete temp;
return 0;
}
  }
else
{
var=temp;
temp=temp->next;
  temp1=temp->next;
  } }
cout<<"data deleted from list is   "<<value;
}
void display()
{
struct node *temp;
temp=head;
if(temp==NULL)
{
cout<<"List is Empty";
}
while(temp!=NULL)
 {
cout<<temp->data;
temp=temp->next;
}}
int main()
{
int value, i, loc;
head=NULL;
cout<<"\n\nSelect the choice of operation on link list"
<<"\n1.) insert at begning"
<<"\n2.)insert at the end"
<<"\n3.)insert at middle"
<<"\n4.)delete from end"
<<"\n5.)delete from start"
<<"\n6.)delete in the middle"
<<"\n7.)display list"
<<"\n8.)exit";
while(1)
 {
cout<<"\n\nenter the choice of operation you want to do ";
cin>>i;
switch(i)
{
case 1:
					 {
cout<<"enter the value you want to insert in node ";
					cin>>value;
					insert_begning(value);
					display();
break;
	  }
case 2:
{
					cout<<"enter the value "
<<"you want to insert in node at last ";
	cin>>value;
					insert_end(value);
					display();
					break;
					  }
					case 3:
					  {
					cout<<"after which data you want to insert data ";
					cin>>loc;
					cout<<"enter the data you want to insert in list ";
					cin>>value;
					insert_after(value,loc);
					display();
					break;
					  }
					case 4:
					  {
					delete_from_end();
					display();
					break;
					  }
case 5:
  {
					delete_from_start();
					display();
break;
  }
case 6:
{
					cout<<"enter the value you want to delete";
					cin>>value;
					delete_from_middle(value);
					display();
break;
	  }
case 7 :
		{
					display();
break;
			  }
case 8 :
		  {
							exit(0);
							break;
			  }
			 }
cout<<"\n\nSelect the choice of operation on link list";
	cout<<"\n1.) insert at begning";
    cout<<"\n2.) insert at end";
    cout<<"\n3.) insert at middle";
	cout<<"\n4.) delete from end";
	cout<<"\n5.) delete from end";
	cout<<"\n6.) delete in the middle";
	cout<<"\n7.) display list";
	cout<<"\n8.)exit";

	 }
	cout<<last->data;
	display();
	getch();
}
