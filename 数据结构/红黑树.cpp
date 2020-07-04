/*************************************************************************
	> File Name: 红黑树.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月23日 星期五 14时39分29秒
 ************************************************************************/

//新插入的节点颜色为红色
//每个节点非黑即红
//根节点都是黑色
//叶节点(NIL)是黑色
//如果一个节点是红色, 则它的两个子节点都是黑色
//从根节点出发到所有叶节点路径上, 黑色节点数量相同
//最短边n, 最长边2 * n - 1;
//插入节点的时候 从爷爷往下看
//删除节点的时候 从爸爸往下看
//插入和删除的情况一共5种情况(插入2种, 删除3种)
//红色节点要么是度为0 要么是度为2


#include <stdio.h>
#include <stdlib.h>

typedef struct RBTNode {
    int key, color; // 0 red, 1 black, 2 double black
    struct RBTNode *lchild, *rchild;
} RBTNode;

RBTNode __NIL;

#define NIL (&__NIL)

int init_NIL() {
    NIL->color = 1;
    NIL->lchild = NIL->rchild = NIL;
    NIL->key = 0;
    return 0;
}

const int __temp_p = init_NIL();

RBTNode *init(int key) {
    RBTNode *p = (RBTNode *)malloc(sizeof(RBTNode) * 1);
    p->key = key;
    p->color = 0;
    p->lchild = p->rchild = NIL;
    return p;    
}

RBTNode *left_rotate(RBTNode *root) {
    RBTNode *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

RBTNode *right_rotate(RBTNode *root) {
    RBTNode *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

RBTNode *insert_maintain(RBTNode *root, int flag) {
    if (root->lchild->color == 0 && root->rchild->color == 0) {
        root->rchild->color = root->lchild->color = 1;
        root->color = 0;
        return root;
    }
    if (flag) {
        if (root->lchild->color) return root;
        if (root->lchild->rchild->color && root->lchild->lchild->color) return root;
        if (root->lchild->rchild->color == 0) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
        root->color = 1, root->rchild->color = 0;
    } else {
        if (root->rchild->color) return root;
        if (root->rchild->rchild->color && root->rchild->lchild->color) return root;
        if (root->rchild->lchild->color == 0) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
        root->color = 1, root->lchild->color = 0;
    }
    return root;
}

RBTNode *__insert(RBTNode *root, int key) {
    if (root == NIL) {
        return init(key);
    }
    if (key == root->key) return root;
    if (key < root->key) root->lchild = __insert(root->lchild, key);
    else root->rchild = __insert(root->rchild, key);
    root = insert_maintain(root, key < root->key);
    return root;
}

RBTNode *insert(RBTNode *root, int key) {
    root = __insert(root, key);
    root->color = 1;
    return root;
}

RBTNode *delete_maintain(RBTNode *root) {
    if (root == NIL) return root;
    if (root->lchild->color < 2 && root->rchild->color < 2) return root;
    if (root->lchild->color == 0) {
        root = right_rotate(root);
        root->color = 1, root->rchild->color = 0;
        root->rchild = delete_maintain(root->rchild);
        return root;
    } else if (root->rchild->color == 0) {
        root = left_rotate(root);
        root->color = 1, root->lchild->color = 0;
        root->lchild = delete_maintain(root->lchild);
        return root;
    }
    if (root->lchild->color == 2) {
        if (root->rchild->rchild->color && root->rchild->lchild->color) {
            root->rchild->color = 0;
            root->color += 1;
            root->lchild->color = 1;
        } else {
            root->lchild->color = 1;
            if (root->rchild->rchild->color) {
                root->rchild = right_rotate(root->rchild);
                root->rchild->color = 1;
                root->rchild->rchild->color = 0;
            }
            root = left_rotate(root);
            root->color = root->lchild->color;
            root->lchild->color = 1, root->rchild->color = 1;
        }
    } else {
        if (root->lchild->rchild->color && root->lchild->lchild->color) {
            root->lchild->color = 0;
            root->color += 1;
            root->rchild->color = 1;
        } else {
            root->rchild->color = 1;
            if (root->lchild->lchild->color) {
                root->lchild = left_rotate(root->lchild);
                root->lchild->color = 1;
                root->lchild->lchild->color = 0;
            }
            root = right_rotate(root);
            root->color = root->rchild->color;
            root->lchild->color = 1, root->rchild->color = 1;
        }
    }
    return root;
}

RBTNode *predecessor(RBTNode *root) {
    root = root->lchild;
    while (root->rchild != NIL) root = root->rchild;
    return root;
}

RBTNode *__delete_node(RBTNode *root, int key) {
    if (root == NIL) return root;
    if (key < root->key) {
        root->lchild = __delete_node(root->lchild, key);
    } else if (key > root->key) {
        root->rchild = __delete_node(root->rchild, key);
    } else {
        if (root->rchild == NIL && root->lchild == NIL) {
            NIL->color += root->color;
            free(root);
            return NIL;
        } else if (root->lchild == NIL || root->rchild == NIL) {
            RBTNode *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            RBTNode *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __delete_node(root->lchild, temp->key);
        }
    }
    root = delete_maintain(root);
    return root;
}

RBTNode *delete_node(RBTNode *root, int key) {
    root = __delete_node(root, key);
    root->color = 1;
    return root;
}

void clear(RBTNode *node) {
    if (node == NIL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

void output(RBTNode *root) {
    if (root == NIL) return ;
    printf("%d(%d, %d, %d)\n",
        root->key,
        root->color, 
        root->lchild->key, 
        root->rchild->key
    );
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    RBTNode *root = NIL;
    int op, key;
    while (~scanf("%d%d", &op, &key)) {
        switch (op) {
            case 1: root = insert(root, key); break;
            case 2: root = delete_node(root, key); break;
        }
        printf("----------------\n");
        output(root);
        printf("----------------\n");
    }
    return 0;
}
