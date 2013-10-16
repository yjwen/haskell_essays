#include <string>
#include <iostream>

template<typename T>
T chain_apply(T (*func)(T const&), T const &v)
{
  return func(func(v));
}

int square(int const &v) {return v * v;}

int main()
{
  std::cout << chain_apply(square, 2) << std::endl;
  return 0;
}
