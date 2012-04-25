#define big long long

int *neighbor(int *new, int *s);
int *altneighbor(int *new, int *s);

int *gen_rand_alt(int *s, int n);
int *gen_rand_std(int *s, int n);
big r(void);
big *gen(big *list, int n);
big kar(big *list);
big *preprocess(int *partitionnumbers, big *list);
