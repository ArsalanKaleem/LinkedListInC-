#include<iostream>
#include<cstring>
#include <cstdlib> 
using namespace std;
struct student{
	char firstname[50];
	char lastname[50];
	int age;
	int id;
};
struct node{
	student data;
	node*next;
};

node*head=NULL;

void addRecord(){
	node* nodedata=new node;
	cout<<"Enter first name:";
	cin>>nodedata->data.firstname;
	cout<<"Enter Last Name:";
	cin>>nodedata->data.lastname;
	cout<<"Enter Age:";
	cin>>nodedata->data.age;
	cout<<"enter Unique ID:";
	cin>>nodedata->data.id;
	nodedata->next=NULL;
	
	if(head==NULL){
		head=nodedata;
	}else{
		node*temp=head;
		while(temp->next!= NULL){
			temp=temp->next;
		}
		temp->next=nodedata;
	}
	cout<<"record added successfully."<<endl;
}

void searchrecord(){
	
	if(head==NULL){
		cout<<"No record Found.";
		return;
	}
	int identity;
	cout<<"Enter ID To Search:";
	cin>>identity;
	node*temp=head;
	bool found=false;
	while(temp!=NULL){
	if(identity==temp->data.id){
		cout<<"record found."<<endl;
		cout<<"First Name:"<<temp->data.firstname<<endl;
		cout<<"Last Name:"<<temp->data.lastname<<endl;
		cout<<"Age:"<<temp->data.age<<endl;
		found = true;
		break;
	}
	temp=temp->next;
}
	if(!found){
		cout<<"Record Not Found."<<endl;
	}
}
void modifyRecord(){
	if(head==NULL){
		cout<<"No Record Found To Modify."<<endl;
	}
	int identity;
	cout<<"Enter Unique ID to Modify Previously Added Record:";
	cin>>identity;
	
	node*temp=head;
	bool found = false;
	while(temp!=NULL){
	if(identity==temp->data.id){
		cout<<"Enter New First Name:";
		cin>>temp->data.firstname;
		cout<<"Enter New Last Name:";
		cin>>temp->data.lastname;
		cout<<"Enter New Age:";
		cin>>temp->data.age;
		cout<<"Enter New Unique ID";
		cin>>temp->data.id;
		cout<<"Record Updated Successfully";
		found=true;
		break;
	}
	temp=temp->next;
}
	if(!found){
		cout<<"No Record Found To Modify."<<endl;
	}
}
void deleteRecord(){
	if(head==NULL){
		cout<<"No Previously Added Record!!!"<<endl;
		return;
	}
	int identity;
	cout<<"Enter Unique Identity Of Record To delete:";
	cin>>identity;
	node*temp=head;
	node*prev=NULL;
	bool found = false;
	while(temp!=NULL){
		if(identity==temp->data.id){
			if(prev==NULL){
				head=temp->next;
			}else{
				prev->next==temp->next;
			}
			delete temp;
			cout<<"Record Deleted Successfully"<<endl;
			found=true;
			break;
		}
		prev=temp;
		temp=temp->next;
	}
	if(!found){
		cout<<"Record Not Found"<<endl;
	}
}
void ExitFunction(){
	std::cout << "Exiting the program";
    exit(0);
}
int main(){
	int choice;
	do{
		cout<<"----Enter Choice!!----"<<endl;
		cout<<"1:Click 1 For Adding Record"<<endl;
		cout<<"2:Click 2 For Searching Record"<<endl;
		cout<<"3:Click 3 For Modifying Record"<<endl;
		cout<<"4:Click 4 to Delete Record"<<endl;
		cout<<"5:Click 5 to Exit"<<endl;
		cin>>choice;
		
		switch(choice){
			case 1:
				addRecord();
				break;
			case 2:	
				searchrecord();
				break;
			case 3:
				modifyRecord();	
			case 4:
				deleteRecord();	
			case 5:
				ExitFunction();
			default:
			cout<<"wrong choice";	
		}
	}while(choice!=5);
}
