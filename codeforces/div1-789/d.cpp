// bubble sort k times
// for k = 0: easy recurrence:
// f(n) = f(n - 1) if s[i] != -1
//        f(n - 1) * (n - 1) if s[i] == -1
// bubble sort changes the sample space & multiplicity
// the only condition: last k elements are fixed
// everything else is constructible: n, n-1, .. n-k+1, p_1, p_2, ...
// bubble sort swap == v[i], v[i + 1] := v[i + 1] - 1, v[i]
// I'm retarded: bubble sort == v[i] = min(v[i + 1] - 1, 0), v[n] = 0
// reverse: shift right, v[0] = 1, and each 0 become 0 or 1. 2^z combos (z = # of zeros)
// so ans = 1 * 2 * ... * k * product(i + 1 where s[i] == 0) * product(i where s[i] == -1)
