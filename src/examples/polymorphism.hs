-- 可以保存任意类型数据的多态类型Pair
data Pair a b = Pair {
  first :: a,
  second :: b
  }

-- 计算任意数字类型的平方和
sqsum :: Num a => a -> a -> a -- sqsum的类型定义
sqsum x y = x * x + y * y     -- sqsum的实现

main = do
  let pair = Pair 15 16
  putStrLn $ show $ sqsum (first pair) (second pair)
