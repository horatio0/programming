Element data[Max_Size];
int top;
const char *underflow = "UnderFlow Error!";
const char *overflow = "OverFlow Error!";

void error(const char *str){
    printf("%s\n", str);
    exit(1);
}

void init_stack(){
    top = -1;
}

int is_empty(){
    if(top==-1) return 1;
    else return 0;
}

int is_full(){
    if (top==Max_Size-1) return 1;
    else return 0;
}

void push(Element e){
    if(is_full()) error(overflow);
    data[++top] = e;
}

Element pop(){
    if(is_empty()) error(underflow);
    return data[top--];
}

Element peek(){
    if(is_empty()) error(underflow);
    return data[top];
}