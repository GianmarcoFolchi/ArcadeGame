#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node; 
typedef struct Stack Stack;

//define the structs and the functions
Stack * createStack();
Node * createNode(char *name, int money); 
void pop(Stack * stack);
void push(Stack * stack, Node * node);
//void printStack(Stack * stack); 

struct Node {
    char * name; 
    int money; 
    Node *next; 
};

struct Stack {
    Node * head;     
};

int main() {
    int t, money; 
    char name[25]; 
    Stack * stack = createStack(); //create the stack for all of the nodes to go in 

    while (t != 0 ) {        
        scanf("%d", &t); //read in t for this specific line of input 
        if (t == 1) { // if t = 1, read in the name and the money and create an object of node with that information
            scanf(" %d", &money); 
            scanf(" %s", name); 
            Node * node = createNode(name, money); 

            if (stack->head == NULL) { //node will be the first element of the list so push into the list
                push(stack, node); 

            } else if (node->money >= stack->head->money) { //we just scanned in a new mvp so push into the list
                push(stack, node); 

            } else if (node->money < stack->head->money) { //the new node is not the new mvp, therefore just duplicate the mvp in the stack
                Node * ret; 
                ret->money = stack->head->money; 
                strcpy(ret->name, stack->head->name); 
                ret->next = NULL; 
                push(stack, ret);
            }

        } else if (t == 2) { //process a player leaving 
            pop(stack); 

        } else if (t == 3) { //print the mvp of the current stack. Which is also the head of the stack
            printf("the mvp is %s \n", stack->head->name); 
          //printStack(stack); 
        }
    }
    //if 0 is scanned in, break out of the while loop and print 
    printf("the program is finished"); 
    return 0; 
}

Stack * createStack() { //create the space for the stack and return the stack 
    Stack * ret = calloc(1, sizeof(Stack));
    ret->head = NULL; 
    return ret; 
}

Node * createNode(char * name, int money) { // allocate space for the node and also the name, allocate the values, and return the node
    Node * node = calloc(1, sizeof(Node));
    node->name = calloc(25, sizeof(char)); 
    node->money = money; 
    strcpy(node->name, name); 
    node->next = NULL;     
    return node; 
}

void pop(Stack * stack) { // remove the head, if head == NULL just return. Otherwise, remove old head. 
    if (stack->head == NULL) {
        return; 
    }
    Node * oldHead = stack->head; 
    stack->head = oldHead->next; 
}

void push(Stack * stack, Node * node) { // pass in a new head and make that the head of the stack
    node->next = stack->head; 
    stack->head = node;
}

// void printStack(Stack * stack) {
//     Node * curr = stack->head; 
//     int i = 0; 
//     while (curr != NULL) {
//         printf("the %dth element's name = %s, and money = %d\n ", i, curr->name, curr->money); 
//         curr = curr->next; 
//         i++; 
//     }
// }
