module Pangram (isPangram) where

import Data.Char

isInAlpha :: Char -> Bool
isInAlpha ch = elem ch ['a' .. 'z']

insert :: String -> Char -> String
insert str ch =
  let lowch = toLower ch
   in if (isInAlpha lowch) && (not $ elem lowch str)
        then lowch : str
        else str

isPangram :: String -> Bool
isPangram str =
  if (length $ insertAll str) == 26
    then True
    else False
  where
    insertAll str' = foldl insert "" str'