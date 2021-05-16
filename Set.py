#집합이란?
s2 = set("Hello")
print(s2) #{'e', 'H', 'l', 'o'}
# 중복을 허용하지 않는다.
# 순서가 없다(Unordered).

#교집합
a= set([1, 2, 3, 4, 5, 6])
b= set([4, 5, 6, 7, 8, 9])
print(a&b) # 출력 => {4,5,6}
print(a.intersection(b)) # 출력 => {4,5,6}

#합집합
a= set([1, 2, 3, 4, 5, 6])
b= set([4, 5, 6, 7, 8, 9])
print(a | b) #출력 => {1, 2, 3, 4, 5, 6, 7, 8, 9}
print(a.union(b)) #출력 => {1, 2, 3, 4, 5, 6, 7, 8, 9}

#차집합
print(a-b) #출력 => {1,2,3}
print(b-a) #출력 => {8,9,7}
print(a.difference(b)) #출력 => {1,2,3}
print(b.difference(a)) #출력 => {8,9,7}

##관련함수
#add
s=set([1,2,3])
s.add(4)
print(s) # 출력 => {1, 2, 3, 4}

#update
s1=set([1, 2, 3])
s1.update([4, 5, 6])
print(s1) #출력 => {1, 2, 3, 4, 5, 6}

#remove
s2 = set([1, 2, 3])
s2.remove(2)
print(s2) #출력 => {1, 3}