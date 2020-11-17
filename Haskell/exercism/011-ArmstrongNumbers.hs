module ArmstrongNumbers (armstrong) where

toList :: Integral a => a -> [a]
toList n
  | n < 10 = [n]
  | otherwise =
    let v = n `mod` 10
     in v : toList (n `div` 10)

armstrong :: Integral a => a -> Bool
-- armstrong = error "You need to implement this function."
armstrong n =
  let arr = reverse $ toList n
      len = length arr
      brr = (^ len) <$> arr
   in sum brr == n