f0 = 0, f1 = 1, fn = fn-1 + 2*fn-2, n>=2

cat data.s xxxx.s > tmp.s
gcc -g tmp.s -o fibonacci
fibonacci
