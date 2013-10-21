#include <string>
#include <iostream>
#include <cmath>
#include <sstream>

template<typename T, typename RetT>
struct unary_func
{
  typedef T param_type;
  typedef RetT return_type;
  typedef return_type (*func_type)(param_type);
  func_type func_ptr;
  unary_func(func_type func_ptr) : func_ptr(func_ptr) {}
  return_type operator() (param_type v) {return func_ptr(v);}
};

template<typename T, typename RetT>
unary_func<T, RetT> unary(RetT (*func_ptr)(T))
{
  return unary_func<T, RetT>(func_ptr);
}

template<typename Func0, typename Func1>
struct chain_func
{
  typedef typename Func0::return_type return_type;
  typedef typename Func1::param_type param_type;
  Func0 func0;
  Func1 func1;
  chain_func(Func0 func0, Func1 func1) : func0(func0), func1(func1) {}
  return_type operator() (param_type v) {return func0(func1(v));}
};

template<typename Func0, typename Func1>
chain_func<Func0, Func1> chain(Func0 func_ptr0, Func1 func_ptr1)
{
  return chain_func<Func0, Func1>(func_ptr0, func_ptr1);
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
  std::cout << chain(unary(double_to_string), unary(root3))(3) << std::endl
            << chain(unary(double_to_string), unary(root4))(3) << std::endl;
}
int main()
{
  test_chain();
  return 0;
}
