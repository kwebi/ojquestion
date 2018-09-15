//
// Created by 弱冠 on 2018/7/14.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdbool.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* right;
    struct TreeNode* left;
}TN;
typedef TreeNode* PN;

PN create_tree(PN& root) {
    char data[1024];
    scanf("%s", data);
    if (strcmp(data,"null") == 0) {
        return NULL;
    } else {
        root = (PN)malloc(sizeof(TN));
        root->data = atoi(data);
        create_tree(root->left);
        create_tree(root->right);
    }
}

bool is_same(PN t1, PN t2) {
    if (t1 == NULL || t2 == NULL) {
        if (t1 == NULL && t2 != NULL) {
            return false;
        }
        else if (t2 == NULL && t1 != NULL) {
            return false;
        }
        else if (t1 == NULL && t2 == NULL) {
            return true;
        }
    } else {
        if (t1->data == t2->data) {
            bool b1 = is_same(t1->left, t2->left);
            bool b2 = is_same(t1->right, t1->right);
            if (b1 == true && b2 == true) {
                return true;
            }
        }
        else {
            return false;
        }
    }
}

int main() {
    freopen("data.txt","r",stdin);
    PN t1 = NULL;
    PN t2 = NULL;
    create_tree(t1);
    create_tree(t2);
    bool b = is_same(t1,t2);
    if (b == true) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    return 0;
}
