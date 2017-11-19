#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node 
{
	int data;
	struct node *next;
}node;
void create(node ** head,int n)
{
	node *temp;
	if(*head == NULL) {
		temp = (node *)malloc(sizeof(node));
		temp->data = n;
		*head = temp;
		(*head)->next  = NULL;
	}else {
		create((&(*head)->next),n);
	}
}
void print(node *head) 
{
	while(head != NULL) {
		cout << head->data << "-->";
		head = head->next;
	}
}
static void reverse(node **head)
{
	int count  = -1;
	node *next;
	node *temp = *head;
	node *prev = NULL;
	count++;
	while(temp->next != NULL) {
		next = (temp)->next;
		//cout << "next is "  << next->data << endl;
		(temp)->next = prev;
		prev = (temp);
		//cout << "prev is " << prev->data <<endl;
		temp = next;
		//cout << "new temp is " << temp->data << endl;
	}
	temp->next = prev;
	*head = temp;
	//cout << "head value is " << (*head)->data << endl;
}
int main()
{
	node *head = NULL;
	while(1) {
		//create(&head,n);
		int n;
		cin >> n;
		if(n == 999) {
			break;
		}else {
			create(&head,n);
		}
	}
	print(head);
	reverse(&head);
	print(head);
	return 0;
}


