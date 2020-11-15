module SumOfMultiples (sumOfMultiples) where

import Data.List.NonEmpty (fromList)

mod' :: [Integer] -> Integer -> Bool
mod' [] _ = False
mod' (x : xs) n =
  let b1 = x /= 0 && n `mod` x == 0
      b2 = mod' xs n
   in b1 || b2

sumList :: [Integer] -> Integer
sumList xs = foldr (+) 0 xs

sumOfMultiples :: [Integer] -> Integer -> Integer
-- sumOfMultiples factors limit = error "You need to implement this function."
sumOfMultiples arr n =
  let tmp = [x | x <- [1 .. n - 1], mod' arr x]
   in sumList tmp


--------------------------------------------------------------------------
sumOfMultiples' :: [Integer] -> Integer -> Integer
sumOfMultiples' factors limit =
  sum $ fromList $ concatMap (\x -> [x, 2 * x .. limit -1]) $ filter (/= 0) factors
--------------------------------------------------------------------------
