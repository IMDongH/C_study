#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    char symbol;   // ���ڰ�
    int frequency; // ���Ͽ� �ִ� ������ �󵵼�

    struct nodetype* left;
    struct nodetype* right;
}node;

typedef struct pq   // �켱���� ��⿭
{
    node* Node;         // ��⿭�� �ִ� node
    struct pq* next;   // ���� node
}pq;

#define ROOT    -1 // ��ȣȭ �Լ� ��½� �ʱⰪ

pq* insert(node* r);        // �켱���� ��⿭�� ��带 �����Ͽ� ����
node* huffman(int n);       // ������ �ڵ� Ʈ���� ����� �Լ�
node* Remove();             // �켱 ���� ��⿭���� ��带 ����
void print_PQ();            // �켱 ���� ��⿭ ���
void print_tree(node* r, int n, char* code);    // ��� ������ ��ȣȭ ���
void freetree(node* r);     // �޸� ����

pq* PQ = NULL;      // �켱���� ��⿭
FILE* file;         // ���� �ĺ���

int main()
{
    int n = 1;
    node* result = (node*)malloc(sizeof(node));   // ����� �������� ���
    char* code = (char*)malloc(sizeof(char));

    file = fopen("huffman.txt", "r");  // �Է��� �Ǵ� ���ڿ� �󵵼�
    if (file == NULL) {
        perror("File open error");
        return 0;
    }


    while (1) {
        node* r = (node*)malloc(sizeof(node));
        if ((fscanf(file, "%c:%d ", &r->symbol, &r->frequency)) == -1) {
            break;       // ���Ͽ� �� �̻� ���� ������ while ������
        }
        r->left = NULL;
        r->right = NULL;
        insert(r);      // ��带 ���� �ϸ鼭 ������
        n++;
    }

    printf("### Huffman Algorithm ###\n\n");
    print_PQ();     // �Է��� ���� �켱���� ��⿭

    result = huffman(n);    // ������ �˰���

    printf("\n-- Result Huffman code tree\n");
    print_tree(result, ROOT, code);
    printf("\n");

    freetree(result);   // �޸� ����
    fclose(file);

    return 0;
}

void freetree(node* r)  // �޸� ����
{
    if (r) {
        freetree(r->left);
        freetree(r->right);
        free(r);
    }
}


pq* insert(node* r) // �켱���� ��⿭�� ��� ����
{
    pq* tmp = NULL;
    pq* new = NULL;

    // �켱���� ��⿭ �߰��� ���ο� ���� �Ҵ�
    new = (pq*)malloc(sizeof(pq));
    new->Node = r;      // ��⿭�� �߰��� ���ο� ������ r ��尪 ����
    new->next = NULL;

    if (PQ == NULL) {    // ��⿭�� �������� ���ο� ������ ����Ʈ�� head�� ��
        PQ = new;
        return PQ;
    }
    else if (PQ->Node->frequency > new->Node->frequency) {
        new->next = PQ;             // ��Ʈ ��忡 ���� �� �� ����
        PQ = new;
    }
    else {                            // ��⿭�� ����Ʈ�� ��� �ִٸ�..
        tmp = PQ;                       // tmp�� head
        while (tmp->next != NULL) {        // ���� ��尡 ����������..
            if (tmp->next->Node->frequency <= new->Node->frequency)
                tmp = tmp->next;        // �켱���� ��⿭ ������ ���� ��
            else {                       // new�� �󵵼��� tmp ���� ũ��,
                new->next = tmp->next;  // tmp->next�� �󵵼����� ������..  
                tmp->next = new;        // �� ��� ���̿� �� ��带 ����
                break;
            }

        }
        if (tmp->next == NULL)     // ���� ��⿭�� ��� ������ ����
            tmp->next = new;

        return tmp;
    }
    return 0;
}

node* huffman(int n)    // ������ �˰���
{
    node* p;
    node* q;
    node* r;

    int i;

    for (i = 1; i < n - 1; i++) {
        p = Remove();   // �켱 ���� ��⿭���� �ϳ��� ��带 ���ͼ� p�� ����
        q = Remove();   // �켱 ���� ��⿭���� �ϳ��� ��带 ���ͼ� q�� ����

        r = (node*)malloc(sizeof(node)); // ���ο� �κ� Ʈ���� ���� ���� �Ҵ�
        r->left = p;
        r->right = q;
        r->frequency = p->frequency + q->frequency;
        r->symbol = '*';  // �κ� Ʈ���� �Ѹ����� ��Ÿ��
        insert(r);          // ������� �κ� Ʈ���� �켱 ���� ��⿭�� ����

        printf("-- Create sub tree (%d/%d)\n  ", i, n - 2);
        printf("%c:%d = %c:%d + %c:%d\n",
            r->symbol, r->frequency, p->symbol, p->frequency, q->symbol, q->frequency);
        print_PQ();
    }

    r = Remove();   // �켱 ���� ��⿭�� �ִ� Ʈ���� �Ѹ��� ���ͼ� r�� ����
    return r;
}

node* Remove()  // �켱 ���� ��⿭���� �ϳ��� ��带 ���� ���ϰ����� �ѱ��
{
    node* pq_firstnode = NULL;

    pq_firstnode = PQ->Node;
    PQ = PQ->next;

    return pq_firstnode;
}

void print_PQ()     // �켱���� ��⿭ ���
{
    pq* tmp = PQ;
    printf("-- Priority Queue\n  | ");
    while (tmp != NULL) {
        printf("%c:%d | ", tmp->Node->symbol, tmp->Node->frequency);
        tmp = tmp->next;
    }
    printf("\n\n");
}

void print_tree(node* r, int n, char* code) // ��� ������ �˰���  Ʈ�� ���
{
    if (r) {
        n++;    // Ʈ���� ���̸� ǥ��

        code[n] = '0';    // Ʈ���� ����
        print_tree(r->left, n, code);

        code[n] = '1';    // Ʈ���� ����
        print_tree(r->right, n, code);

        code[n] = '\0';   // ��� ����
        if (r->left == NULL || r->right == NULL)   // �ڽ��� �ִ� ���� ������� ����
            printf(" - %c:%d\t= %s\n", r->symbol, r->frequency, code);
    }
}