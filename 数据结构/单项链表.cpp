/*************************************************************************
	> File Name: 单项链表.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月11日 星期四 19时29分18秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


typedef struct Node {
    int data;
    struct Node *next;
}Node, *LinkedList;

Node *get_node(int value) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->next = NULL;
    return p;
}


LinkedList insert(LinkedList head, int value, int index) {
    /*if (head == NULL) {
        return (index == 0 ? get_node(value) : NULL);
    }*/
    Node ret, *p;
    ret.next = head;
    p = &ret;
    while (index != 0 && p != NULL) {
        index--;
        p = p->next;
    }
    if (p == NULL) return head;
    Node *new_node = get_node(value);
    new_node->next = p->next;
    p->next = new_node;
    return ret.next;
}

LinkedList insert_circle(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            return head;
        }
        head = node;
        head->next = head;
        return head;
    }
    if (index == 0) {
        node->next = head->next;
        head->next = node;
        return head;
    }
    Node *current_node = head->next;
    int count = 0;
    while (count < index - 1 && current_node != head) {
        current_node = current_node->next;
        count++;
    }
    if (index - 1 == count) {
        node->next = current_node->next;
        current_node->next = node;
    }
    if (node == head->next) {
        head = node;
    }
    return head;
}

LinkedList delete_node(LinkedList head, int index) {
    if (index < 0) return head;
    Node ret, *p;
    ret.next = head;
    p = &ret;
    while (index != 0 && p->next != NULL) {
        index --;
        p = p->next;
    }
    if (p->next == NULL) return head;
    Node *node = p->next;
    p->next = p->next->next;
    free(node);
    return ret.next;
}

LinkedList reverse(LinkedList head) {
    if (head == NULL) return head;
    Node *next_node, *current_node;
    current_node = head->next;
    head->next = NULL;
    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = head;
        head = current_node;
        current_node = next_node;
    }
    return head;
}

void clear(LinkedList head) {
    Node *node = head;
    while (node != NULL) {
        Node *delete_node = node;
        node = node->next;
        free(delete_node);
    }
    return ;
}

void output(LinkedList head) {
    Node *node = head;
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
    return ;
}


int main() {
    LinkedList head = NULL;
    int op, value, index;
    while (~scanf("%d", &op)) {
        switch (op) {
            case 1 : {
                scanf("%d%d", &value, &index);
                head = insert(head, value, index);
                break;
            }
            case 2: {
                scanf("%d", &index);
                head = delete_node(head, index);
                break;
            }
            default : {
                break;
            }
        }
        output(head);
    }
    head = reverse(head);
    output(head);
}
