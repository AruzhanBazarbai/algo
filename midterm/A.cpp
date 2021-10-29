// #include <iostream>
// using namespace std;
// // 
// class Node{
//     public:
//     Node * next, * prev;
//     Node(int a[],int sz){
//         int arr[sz]=a;
//         this->next=NULL;
//         this->prev=NULL;
//     }
// };

// class LinkedList{
//     public:
//     Node * head, * tail;
//     LinkedList(){
//         this->head=NULL;
//         this->tail=NULL;
//     }
//     void add(int m,int d,int y){
//         Node * node = new Node(m,d,y);
//         if(head == NULL){
//             head = tail = node;
//         }else{
//             tail->next=node;
//             node->prev=tail;
//             tail=node;

//         }
//     }
//     void sort(){
//         Node * temp=head;
//         Node * cur=head;
//         while(cur!=NULL){
//             temp=cur->next;
//             while(temp!=NULL){
//                 if((cur->y > temp->y) || (cur->y==temp->y && cur->m < temp->m) || (cur->y==temp->y && cur->m == temp->m && cur->d < temp->d)){
//                     int x1=cur->d,x2=cur->m,x3=cur->y;
//                     cur->d=temp->d;
//                     cur->m=temp->m;
//                     cur->y=temp->y;
//                     temp->d=x1;
//                     temp->m=x2;
//                     temp->y=x3;
//                 }
//                 temp=temp->next;
//             }
//             cur=cur->next;
//         }

//     }


//     void print(){
//         Node * temp = head;
//         while(temp != NULL){
//             cout << temp->m << " " << temp->d << " " << temp->y << endl;
//             temp = temp->next;
//         }
//     }

// };

// int main(){
//     LinkedList * ll=new LinkedList();
//     string s,d,m,y;
    
    
//     int n,m;
//     cin >> n >> m;
//     while(n--){
//         int d1=0,m1=0,y1=0;
//         cin >> m >> d >> y;
//         for(char x:d){
//             d1=d1*10+((int)x-'0');
//         }
//         for(char x:m){
//             m1=m1*10+((int)x-'0');
//         }
//         for(char x:y){
//             y1=y1*10+((int)x-'0');
//         }
//         ll->add(m1,d1,y1);
//     }
//     ll->sort();
//     ll->print();

//     return 0;
// }