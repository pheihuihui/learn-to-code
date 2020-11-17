module PerfectNumbers (classify, Classification (..)) where

data Classification = Deficient | Perfect | Abundant deriving (Eq, Show)

classify :: Int -> Maybe Classification
-- classify = error "You need to implement this function."
classify n
  | n <= 0 = Nothing
  | res == n = Just Perfect
  | res < n = Just Deficient
  | res > n = Just Abundant
  | otherwise = Nothing
  where
    res = sum $ getFactors n

getFactors :: Int -> [Int]
getFactors n = 0 : [x | x <- [1 .. n - 1], n `mod` x == 0]