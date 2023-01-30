  N = 10
  .global main
main: save %sp, -96, %sp ! 스택 프레임 확보
      clr %l0 ! f0 = 0
      mov 1, %l1 ! f1 = 1
      mov 2, %l3 ! i = 2
      ba test ! while의 조건식으로 무조건 분기
      cmp %l3, n ! subcc %l2, n, %g0 즉 cc 생성
loop: add %l1, %l2, %o0 ! fn = 2f(n-2)+f(n-1)
      mov %l1, %l0 ! fn-2 = fn-1
      mov %o0, %l1 ! fn-1 = fn
      inc %l3 ! i++
      cmp %l3, n ! subcc %l2, n, %g0 즉 cc 생성
test: ble,a loop ! i<n이면 while의 몸체로 이동
      add %l0, %l0, %l2 ! 2fn-2
out:  ret ! 귀환
      restore ! 스택 프레임 수거
