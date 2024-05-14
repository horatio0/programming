typedef struct Node{
    Element data;
    struct Node *link;
} Node;
Node *top=NULL;

char Underflow[16] = "Underflow Error";

Node* alloc_node(Element e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->link = NULL;
    return p;
}

Element free_node(Node *p){
    Element e = p->data;
    free(p);
    return e;
}

void error(char *str){
    printf("%s\n", str);
    exit(1);
}

int is_empty() {return top == NULL;}
int is_full() {return 0;}
void init_stack() {top=NULL;}

void push(Element e){
    Node *p = alloc_node(e);
    p->link = top;
    top = p;
}

Element pop(){
    if(is_empty()) error(Underflow);
    Node *p = top;
    top = p->link;
    return free_node(p);
}

Element peek(){
    if(is_empty()) error(Underflow);
    return top->data;
}

void destroy_stack(){
    while(is_empty()==0) pop();
}