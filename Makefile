all:
	gcc kk.c gen.c run_kk.c stdrep.c altrep.c kar.c r.c -o kk -g -lm
	gcc gen_set.c gen.c r.c -o gen_set -g -std=c99
