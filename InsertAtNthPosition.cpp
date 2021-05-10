#include<bits/stdc++.h>

struct Node{
  int data;
  struct Node *next;
};
struct Node* head;
//Inserting data at nth position(Middle of the LinkedList)
void Insert(int data, int n){
  Node* temp1 = new Node();  //Node* temp = (Node*)malloc(sizeof(struct Node));
  temp1->data = data; // (*temp).data = x;
  temp1->next = NULL;
  if(n == 1){  //Inserting in the beginning of the list(at head)
    temp1->next = head;
    head = temp1;
    return;
  }

  Node* temp2 = head;
  for(int i=0;i<n-2;i++){ //Traverse till n-2 th position
    temp2 = temp2->next; //Now it's at n-1 th position
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}

void Print(){
  Node* temp = head;
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main(){
  head = NULL;  //empty list
  Insert(2,1); //List: 2
  Insert(3,2); //List: 2, 3
  Insert(4,1); //List: 4,2,3
  Insert(5,2); //List: 4,5,2,3
  Print();
}
