#include <iostream>

// 定义一个保存任意两种类型数据的数据对类模板
// T1, T2是模板参数，指代待保存数据的类型
template<typename T1, typename T2>
struct pair {T1 first; T2 second;};

// 定义针对任意类型数据的求平方和的函数
// T是模板参数，指代待比较的数据的类型
template<typename T>
T sqsum(T const &v1, T const &v2) {return v1 * v1 + v2 * v2;}

int main()
{
  pair<int, int> pair_ii;
  pair_ii.first = 15;
  pair_ii.second = pair_ii.first + 20;
  std::cout << pair_ii.first << ", " << pair_ii.second
            << std::endl;

  std::cout << sqsum(pair_ii.first, pair_ii.second)
            << std::endl;

  return 0;
}
