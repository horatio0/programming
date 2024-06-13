#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Waiting {
    int id;
    int nperson;
    char info[32];
}Element;
#include "DblLinkedList.h"

void reserve(int nperson, const char info[])
{
    static int id = 0;
    Element e;
    e.id = ++id;
    e.nperson = nperson;
    strcpy_s(e.info, 32, info);
    insert(size(), e);
    printf("<등록> 번호 %d: 인원 %d명 %s\n", e.id, e.nperson, e.info);
}

void find(int wid)
{
    int nTeam = 0, nPeople = 0;
    for (int pos = 0; pos < size(); pos++) {
        Element e = get_entry(pos);
        if (e.id == wid) {
            printf("<확인> 번호 %d번 앞 대기팀: %d팀 %d명\n", wid, nTeam, nPeople);
            return;
        }
        nTeam += 1;
        nPeople += e.nperson;
    }
}

void cancel(int wid)
{
    for (int pos = 0; pos < size(); pos++) {
        Element e = get_entry(pos);
        if (e.id == wid) {
            del(pos);
            printf("<취소> %d번 웨이팅이 취소되었습니다.\n", wid);
            return;
        }
    }
}

void delay(int wid)
{
    for (int pos = 0; pos < size() - 1; pos++) {
        Element e = get_entry(pos);
        if (e.id == wid) {
            del(pos);
            insert(pos + 1, e);
            printf("<연기> %d번 웨이팅이 한 칸 연기되었습니다.\n", wid);
            return;
        }
    }
}

void print()
{
    printf("<출력>\n");
    for (int pos = 0; pos < size(); pos++) {
        Element e = get_entry(pos);
        printf(" 번호: %2d: %d명 %s\n", e.id, e.nperson, e.info);
    }
    printf("\n");
}

void service()
{
    Element e = del(0);
    printf("<입장> %d번 손님 입장 (%d명, %s)\n", e.id, e.nperson, e.info);
}

int main(void)
{
    init_list();
    print();
    reserve(2, "010-xxxx-8762");
    reserve(2, "010-xxxx-3303");
    reserve(5, "010-xxxx-1212");
    reserve(1, "010-xxxx-2305");
    print();

    service();
    print();

    reserve(3, "010-xxxx-4949");
    reserve(4, "010-xxxx-7345");
    print();

    find(4);
    delay(3);
    delay(3);
    print();
    cancel(5);
    print();

    destroy_list();
}


#ifdef XXX

void modify()
{
    int	wid;
    printf("�����Ͻ� ������ ��ȣ�� �Է��ϼ���: ");
    scanf_s("%d", &wid);

    for (int pos = 0; pos < size() - 1; pos++) {
        Element e = get_entry(pos);
        if (e.id == wid) {
            printf("����ȣ %2d: %d�� %s\n", e.id, e.nperson, e.info);
            printf("�ο��� ��ȭ��ȣ�� �ٽ� �Է��ϼ���: ");
            scanf_s("%d%s", &e.nperson, e.info, 32);
            replace(pos, e);
            printf("%d�� �������� �����Ǿ����ϴ�.\n", wid);
            return;
        }
    }
}
#endif
