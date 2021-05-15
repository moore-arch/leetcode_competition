//
// Created by shimeng on 2021/5/12.
//

#include "common.h"

using namespace std;

/**
 * 给你一个整数数组perm，它是前n个正整数的排列，且n是个奇数。
 * 它被加密成另一个长度为 n - 1的整数数组encoded，满足encoded[i] = perm[i] XOR perm[i + 1]。比方说，如果perm = [1,3,2]，那么encoded = [2,1]。
 * 给你encoded数组，请你返回原始数组perm。题目保证答案存在且唯一。
 *
 * 分析：加密后每项由两项异或构成：perm[0] prem[1], prem[1] prem[2], perm[2] perm[3], ...,
 *              perm[n-3] prem[n-2], perm[n-2] perm[n-1]
 * 当加密后序列全部进行异或运算后：中间每项都可以抵消，得到perm[0]^perm[n-1]，记为mask
 * 此时，设法消除res[0]或res[n]即可得到原序列中的一个，由此可以得到全部序列
 * 解决方式：n为奇数，n-1为偶数，观察加密后序列，依次异或encoded中的偶数项en[1] en[3] ... en[n-2]即
 *  可得到perm[1]^perm[2]^...^perm[n-1]的结果
 *  此时，再计算1-n共计n个数字的异或，即perm[0]^perm[1].....perm[n-1]
 *  将以上两项异或，得到perm[0]，与mask结合即可获取原perm数组中第一个或最后一个元素
 *
 * leetcode 1734解码异或后的排列
 * https://leetcode-cn.com/problems/decode-xored-permutation/
 * @param encoded
 * @return
 */
vector<int> decode(const vector<int>& encoded) {
    const auto N = encoded.size() + 1;
    int mask = 0;
    for (const int item : encoded) {
        mask ^= item;
    }
    int total_xor = 0;
    for (int i = 1; i <= N; ++i) {
        total_xor ^= i;
    }
    int even_xor = 0;
    for (int i = 1; i < encoded.size(); i += 2) {
        even_xor ^= encoded[i];
    }
    vector<int> res(N);
    // mask = perm[n-1]
    res[N-1] = (mask ^ total_xor ^ even_xor);
    res[0] = mask ^ res[N-1];
    for (int i = 1; i < N; ++i) {
        res[i] = res[i-1]^encoded[i-1];
    }

    return res;
}
/**
 * i i+1, i+1 i+2, i+2 i+3, ..., n-2 n-1, n-1 n.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    auto res = decode({6,5,4,6});
    string s;
    for (int item : res) {
        s.append(to_string(item) + "-");
    }
    s.pop_back();
    cout << s << endl;

    return 0;
}