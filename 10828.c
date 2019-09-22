#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 10001

int top = -1;
int stack[MAX_STACK_SIZE];

void pop();
void push(int item);
int isEmpty();
int isFull();
void Top();
void size();

int main(void) {
    int input, i;
    char command[10];
    int num;
    char c;

    scanf("%d ", &input);
    
    for(i = 0; i < input; i++){
        scanf("%s", command);
        scanf("%c", &c);
        
        
        if(strcmp(command, "push") == 0){
          scanf("%d", &num);
          push(num);
        }
        else if(strcmp(command, "top") == 0)
          Top();

        else if(strcmp(command, "size") == 0)
          size();
        else if(strcmp(command, "empty") == 0)
          printf("%d\n", isEmpty());
        else if(strcmp(command, "pop") == 0)
          pop();
    }

    return 0;
}


void size(){
    printf("%d\n", top + 1);
}

void Top(){
    if(isEmpty())
	    printf("-1\n");
	else 
	    printf("%d\n", stack[top]);
}

int isFull() {
	if (top == MAX_STACK_SIZE - 1)
	    return 1;
	else
	    return 0;
}

int isEmpty(){
	if (top == -1)
	    return 1;
	else
	    return 0;
}

void push(int item){
	if(isFull()) return; //stack 가득 찼을 때
	else
	    stack[++top] = item;
}

void pop(){
	if(isEmpty())
	    printf("-1\n");
	else 
	    printf("%d\n", stack[top--]);
}