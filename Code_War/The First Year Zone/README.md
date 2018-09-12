<b>The First Year Zone</b><br />

Since the question asks you to check out the sum of squares it is assured that the numbers only till the square root of the sum should be checked. Apart from this you might break the loops when the sum exceeds N.
The catch of the question remains in removing the repetitions in palindromes that occurs so that you do not double count. For that purpose we hae used an unordered_set.
