#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node{
	int val;
	struct node *llink, *rlink;
};

typedef struct node *NODE;

NODE head = NULL;

void CreateList(int val){
	NODE nd;
	if (head == NULL){
		nd = (NODE)malloc(sizeof(struct node));
		nd->llink = nd->rlink = NULL;
		nd->val=val;
		head=nd;
	}
	else{
		cout<<"List is already created!";
	}
}

void insertIntoList(int before , int val){
	NODE nd, newnd;
	nd=head;
	while(nd!=NULL && nd->val!=before){
		nd=nd->rlink;
	}
	if(nd!=NULL){
		newnd=(NODE)malloc(sizeof(struct node));
		newnd->llink = newnd->rlink = NULL;
		newnd->val=val;
		if(nd->llink!=NULL){
			nd->llink->rlink=newnd;
			newnd->llink=newnd->rlink = NULL;
			newnd->val=val;
			nd->llink=newnd;
		}
		else{
			newnd->rlink=nd;
			nd->llink=newnd;
			head=newnd;
		}
	}
	else{
		cout<<"Unable to insert, node with value %d not found"<<val;
	}
}

void deleteAll(int delVal){
	NODE nd, nxtNode;
	nd=head;
	while(nd!=NULL){
		if(nd->val==delVal){
			if(nd->llink!=NULL){
				nd->llink->rlink=nd->rlink;
				if(nd->rlink!=NULL){
					nd->rlink->llink=nd->llink;
					nxtNode=nd->rlink;
					free(nd);
					nd=nxtNode;
				}
				else{
					nd->llink->rlink=NULL;
					free(nd);
					nd=NULL;
			    }
			}
			else{
				if(nd->rlink!=NULL){
					nd ->rlink->llink = NULL;
                    head = nd->rlink;
                    free(nd);
                    nd = head;	
				}
				else{
					free(nd);
                    head = nd = NULL;	
				}
			}
		}
		else{
			nd = nd->rlink;
		}
	}
}

void searchNode(int searchVal){
    NODE nd;
    nd=head;
    while (nd != NULL) {
        if (nd->val == searchVal){
        	cout<< "Node is found with key %d\n" <<searchVal;
		}
	    nd = nd->rlink;
    }
}

void displayAll(){
	NODE nd;
	nd = head;
	while (nd != NULL) {
	    cout<<"Node with val %d\n"<, nd->val;
		nd = nd->rlink;
	}
}

void main(){
    int choice, val,before;d
	do {
	    cout<<"1. Create List\n";
		cout<<"2. Insert into List\n";
	    cout<<"3. Delete all by value\n";
		cout<<"4. Search by value\n";
		cout<<"5. Display all\n";
		cout<<"6. Exit\n";
		cout<<"Enter your choice :";
		cin>>choice;
		switch(choice) {
		    case 1:
			    cout<<"Please enter the node value";
			    cin>>val;
				CreateList(val);
				break;
			case 2:
			    cout<<"Please enter the node value to insert ";
			    cin>>val;
				cout<<"Please enter the node value before which new node to be inserted ";
				cin>>before;
				insertIntoList(before,val);
				break;
			case 3:
				cout<<"ENter the node value to be deletd:";
				cin>>val;
				deleteAll(val);
				break;
			case 4:
				cout<<"Enter the node value to be searched:";
				cin>>val;
				searchNode(val);
				break;
			case 5:
				displayAll();
				break;
			case 6:
				break;
			default:
				cout<<"Invalid choice";
				break;
		}
	}(while choice!=6);
}
					



