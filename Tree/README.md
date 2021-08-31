
## Fenwick tree

- [x] boj_1275 커피숍 
    - using Fenwick tree : [https://github.com/evelyn82/Algorithm/blob/master/Tree/ps/boj_1275_fw.cpp](https://github.com/evelyn82/Algorithm/blob/master/Tree/ps/boj_1275_fw.cpp)
    - using Segment tree : [https://github.com/evelyn82/Algorithm/blob/master/Tree/ps/boj_1275_sgt.cpp](https://github.com/evelyn82/Algorithm/blob/master/Tree/ps/boj_1275_sgt.cpp)
- [x] [**_boj_1280 나무 심기_**](https://github.com/evelyn82/Algorithm/blob/master/Tree/ps/boj_1280.cpp)
    > 서로의 거리가 a, 2a+b, 3a+2b+c ... 처럼 선형이니깐 쉽게 풀 수 있을 것이라고 생각했는데, 주어지는 나무의 위치는 좌표 순으로 주어진다는 보장이 없다.<br>즉, 좌표를 기준으로 왼쪽에 있는, 오른쪽에 있는 나무의 위치를 따로 구해야 한다.<br>
- [x] [**_boj_2517 달리기_**](https://github.com/evelyn82/Algorithm/blob/master/Tree/ps/boj_2517.cpp)
    > 좌표압축을 하지 않아 에러가 발생함.
- [x] [boj_3653 영화 수집](https://github.com/evelyn82/Algorithm/blob/master/Tree/ps/boj_3653.cpp)
    > 가지고 있는 영화 수 n과 보려고 하는 영화 수 m은 최대 1e5개 주어진다.<br>fenwick tree를 이용해 현재 내가 보려고 하는 영화 index 앞에(문제에선 위) 몇개의 영화가 존재하는지 sum method로 구할 수 있다.<br>탐색 후 보려고 하는 영화를 맨 위에 놓아야 하므로 현재 fenwick tree에서 맨 앞에 있는 index 앞에 추가 시킨다.<br>즉, 초기설정을 보려고하는 영화 수만큼 0 ~ (m - 1) 만큼 비워두고 m index부터 영화 1부터 n까지 채워 앞으로 가져오면서 탐색하면 된다.<br>
- [x] [7578 공장](https://github.com/evelyn82/Algorithm/blob/master/Tree/ps/boj_7578.cpp)
    > 왼쪽부터 오른쪽 방향으로 lineA를 기준으로 lineB에 위치한 짝을 찾는다.<br>lineA의 맨 왼쪽부터 탐색하기 때문에 탐색 기준의 오른쪽에 있는 기계들은 신경쓰지 않아도 된다.<br>이미 탐색을 완료한 왼쪽 기계가 현재 탐색 기준의 lineB에 있는 짝보다 더 오른쪽에 연결된 경우 교차가 생기므로 연결 예정인 lineB index보다 오른쪽에 몇 개가 연결된 상태인지 count 하면 된다.<br>

## Segment tree

- [x] [boj_6549 히스토그램에서 가장 큰 직사각형](https://github.com/evelyn82/Algorithm/blob/master/Tree/ps/boj_6549.cpp)
    > ![png](/img/boj_6549.png)<br>segment tree에 범위 내에서 가장 작은 높이를 갖는 index를 저장한다.<br>분할정복 시 분할하는 기준을 범위 내에서 가장 작은 높이로 설정해 탐색하면 된다.<br>

- [x] [boj_2104 부분배열 고르기](https://github.com/evelyn82/Algorithm/blob/master/Tree/ps/boj_2104.cpp)
- [x] [boj_2243 사탕상자](https://github.com/evelyn82/Algorithm/blob/master/Tree/ps/boj_2243.cpp)