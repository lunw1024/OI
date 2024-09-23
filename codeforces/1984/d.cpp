// answer can potentially be very large. n^2 large
// all distinct characters must be in there. 
// what if i strip all 'a'?
// if the resulting string is not separable, the minimal valid t is that result string with 'a' in the middle added back
// if the resulting string is separable, there should only be a few possibilities.
// we can find the smallest period. all possible periods should be a multiple of the smallest one. (claim 1)
// can also brute force and check for all periods 1, 2, ..., n, which takes n^2. Bad.
// use KMP, O(n). KMP feels sus tho.
// if we do rolling hash, we only need to check n*(1 + 1/2 + 1/3 + ...).
// but how do we add back the 'a'?
// we can store it as a property of each non-a char, and the criterion becomes
// a == b iff a[i] == b[i] for all i and cnt[a[i]] == cnt[b[i]] for all i but the last one
// ok just brute force all the divisor of the string length. this is n * d(n). d(n) is bounded by 240. With early stopping (after finding the smallest)
// then do combinatorics to calculate total # of combos. for each possible period (up to d(n)) we calculate the prefix a, suffix a, and min # of a in the middle.
// pre-calculating the combo function takes O(n).
// Editorial says we can start with the first non-a char, and it works similarly. We do use rolling hash / z-function to compare all lengths of t, so O(nlogn) due to harmonic series.

