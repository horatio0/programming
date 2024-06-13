char *invalid="Invalid Position Error!";
char *underflow="Underflow Error!";

typedef struct Node {   // �ڱ����� ����ü
    Element data;       // ������ �ʵ�(���� ���)
    struct Node* link;  // ��ũ �ʵ�
} Node;

Node* head = NULL;

// �ܼ� ���� ���� ����� ���� �Ҵ� �Լ�(�ڵ� 5.3�� ����)
Node* alloc_node(Element e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;        // ������ �ʱ�ȭ
    p->link = NULL;     // ��ũ �ʱ�ȭ
    return p;
}
// �ܼ� ���� ���� ����� ������ ��ȯ �� ���� ���� �Լ�(�ڵ� 5.3�� ����)
Element free_node(Node* p)
{
    Element e = p->data;// ������ ����
    free(p);            // ���� ����
    return e;           // ������ ��ȯ
}

void error(char* str)
{
    printf("%s\n", str);
    exit(1);
}

// ����Ʈ�� �����
int is_empty() { return head == NULL; }
int is_full() { return 0; }
void init_list() { head = NULL; }
// ����Ʈ ��� ���� �Լ�(���, ������)
Node* get_node(int pos)
{
    if (pos < 0) return NULL;
    Node* p = head;
    for (int i = 0; i < pos; i++, p = p->link)
        if (p == NULL) return NULL;
    return p;
}
Element get_entry(int pos)
{
    Node* p = get_node(pos);
    if (p == NULL)
        error("Invalid Position Error!");
    return p->data;
}
// ����Ʈ�� ���� ����
void insert(int pos, Element e)
{
    Node* p = alloc_node(e); // ������ ��� ���� �� �ʱ�ȭ
    if (pos == 0) {
        p->link = head;
        head = p;
    }
    else {
        Node* before = get_node(pos - 1);
        if (before == NULL)
            error(invalid);
        p->link = before->link;
        before->link = p;
    }
}
// ����Ʈ�� ���� ����
Element del(int pos)
{
    if (is_empty())
        error(underflow);
    Node* p = get_node(pos);            // ������ ���
    if (p == NULL)
        error(invalid);
    Node* before = get_node(pos - 1);   // ���� ���
    if (before == NULL)                 // �� �� ��� ����
        head = head->link;
    else
        before->link = p->link;
    return free_node(p);
}
// ����Ʈ�� ��� ��� ����(���� ����)
void destroy_list()
{
    while (is_empty() == 0) del(0);
}
int size()
{
    int count = 0;
    for (Node* p = head; p != NULL; p = p->link) count++;
    return count;
}


//--------------------------------------------------------------------
// �ڵ� 6.6 ���� ����Ʈ�� �߰� ����

void append(Element e)
{
    insert(size(), e);
}
Element pop()
{
    return del(size() - 1);
}
void replace(int pos, Element e)
{
    Node* p = get_node(pos);
    if (p == NULL)
        error(invalid);
    p->data = e;
}
int find(Element e)
{
    int i = 0;
    for (Node* p = head; p != NULL; p = p->link, i++)
        if (p->data == e) return i;
    return -1;
}
//--------------------------------------------------------------------
