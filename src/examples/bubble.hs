bub (e:[]) = [e] -- 当序列只有一个元素e时，返回该序列
bub l | e > e' = e:e':lr'
      | otherwise = e':e:lr'
  where e = head l
        lr = tail l
        l' = bub lr -- 递归调用
        e' = head l'
        lr' = tail l'

main = putStrLn $ show $ bub [9, 3, 7, 1, 15, 6]
