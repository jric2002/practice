cp = {
  12 : 2,
  15 : 2.2,
  18 : 4.5,
  19 : 3.5,
  23 : 6,
  25 : 6,
  29 : 5
}
while c, m = map(int, input().split(",")):
  print(cp[c] * m)