chain :: (b -> c) -> (a -> b) -> a -> c
chain func0 func1 v = func0 (func1 v)

is_odd :: Int -> Bool
is_odd v | (mod v 2) == 0  = False
         | otherwise       = True

bool_to_string :: Bool -> String
bool_to_string v | v == True = "True"
                 | otherwise = "False"

test_chain = chain bool_to_string is_odd 4

invert :: Bool -> Bool
invert v | v == True = False
         | otherwise = True

test_chain_3 = chain bool_to_string (chain invert is_odd) 4

main = do
  putStrLn $ test_chain
  putStrLn $ test_chain_3
  
