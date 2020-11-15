module DNA (nucleotideCounts, Nucleotide (..)) where

import Data.Map

data Nucleotide = A | C | G | T deriving (Eq, Ord, Show)

nucleotideCounts :: String -> Either String (Map Nucleotide Int)
--nucleotideCounts xs = error "You need to implement this function."
nucleotideCounts "" = Right $ fromList [(A, 0), (C, 0), (G, 0), (T, 0)]
nucleotideCounts (v : xs)
  | v /= 'A' && v /= 'C' && v /= 'G' && v /= 'T' = Left "error"
  | otherwise = case pre of
    Right r -> Right $ addOne r v
    Left _ -> Left "error"
  where
    pre = nucleotideCounts xs

addOne :: (Map Nucleotide Int) -> Char -> (Map Nucleotide Int)
addOne mm 'A' = fromList [(A, lookup' mm A + 1), (C, lookup' mm C), (G, lookup' mm G), (T, lookup' mm T)]
addOne mm 'C' = fromList [(A, lookup' mm A), (C, lookup' mm C + 1), (G, lookup' mm G), (T, lookup' mm T)]
addOne mm 'G' = fromList [(A, lookup' mm A), (C, lookup' mm C), (G, lookup' mm G + 1), (T, lookup' mm T)]
addOne mm 'T' = fromList [(A, lookup' mm A), (C, lookup' mm C), (G, lookup' mm G), (T, lookup' mm T + 1)]
addOne mm _ = fromList [(A, lookup' mm A), (C, lookup' mm C), (G, lookup' mm G), (T, lookup' mm T)]

lookup' :: (Map Nucleotide Int) -> Nucleotide -> Int
lookup' mm ch = case Data.Map.lookup ch mm of
  Nothing -> 0
  Just n -> n
