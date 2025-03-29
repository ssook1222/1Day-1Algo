# 3월 5주차 문제 풀이 기록

- 최소 1주일에 1번은 문제 풀이 진행하기
- 문제 풀이 1번에 3문제는 풀기 (단, 최소 1문제는 중급 난이도)
- 성능 향상이 가능해 보이는 쿼리의 경우 나중에 따로 Keep해두기
- 문제 풀었을 때의 기록 외에도 왜 그렇게 작성했는지 생각해보기

### 헤비 유저가 소유한 장소

```sql
WITH HEAVY_USER AS
(
SELECT HOST_ID
FROM PLACES
GROUP BY HOST_ID
HAVING COUNT(ID) > 1
)

SELECT ID, NAME, A.HOST_ID
FROM PLACES A, HEAVY_USER 
WHERE A.HOST_ID = HEAVY_USER.HOST_ID
ORDER BY ID ASC
```

### 물고기 종류 별 대어 찾기

```sql
WITH ML AS (
    SELECT      MAX(LENGTH) AS LENGTH
                , FISH_TYPE
    FROM        FISH_INFO
    GROUP BY    FISH_TYPE
),
MN AS (
    SELECT  ID
            , ML.FISH_TYPE
            , ML.LENGTH
            , TIME
    FROM    FISH_INFO I INNER JOIN ML ON I.LENGTH = ML.LENGTH AND I.FISH_TYPE = ML.FISH_TYPE
)

SELECT      ID
            , FISH_NAME
            , LENGTH
FROM        FISH_NAME_INFO FNI INNER JOIN MN ON FNI.FISH_TYPE = MN.FISH_TYPE
ORDER BY    ID
```

### 연도별 대장균 크기의 편차 구하기

```sql
WITH A AS (
    SELECT  YEAR(DIFFERENTIATION_DATE) AS YEAR,
            MAX(SIZE_OF_COLONY) AS LARGEST
    FROM    ECOLI_DATA
    GROUP BY YEAR(DIFFERENTIATION_DATE)
)

SELECT  YEAR(E.DIFFERENTIATION_DATE) AS YEAR,
        A.LARGEST - E.SIZE_OF_COLONY AS YEAR_DEV,
        E.ID
FROM    ECOLI_DATA E 
INNER JOIN A ON YEAR(E.DIFFERENTIATION_DATE) = A.YEAR
ORDER BY YEAR, YEAR_DEV
```