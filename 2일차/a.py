#집합
#중복을 허용하지 않고 순서는 없음

s = {1,2,3}
b = set({1,2,3,8})

print(s | b)

s.update([4,5,6,7])

print(s)

s.remove(4)

print(s)