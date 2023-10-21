#include <iostream>
using namespace std;

struct node {
    int key;
    struct node* next;
};
int hash(int key,int size) 
{
	return key % size;
}

void insert(int key,int size,struct node **&t_head) {
    int index = hash(key,size);
    struct node* newNode = new struct node;
    newNode->key = key;
    newNode->next = NULL;
    if (t_head[index] == NULL) {
        t_head[index] = newNode;
    } else {
        node* curr = t_head[index];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

int search(int key,int size,struct node **&t_head) {
    int index = hash(key,size);
    int count = 0;
    node* curr = t_head[index];
    while (curr != NULL) {
        count++;
        if (curr->key == key) {
            return count; // Successful search
        }
        curr = curr->next;
    }
    return -count; // Unsuccessful search
}

int main() {
    int tableSize, n, key;
    cout << "Enter the size of the hash table: ";
    cin >> tableSize;
    struct node **t_head=new struct node*[tableSize];
        for (int i = 0; i < tableSize; i++) {
            t_head[i] = NULL;
        }

    cout << "Enter the number of keys to insert: ";
    cin >> n;

    cout << "Enter the keys: ";
    for (int i = 0; i < n; i++) {
        cin >> key;
        insert(key,tableSize,t_head);
    }
    
    for (int i = 0; i < tableSize; ++i)
	{
        node *temp = *(t_head + i);
        cout << i << "-->\t";
        if(temp==NULL)
        {
        	cout<<endl;
		}
		else
		{
			while (temp->next!=NULL) 
		{
            cout<<temp->key<<" ";
            temp=temp->next;
        }
        cout<<temp->key;
        cout<<endl;
		}
        
    }
    
    cout << "Enter the key to search: ";
    cin >> key;

    int comparisons = search(key,tableSize,t_head);
    if (comparisons > 0) {
        cout << "Key found after " << comparisons << " comparisons." << endl;
    } else {
        cout << "Key not found after " << -comparisons << " comparisons." << endl;
    }

    return 0;
}

