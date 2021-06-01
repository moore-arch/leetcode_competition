#include "common.h"

using namespace std;
/**
 * 给你一个下标从 0 开始的正整数数组candiesCount，其中candiesCount[i]表示你拥有的第i类糖果的数目。
 * 同时给你一个二维数组queries，其中queries[i] = [favoriteType(i), favoriteDay(i), dailyCap(i)]。
 * 你按照如下规则进行一场游戏：
     * 你从第0天开始吃糖果。
     * 你在吃完所有第 i - 1 类糖果之前，不能吃任何一颗第i类糖果。
     * 在吃完所有糖果之前，你必须每天至少吃一颗糖果。
 * 请你构建一个布尔型数组answer，满足answer.length == queries.length 。
 * answer[i]为true的条件是：在每天吃不超过 dailyCap(i)颗糖果的前提下，你可以
 * 在第favoriteDay(i)天吃到第favoriteType(i)类糖果；否则 answer[i]为false。
 *
 * 注意，只要满足上面 3 条规则中的第二条规则，你就可以在同一天吃不同类型的糖果。
 *
 * 请你返回得到的数组answer。
 * @param candiesCount
 * @param queries
 * @return
 */
vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    const size_t CANDY_SIZE = candiesCount.size();
    vector<unsigned long long> record(CANDY_SIZE, 0);
    record[0] = candiesCount[0];
    for (unsigned i = 1; i < CANDY_SIZE; ++i) {
        record[i] = record[i - 1] + candiesCount[i];
    }

    const size_t QUERY_LENGTH = candiesCount.size();
    vector<bool> res(QUERY_LENGTH);
    for (unsigned i = 0; i < QUERY_LENGTH; ++i) {
        int favoriteType = queries[i][0];
        int favoriteDay = queries[i][1];
        int dailyCap = queries[i][2];

        // todo, fill code.
        res[i] = (favoriteDay < record[favoriteType] && record[favoriteDay] < dailyCap * favoriteDay)
                || ();
    }

    return res;
}

int main()
{
    return 0;
}