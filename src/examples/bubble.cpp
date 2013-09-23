#include <iostream>

template<typename T>
void swap(T &a, T &b) {T c = a; a = b; b = c;}

struct node
{
  int v;
  node *next;
};

void pop_bubble(node *head)
{
  if (head) {
    node *p = head;
    for (; p->next; p = p->next) {
      if (p->v > p->next->v)
        swap(p->v, p->next->v); // 借用之前实现的swap函数。
    }
    swap(head->v, p->v);
  }
}

int main()
{
  int ary[10] = {0, 4, 2, 6, 1, 5, 8, 3, 9, 7};
  node nds[10];
  nds[0].v = ary[0];
  nds[0].next = 0;
  for (unsigned i = 1; i < 10; ++i) {
    nds[i].v = ary[i];
    nds[i].next = nds + i - 1;
  }
  pop_bubble(nds + 9);

  for (unsigned i = 0; i < 10; ++i) {
    std::cout << nds[i].v << ", ";
  }
  std::cout << std::endl;
  return 0;
}
