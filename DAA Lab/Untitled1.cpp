#include <iostream>
using namespace std;
//struct Node
//{
//    int val;
//    Node* nxt{nullptr};
//};
//
//
//struct LinkedList
//{
//    Node* head{nullptr};
//};
//
//    void insertAtBack(LinkedList* ll, int value)
//    {
//        if (!ll->head)
//        {
//            head = new Node(value);
//        }
//        else
//        {
//            Node* current = head;
//            while(current->next != nullptr)
//            { 
//                current = current->next;
//            }
//            //current is the last node whose next is null
//            current->next = new
//        }
//    }
//    
//    void insertAtFront (LinkedList* ll, int value)
//    {
//    	Node * current = new Node(value);
//    	current->next = head;
//    	head = current;
//    	
//	}
//	
//int main(){
//	int x[3] = {2,3,4};
//	int *y=x;
//	int *z=&x[1];
//	int *p=&x[2];
//	cout<<y<<"\n";
//	cout<<z<<"\n";
//	cout<<p<<"\n";
//	cout<<sizeof(y);
//void doubleIt(int x, int * p)
//{
//*p = 2 * x;
//}
//int main()
//{
//int a = 16;
//doubleIt(9, a);
//return 0;
//}
//}
int sum(int size,int *base);
int main(){
 int a[5]={3,4,6,1,2};
 cout<<sum(5,a);
	
}
int sum(int size,int *base){
	int s=0;
	for(int i = 0 ;i<size;i++){
 	   s=s+ *(base+i);
    }
	return s;
}
//void swap(int *a,int*b){
//	int temp;
//	temp=*a;
//	*a=*b;
//	*b=temp;
//}
//void sum(
//}
