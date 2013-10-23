#include <string>
#include <iostream>
#include <cmath>
#include <sstream>

// 提取函数对象返回值的元函数
template<typename T>
struct function_traits
{
  typedef decltype(&T::operator()) operator_type;
  typedef typename function_traits<operator_type>::return_type return_type;
};

template<typename R, typename C, typename... A>
struct function_traits<R (C::*)(A...)>
{
  typedef R return_type;
};
// 元函数到此结束

// 连锁调用两个单参数函数的函数对象
template<typename Func0,        // Func0与Func1为所调用的函数对象类型。
         typename Func1>
struct chain_func
{
  // 利用元函数提取出Func0的返回值类型
  typedef typename function_traits<Func0>::return_type return_type;
  Func0 func0;                  // 所复用的函数对象
  Func1 func1;
  chain_func(Func0 func0, Func1 func1) : func0(func0), func1(func1) {}
  // 重载的括号操作符，连锁调用func1与func0
  template<typename T>
  return_type operator() (T v) {return func0(func1(v));}
};

// 生成连锁调用函数对象的助手函数模板
template<typename Func0, typename Func1>
chain_func<Func0, Func1> chain(Func0 func_ptr0, Func1 func_ptr1)
{
  return chain_func<Func0, Func1>(func_ptr0, func_ptr1);
}

void test_chain()
{
  // 利用C++11中的lambda函数生成函数对象
  auto is_odd = [](int v) mutable {return v % 2 == 1;};
  auto invert = [](bool v) mutable {return !v;};
  auto bool_to_string = [](bool v) mutable {
    return std::string(v ? "true" : "false");
  };

  // 用两次chain生成三个函数对象的连锁调用函数。
  auto is_even = chain(invert, is_odd);
  auto is_even_str = chain(bool_to_string, is_even);

  // 将打印字符串"true"
  std::cout << is_even_str(4) << std::endl;

}
int main()
{
  test_chain();
  return 0;
}
