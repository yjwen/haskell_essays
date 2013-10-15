#include <string>
#include <iostream>

using namespace std;
typedef string (*str_func_type)(string const &, string const &);
string apply_on_pair(str_func_type func,
                     string const &a, string const &b)
{
  return func(a, b);
}

// 返回函数指针类型的元函数
template<typename T>
struct func_type
{
  //类型result是元函数的返回类型
  typedef T (*result)(T const&, T const&);
};
  
template<typename T>
T apply_on_pair(typename func_type<T>::result func,
                // ↑利用元函数得到函数指针类型↑
                T const& a, T const& b)
{
  return func(a, b);
}

template<typename T>
T print_pair(T const &a, T const &b)
{
  std::cout << a << ", " << b << std::endl;
  return b;
}

int main()
{
  apply_on_pair(print_pair, string("abc"), string("def"));
  apply_on_pair(print_pair, 1, 2);
  return 0;
}
