apply_on_pair :: (a->a->a)->a->a->a -- 函数类型声明
apply_on_pair func a b = func a b   -- 函数的实现

main = do
  putStrLn $ show $ apply_on_pair (+) 1 2
  
