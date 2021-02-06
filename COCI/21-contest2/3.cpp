// ga, gb | a > b
// a / b, gb
// a / b = c, gcd(a, b) = 1
// can constuct a = c * b + 1 s.t. gcd(a, b) = 1
// so the problem becomes: find c, b, s.t. R(c, gb) = h, c is any integer <= gb
// note that last step, must be R(h, h..2h-1)
// R(h, h) = R(h, h * h..h * h + h - 1) (range = h)
// * if range > g, we can construct b
// R(h, h^2) = R(h^2, h^4..h^4 + h^2 - 1) (range = h^2)
// similarly, 