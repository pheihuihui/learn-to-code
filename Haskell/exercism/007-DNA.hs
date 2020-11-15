module DNA (toRNA) where

import Data.Either

toRNA :: String -> Either Char String
toRNA "" = Right ""
toRNA "A" = Right "U"
toRNA "C" = Right "G"
toRNA "G" = Right "C"
toRNA "T" = Right "A"
toRNA "U" = Left 'U'
toRNA str
  | length str == 1 = Left 'X'
  | isRight hh && (isRight tt) = (++) <$> hh <*> tt
  | hh == Left 'X' || (tt == Left 'X') = Left 'X'
  | otherwise = Left 'U'
  where
    hh = toRNA [head str]
    tt = toRNA $ tail str