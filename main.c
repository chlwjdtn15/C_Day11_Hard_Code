// 문제 : 배열을 훼손하는 change 함수를 만들어주세요.

#include <stdio.h>

void change(int* p) {
  // v1
  *p = 0;
  *(p + 1) = 0;

  // v2
  *p = 0;
  p++;
  *p = 0;
  p--;

  // v3
  *(p + 0) = 0;
  *(p + 1) = 0;

  // v4
  p[0] = 0;
  p[1] = 0;

  // v5
  *&p[0] = 0;
  *&p[1] = 0;

  // v6
  0[p] = 0;
  1[p] = 0;
}

int main(void) {
  int x[2] = {100, 200};

  printf("change 함수를 호출하기 전, x[0] : %d, x[1] : %d\n", x[0], x[1]);

  // 이렇게도 가능하고
  change(x);
  // 이렇게도 가능하다.
  change(&x[0]);

  printf("change 함수를 호출하기 전, x[0] : %d, x[1] : %d\n", x[0], x[1]);
  // 출력 => change 함수를 호출하기 전, x[0] : 200, x[1] : 400

  return 0;
}