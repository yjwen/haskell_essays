#include <string>
#include <iostream>
#include <cmath>
#include <sstream>

template<typename T0,
         typename T1,
         typename T2>
T0 chain(T0 (*func0)(T1),
//            ^^^^^声明func0是一个函数指针，指
// 向有一个T1型参数并返回一个T0型值的函数
         T1 (*func1)(T2),
//            ^^^^^类似func0，也是一个函数指针
// 指向有一个T2型参数并返回一个T1型值的函数
         T2 const &v)
{
  return func0(func1(v));
}

double root3(int v) {return pow(v, -3);}
double root4(int v) {return pow(v, -4);}

std::string double_to_string(double v)
{
  std::ostringstream oss;
  oss << v;
  return oss.str();
}

void test_chain()
{
  std::cout << chain(double_to_string, root3, 3) << std::endl
            << chain(double_to_string, root4, 3) << std::endl;
}
int main()
{
  test_chain();
  return 0;
}
