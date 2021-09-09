
## 21 Blind Recruitment

- [x] [신규 아이디 추천](https://github.com/evelyn82/Algorithm/blob/master/_open_contest/kakao/21_blind/id_recommendation.cpp)
- [x] [메뉴 리뉴얼](https://github.com/evelyn82/Algorithm/blob/master/_open_contest/kakao/21_blind/menu_renewal.cpp)
    > ![png](/_img/kakao21_blind_menu_renewal.png)<br>주문 1개당 최대 10가지의 메뉴가 가능하다.<br>course는 2이상 10이하이다.<br>최대 10가지 메뉴에서 2개부터 10개까지의 조합의 개수는 1013개이다.<br><br>최대 20개의 주문이 주어지므로 최악의 경우 1013 X 20 = 20260 번의 탐색을 하면된다.<br>map보다 속도가 빠른 unordered_map을 사용했다.<br>

- [x] [순위 검색](https://github.com/evelyn82/Algorithm/blob/master/_open_contest/kakao/21_blind/ranking_search.cpp)
- [x] [택시 요금](https://github.com/evelyn82/Algorithm/blob/master/_open_contest/kakao/21_blind/taxi_fare.cpp)
- [x] [광고 삽입](https://github.com/evelyn82/Algorithm/blob/master/_open_contest/kakao/21_blind/ad_insert.cpp)
    >![png](/_img/kakao21_blind_ad_insert.png)<br>ssacnf로 string에서 시간을 읽는 방법을 발견했지만 빠르지 않았다.<br>prefix sum으로 구현했는데 계산과정에서 마이너스 값이 발생하므로 prefix sum을 두번한 다음 탐색했다.<br>더 자세한 내용은 게시물로 올릴 예정.<br>

- [x] [카드 짝 맞추기](https://github.com/evelyn82/Algorithm/blob/master/_open_contest/kakao/21_blind/card_matching.cpp)
    > 다음 탐색에서 A라는 2장의 카드를 선택하겠다.<br>그러면 현재 지점에서 A라는 2장의 카드로 가는 경로를 구하고(dist1(line65), dist2(line66)) 2개의 카드 중 다음 탐색의 시작점을 어디로 할 것인지 정한다.<br>다음 탐색의 기준은 BackTracking으로 answer이 더 적은 쪽을 선택한다.<br><br>여기서 2장의 카드 중 어떤 카드를 선택해도 둘 사이의 answer를 구해야 한다.<br>계속 에러가 났던 부분이 이 부분이다.<br>둘 사이의 answer는 어느 점을 기준으로 해도 동일할 것이라고 생각하는데 해당 개념은 정답처리가 되지 않으며, **아직도 왜인지 이유를 알지 못한다.**<br>기준점을 따로해 계산해준 결과 정답처리가 되었다.<br>