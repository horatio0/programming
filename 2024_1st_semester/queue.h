Element data[MAX_SIZE];
int front, rear;

void error(const char *str){
    printf("%s\n", str);
    exit(1);
}

void init_queue(){
    front = rear = 0;
}

int is_empty(){
    return (front==rear);
}

int is_full(){
    return (front == (rear+1) % MAX_SIZE);
}

void enqueue(Element e){
    if(is_full()) error("Overflow Error!");
    rear = (rear+1) % MAX_SIZE;
    data[rear]=e;
}

Element dequeue(){
    if (is_empty()) error("Underflow Error");
    front = (front + 1) % MAX_SIZE;
    return data[front];
}

Element peek(){
    if (is_empty()) error("Underflow Error");
    return data[(front + 1) % MAX_SIZE];
}