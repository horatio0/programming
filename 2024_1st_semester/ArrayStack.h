EforC data_c[Max_Size];
EforD data_d[Max_Size];
int tfd, tfc;
const char *underflow = "UnderFlow Error!";
const char *overflow = "OverFlow Error!";

void error(const char *str){
    printf("%s\n", str);
    exit(1);
}

void init_stack_c(){
    tfc = -1;
}

void init_stack_d(){
    tfd = -1;
}

int is_c_empty(){
    if(tfc==-1) return 1;
    else return 0;
}

int is_d_empty(){
    if(tfd==-1) return 1;
    else return 0;
}

int is_c_full(){
    if (tfc==Max_Size-1) return 1;
    else return 0;
}

int is_d_full(){
    if (tfd==Max_Size-1) return 1;
    else return 0;
}

void push_c(EforC e){
    if(is_c_full()) error(overflow);
    data_c[++tfc] = e;
}

void push_d(EforD e){
    if(is_d_full()) error(overflow);
    data_d[++tfd] = e;
}

EforC pop_c(){
    if(is_c_empty()) error(underflow);
    return data_c[tfc--];
}

EforC peek_c(){
    if(is_c_empty()) error(underflow);
    return data_c[tfc];
}

EforD pop_d(){
    if(is_d_empty()) error(underflow);
    return data_d[tfd--];
}

EforD peek_d(){
    if(is_d_empty()) error(underflow);
    return data_d[tfd];
}