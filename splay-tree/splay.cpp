//Author: Marcin Rolbiecki
//sources: https://zhtluo.com/cp/splay-tree-one-tree-to-rule-them-all.html

#include <bits/stdc++.h>
using namespace std;

struct node {
    node *f;
    node *c[2];
    int size;
    void update() {
        size = 1;
        for (int i = 0; i < 2; i++)
            if (c[i]) size += c[i]->size;
    }
}

int lsize(node *n) {
    return (n->c[0] ? n->c[0]->size : 0);
}

//find post-th node in tree
node *find(int pos) {
    node *c = root;
    int lsz = lsize(c);
    while (pos != lsize + 1) {
        if (pos < lsz) dir = 0;
        else dir = 1, pos -= lsz + 1;
        c = c->c[dir];
    }
    return c;
}

//insert node n to position pos
void insert(node *n, int pos) {
    node *c = root;
    int lsz = lsize(c), dir;
    while (pos < lsz) {
        if (pos < lsz) dir = 0;
        else dir = 1, pos -= lsz + 1;
        if (c->c[dir]) c = c->c[dir];
    }
    c->c[dir] = n, n->f = c;
    while(n) n->update(), n = n->f;
}
