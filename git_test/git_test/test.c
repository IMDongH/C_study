#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    char symbol;   // 문자값
    int frequency; // 파일에 있는 문자의 빈도수

    struct nodetype* left;
    struct nodetype* right;
}node;

typedef struct pq   // 우선순위 대기열
{
    node* Node;         // 대기열에 있는 node
    struct pq* next;   // 다음 node
}pq;

#define ROOT    -1 // 부호화 함수 출력시 초기값

pq* insert(node* r);        // 우선순위 대기열에 노드를 정렬하여 삽입
node* huffman(int n);       // 허프만 코드 트리를 만드는 함수
node* Remove();             // 우선 순위 대기열에서 노드를 삭제
void print_PQ();            // 우선 순위 대기열 출력
void print_tree(node* r, int n, char* code);    // 결과 허프만 부호화 출력
void freetree(node* r);     // 메모리 해제

pq* PQ = NULL;      // 우선순위 대기열
FILE* file;         // 파일 식별자

int main()
{
    int n = 1;
    node* result = (node*)malloc(sizeof(node));   // 결과를 돌려받을 노드
    char* code = (char*)malloc(sizeof(char));

    file = fopen("huffman.txt", "r");  // 입력이 되는 문자와 빈도수
    if (file == NULL) {
        perror("File open error");
        return 0;
    }


    while (1) {
        node* r = (node*)malloc(sizeof(node));
        if ((fscanf(file, "%c:%d ", &r->symbol, &r->frequency)) == -1) {
            break;       // 파일에 더 이상 값이 없으면 while 끝내기
        }
        r->left = NULL;
        r->right = NULL;
        insert(r);      // 노드를 삽입 하면서 정렬함
        n++;
    }

    printf("### Huffman Algorithm ###\n\n");
    print_PQ();     // 입력이 끝난 우선순위 대기열

    result = huffman(n);    // 허프만 알고리즘

    printf("\n-- Result Huffman code tree\n");
    print_tree(result, ROOT, code);
    printf("\n");

    freetree(result);   // 메모리 해제
    fclose(file);

    return 0;
}

void freetree(node* r)  // 메모리 해제
{
    if (r) {
        freetree(r->left);
        freetree(r->right);
        free(r);
    }
}


pq* insert(node* r) // 우선순위 대기열에 노드 삽입
{
    pq* tmp = NULL;
    pq* new = NULL;

    // 우선순위 대기열 추가할 새로운 공간 할당
    new = (pq*)malloc(sizeof(pq));
    new->Node = r;      // 대기열에 추가할 새로운 공간에 r 노드값 삽입
    new->next = NULL;

    if (PQ == NULL) {    // 대기열이 비여있으면 새로운 공간이 리스트의 head가 됌
        PQ = new;
        return PQ;
    }
    else if (PQ->Node->frequency > new->Node->frequency) {
        new->next = PQ;             // 루트 노드에 대한 비교 및 정렬
        PQ = new;
    }
    else {                            // 대기열에 리스트가 들어 있다면..
        tmp = PQ;                       // tmp는 head
        while (tmp->next != NULL) {        // 다음 노드가 없을때까지..
            if (tmp->next->Node->frequency <= new->Node->frequency)
                tmp = tmp->next;        // 우선순위 대기열 정렬을 위한 비교
            else {                       // new의 빈도수가 tmp 보다 크고,
                new->next = tmp->next;  // tmp->next의 빈도수보다 작으면..  
                tmp->next = new;        // 두 노드 사이에 새 노드를 삽입
                break;
            }

        }
        if (tmp->next == NULL)     // 다음 대기열이 비어 있으면 삽입
            tmp->next = new;

        return tmp;
    }
    return 0;
}

node* huffman(int n)    // 허프만 알고리즘
{
    node* p;
    node* q;
    node* r;

    int i;

    for (i = 1; i < n - 1; i++) {
        p = Remove();   // 우선 순위 대기열에서 하나의 노드를 빼와서 p에 삽입
        q = Remove();   // 우선 순위 대기열에서 하나의 노드를 빼와서 q에 삽입

        r = (node*)malloc(sizeof(node)); // 새로운 부분 트리를 위한 공간 할당
        r->left = p;
        r->right = q;
        r->frequency = p->frequency + q->frequency;
        r->symbol = '*';  // 부분 트리의 뿌리임을 나타냄
        insert(r);          // 만들어진 부분 트리를 우선 순위 대기열에 삽입

        printf("-- Create sub tree (%d/%d)\n  ", i, n - 2);
        printf("%c:%d = %c:%d + %c:%d\n",
            r->symbol, r->frequency, p->symbol, p->frequency, q->symbol, q->frequency);
        print_PQ();
    }

    r = Remove();   // 우선 순위 대기열에 있는 트리의 뿌리를 빼와서 r에 대입
    return r;
}

node* Remove()  // 우선 순위 대기열에서 하나의 노드를 빼서 리턴값으로 넘긴다
{
    node* pq_firstnode = NULL;

    pq_firstnode = PQ->Node;
    PQ = PQ->next;

    return pq_firstnode;
}

void print_PQ()     // 우선순위 대기열 출력
{
    pq* tmp = PQ;
    printf("-- Priority Queue\n  | ");
    while (tmp != NULL) {
        printf("%c:%d | ", tmp->Node->symbol, tmp->Node->frequency);
        tmp = tmp->next;
    }
    printf("\n\n");
}

void print_tree(node* r, int n, char* code) // 결과 허프만 알고리즘  트리 출력
{
    if (r) {
        n++;    // 트리의 깊이를 표시

        code[n] = '0';    // 트리의 좌측
        print_tree(r->left, n, code);

        code[n] = '1';    // 트리의 우측
        print_tree(r->right, n, code);

        code[n] = '\0';   // 찌꺼기 제거
        if (r->left == NULL || r->right == NULL)   // 자식이 있는 노드는 출력하지 않음
            printf(" - %c:%d\t= %s\n", r->symbol, r->frequency, code);
    }
}