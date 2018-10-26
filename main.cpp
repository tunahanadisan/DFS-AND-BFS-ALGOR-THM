#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
using namespace std;

struct node * createNode(int item);
void delQueue();
int isEmpty();
void findBFS(int root);
void findDFS(int root, bool visited[]);
void readFile();

int data[6][6];
bool visited[6];

struct node{
	int data;
	struct node *next;
};

struct node *front =NULL;
struct node *rear =NULL;
int start;
int main(){
	int key;
		while(key!=3){
		readFile();
		cout<<"1:DFS(Depth First Search)"<<endl;
		cout<<"2:BFS(Breadth First Search)"<<endl;
		cin>>key;
		if(key==1){
			cout<<"Please Enter start traversing : ";
			cin>>start;	
			findBFS(start);
			system("pause");
			system("cls");
			return main();
		}
		else if(key==2){
			cout<<"Please Enter start traversing : ";
			cin>>start;	
			cout<<endl;
			for(int i=0;i<6;i++){
				visited[i]=false;
			}
			findDFS(start,visited);
			system("pause");
			system("cls");
			return main();
		}
		else if(key==3){
			return 0;
		}
		else{
			system("pause");
			system("cls");
			return main();
		}
	}
}
void readFile(){
	int i= 0;
	FILE * FP =fopen("file.txt","r");
	if(FP==NULL){//dosya yoksa buraya girecek
	 printf("FILE NOT FOUND");
	}
	
	while(fscanf(FP,"%d %d %d %d %d %d",&data[i][0],&data[i][1],&data[i][2],&data[i][3],&data[i][4],&data[i][5]) !=EOF){
		i++;
	}
	fclose(FP);
}

struct node * createNode(int item){
	struct node* temp = (struct node *)malloc(sizeof(struct node));
	temp->next = NULL;
	temp->data = item;
	return temp;
}
void addQueue(int item){
	struct node* newnode = createNode(item);
	if(front == NULL){
		front = newnode;
		rear = newnode;
	}
	else{
		rear->next=newnode;
		rear=newnode;
	}
}
void delQueue(){
	if(front == NULL){
		return;
	}
	
	if(front->next == NULL){
		front = NULL;
		rear = NULL;	
	}
	else{
		struct node * temp = front->next;
		free(front);
		front = temp;
	}
}
int isEmpty(){
	if(front ==NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void findBFS(int root){
	for(int i=0;i<6;i++){//baþlangýcta bütün hepsini false yapýyoruz
		visited[i]=false;
	}
	visited[root] = true;
	addQueue(root);
	while(!isEmpty()){
		root=front->data;
		printf("%d ",root);
		delQueue();
		for(int i=0;i<6;i++){
			if(visited[i] == false && data[root][i]==1){
					visited[i]=true;
					addQueue(i);
			}
		}
	}	
}

void findDFS(int root, bool visited[])
{
    int i;
    visited[root] = true;
    printf("%d ", root);
    for( i = 0; i < 6; i++)
    {
        if(data[root][i] == 1 && visited[i] == false)
        {
            findDFS(i, visited);
        }
    }
}
