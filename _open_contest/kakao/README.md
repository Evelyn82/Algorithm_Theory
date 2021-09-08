
## 21 Blind Recruitment

- [x] [신규 아이디 추천](https://github.com/evelyn82/Algorithm/blob/master/_open_contest/kakao/21_blind/id_recommendation.cpp)
- [x] [메뉴 리뉴얼](https://github.com/evelyn82/Algorithm/blob/master/_open_contest/kakao/21_blind/menu_renewal.cpp)
    > ![png](/_img/kakao21_blind_menu_renewal.png)<br>주문 1개당 최대 10가지의 메뉴가 가능하다.<br>course는 2이상 10이하이다.<br>최대 10가지 메뉴에서 2개부터 10개까지의 조합의 개수는 1013개이다.<br><br>최대 20개의 주문이 주어지므로 최악의 경우 1013 X 20 = 20260 번의 탐색을 하면된다.<br>map보다 속도가 빠른 unordered_map을 사용했다.<br>