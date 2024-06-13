typedef struct DNode {
    Element data;
    struct DNode* prev;
    struct DNode* next;
} DNode;
char *invalid="Invalid Position Error!";
DNode org;
DNode* alloc_dnode(Element e)
{
    DNode* p = (DNode*)malloc(sizeof(DNode));
    p->data = e;
    p->prev = NULL;
    p->next = NULL;
    return p;
}
Element free_dnode(DNode* p)
{
    Element e = p->data;
    free(p);
    return e;
}
void error(char* str)
{
    printf("%s\n", str);
    exit(1);
}

int is_empty() { return org.next == NULL; }
int is_full() { return 0; }
void init_list() { org.next = NULL; }

DNode* get_node(int pos)
{
    DNode* p = &org;
    for (int i = 0; i <= pos; i++, p = p->next)
        if (p == NULL)
            return NULL;
    return p;
}
Element get_entry(int pos)
{
    DNode* p = get_node(pos);
    if (pos < 0 || p == NULL)
        error(invalid);
    return p->data;
}

void insert(int pos, Element e)
{
    DNode* before = get_node(pos - 1);
    if (before == NULL) error(invalid);
    if(pos==0){
        DNode* p = alloc_dnode(e);
        p->next = before->next;
        p->prev = before;
        before->next = p;
        if (p->next != NULL) p->next->prev = p;
    } else {
        for(int i=0;i<pos;i++){
            if(before->data.nperson<=e.nperson){
                before=before->prev;
            }
        }
        DNode* p = alloc_dnode(e);
        p->next = before->next;
        p->prev = before;
        before->next = p;
        if (p->next != NULL) p->next->prev = p;
    }
    
}

Element del(int pos)
{
    DNode* p = get_node(pos);
    if (pos < 0 || p == NULL)
        error(invalid);
    p->prev->next = p->next;
    if (p->next != NULL)
        p->next->prev = p->prev;
    return free_dnode(p);
}
void destroy_list() { while (is_empty() == 0) del(0); }
int size()
{
    int count = 0;
    for (DNode* p = org.next; p != NULL; p = p->next)
        count++;
    return count;
}



#ifdef XXX
// ����Ʈ�� ��ü ����
void replace(int pos, Element e)
{
    DNode* p = get_node(pos);	// ������ ���
    if (p == NULL)
        error("Invalid Position Error!");
    p->data = e;
}

// ����Ʈ�� Ž�� ����(���� Ž��)
int find(Element e)
{
    int i = 0;
    for (DNode* p = head(); p != NULL; p = p->next, i++)
        if (p->data == e) return i;
    return -1;
}
#endif
