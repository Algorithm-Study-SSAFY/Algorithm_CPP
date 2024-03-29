
# 목차
<h3>1. 조합</h3>
<h3>2. 순열</h3>
<h3>3. 중복조합</h3>
<h3>4. 중복순열</h3>
<h3>5. 정리</h3>
</br>

# 1. 조합
**조합(Combination)이란?** </br>
서로 다른 n개의 원소에서 r개를 중복없이 순서에 상관없게 r개의 원소를 **선택**하는 것을 의미한다. **순서가 상관없다**는 특징이 있다. 즉, {1,2,3}과 {3,2,1}은 같은 부분집합이다.

</br></br>

# 2. 순열
**순열(Permutation)이란?** </br>
서로 다른 n개의 원소에서 r개를 중복없이 순서에 상관있게 뽑는 것을 의미한다. **부분집합의 원소가 같아도 순서가 다르면 다른 부분집합이다.** 즉, {1,2,3}과 {3,2,1}은 다른 부분집합이다.

</br></br>

# 3. 중복조합
**중복조합(Duplicate Combination)이란?** </br>
서로 다른 n개에서 **중복을 허용**하여 r개를 선택하는 것을 의미한다. 중복을 허용한다는 특징이 있다. 따라서 {1,1,1}, {1,1,2}와 같은 부분집합은 가능하지만, 순서는 상관없는 **조합**이기 때문에 이미 {1,1,2}가 나왔다면 {1,2,1}이나 {2,1,1,}은 나올 수 없다.

</br></br>

# 4. 중복순열
**중복순열(Duplicate Permutation)이란?** </br>
순열과 마찬가지로 n개의 원소에서 r개를 **중복을 허용**하여 순서에 상관있게 뽑는 것을 의미한다. 중복을 허용하는 **순열**이기 때문에 {1,1,1}, {1,1,2}와 같은 원소의 중복뿐만 아니라, {2,1,1}, {1,2,1}과 같이 이미 나왔던 조합도 순서가 다르다면 나올 수 있다.

</br></br>
# 5. 정리
* **조합**은 원소의 중복을 허락하지 않으며 순서에 상관없다.(순서가 다르면 같은 부분집합)</br>
* **순열**은 원소의 중복을 허락하지 않으며 순서에 상관있다.(순서가 다르면 다른 부분집합)</br>
* **중복조합**은 원소의 중복을 허락하며 순서에 상관없다.(순서가 다르면 같은 부분집합)</br>
* **중복순열**은 원소의 중복을 허락하며 순서에 상관있다.(순서가 다르면 다른 부분집합)</br></br>

| 종류 | 중복 허락 | 순서 상관|
|:----:|:---------:|:---------:|
|조합|X|X|
|순열|X|O|
|중복조합|O|X|
|중복순열|O|O|
