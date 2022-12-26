#include "all.c"

void free_i(void* v) {
    free(v);
}

int main() {
    sll* l = create_sll();
    sln* tmp_sln;
    for (int i = 0; i < 10; i++) {
        tmp_sln = create_sln();
        tmp_sln->data = malloc(sizeof(int));
        *(int*)(tmp_sln->data) = i;
        sll_add_back(l, tmp_sln);
    }
    sll_traverse(n, l) {
        printf("%d\n", *((int*)(n->data)));
    }

    void_free_func *freeList = sll_free_constructor(free_i);
    freeList(l);

}