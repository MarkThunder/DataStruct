/**
 * 顺序表操作
 * InitList ( *L )  初始化操作，建立一个空的线性表 L
 * ListEmpty ( L )  线性表为空, return true; 否则, return false
 * ClearList ( *L ) 将线性表清空
 * GetElem ( L, i, *e ) 将线性表 L 中的第 i 个位置元素返回给 e
 * LocateElem ( L, e ) 在线性表 L 中查找与给定值 e 相等的元素, 成功: return 对应的下标; 失败: return 0
 * ListInsert ( *L, i, e ) 在线性表 L 中第 i 个位置插入 e
 * ListDelete ( *L, i, *e ) 删除线性表第 i 个元素, 用 e 返回
 * ListLength ( L ) 返回线性表 L 的元素个数
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
    int sqListSize;
} SqList;

void OperateOutput();

Status InitList(SqList *L);

Status GetElem(SqList L, int i, ElemType *e);

Status ListEmpty(SqList L);

Status ClearList(SqList *L);

Status LocateElem(SqList L, ElemType e);

Status ListInsert(SqList *L, int i, ElemType e);

Status ListDelete(SqList *L, int i, ElemType *e);

Status ListLength(SqList L);

int main() {

    SqList L;
    ElemType e;
    int command = 0;
    OperateOutput();
    while (scanf("%d", &command) && command) {
        switch (command) {
            case 1: {
                if (InitList(&L)) {
                    printf("InitList is OK\n");
                }
            }
                break;
            case 2: {
                if (ListEmpty(L)) {
                    printf("SqList is Empty\n");
                } else {
                    printf("SqList is not Empty\n");
                }
            }
                break;
            case 3: {
                if (ClearList(&L)) {
                    printf("Clear is ok\n");
                }
            }
                break;
            case 4: {
                int i;
                printf("Which element do you want to get\n");
                scanf("%d", &i);
                if (GetElem(L, i, &e)) {
                    printf("The %d element is %d\n", i, e);
                } else {
                    printf("The i Enter ERROR\n");
                }
            }
                break;
            case 5: {
                printf("Enter the element you want to find\n");
                scanf("%d", &e);
                int position = LocateElem(L, e);
                if (!position) {
                    printf("The number does not exist\n");
                } else {
                    printf("This number is in the %d position\n", position);
                }
            }
                break;
            case 6: {
                printf("Enter the position and the element you want to insert\n");
                int i = 0;
                scanf("%d,%d", &i, &e);
                if (ListInsert(&L, i, e)) {
                    printf("Insert OK!\n");
                }
            }
                break;
            case 7: {
                printf("Enter the position and the element you want to delete\n");
                int i = 0;
                scanf("%d,%d", &i);
                ListDelete(&L, i, &e);
                printf("delete element is %d\n", e);
            }
                break;
            case 8: {
                printf("SqList length is %d\n", ListLength(L));
            }
                break;
            default: {
                printf("command INPUT ERROR!!!\n");
            }
        }
        printf("Please Enter Command:\n");
    }
    return 0;
}

void OperateOutput() {
    printf("*************************\n");
    printf("welcome to mark SqList\n");
    printf("1: InitList\n");
    printf("2: ListEmpty\n");
    printf("3: ClearList\n");
    printf("4: GetElem\n");
    printf("5: LocateElem\n");
    printf("6: ListInsert\n");
    printf("7: ListDelete\n");
    printf("8: ListLength\n");
    printf("*************************\n");
    printf("Please enter command according to the sequence number\n");
}

Status GetElem(SqList L, int i, ElemType *e) {
    if (i >= MAXSIZE) {
        return FALSE;
    }

    *e = L.data[i - 1];
    return TRUE;
}

Status InitList(SqList *L) {
    L->data = (ElemType *) malloc(MAXSIZE * sizeof(ElemType));
    L->length = 0;
    L->sqListSize = MAXSIZE;
    return TRUE;
}

Status ListEmpty(SqList L) {
    return L.length == 0;
}

Status ClearList(SqList *L) {
    if (L->length == 0)
        return TRUE;
    for (int i = 0; i < L->length; i++) {
        L->data = 0;
    }
    L->length = 0;
    return TRUE;
}

Status LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (e == L.data[i]) {
            return i + 1;
        }
    }
    return FALSE;
}

Status ListInsert(SqList *L, int i, ElemType e) {
    if (i < 1 && i > L->length + 1)
        return FALSE;
    if (L->length >= L->sqListSize)
        return FALSE;
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return TRUE;
}

Status ListDelete(SqList *L, int i, ElemType *e) {
    if (i < 1 && i > L->length + 1)
        return FALSE;
    if (L->length >= L->sqListSize)
        return FALSE;
    *e = L->data[i - 1];
    for (int j = i - 1; j <= L->length; ++j) {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    return TRUE;
}

Status ListLength(SqList L) {
    return L.length;
}