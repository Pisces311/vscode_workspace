#include <bits/stdc++.h>
using namespace std;

class SuffixArray {
   public:
    using size_type = unsigned;
    using pointer = size_type*;
    using const_pointer = const size_type*;

   private:
    template <typename It>
    inline static void get_sbuk(It s, pointer sbuk, size_type n, size_type m) {
        std::fill_n(sbuk, m, 0);
        for (size_type i = 0; i < n; ++i) ++sbuk[s[i]];
        std::partial_sum(sbuk, sbuk + m, sbuk);
    }

    inline static void lbuk_to_sbuk(const_pointer lbuk, pointer sbuk,
                                    size_type n, size_type m) {
        std::copy_n(lbuk + 1, m - 1, sbuk);
        sbuk[m - 1] = n;
    }

    inline static void sbuk_to_lbuk(pointer lbuk, const_pointer sbuk,
                                    size_type n, size_type m) {
        std::copy_n(sbuk, m - 1, lbuk + 1);
        lbuk[0] = 0;
    }

    template <bool Stage, typename It>
    inline static void induced_sort(It s, pointer sa, pointer lbuk,
                                    pointer sbuk, size_type n, size_type m) {
        constexpr size_type mask = size_type(1)
                                   << (CHAR_BIT * sizeof(size_type) - 1);
        using value_type = typename std::iterator_traits<It>::value_type;
        value_type prev = s[n - 1], cur;
        pointer ptr = sa + lbuk[prev];
        *ptr++ = n - 1;
        for (size_type p, i = 0; i < n; ++i) {
            if ((p = sa[i] - 1) & mask) continue;
            if ((cur = s[p]) < s[p + 1]) {
                sa[i] = ~p;
                continue;
            }
            if (cur != prev) {
                lbuk[prev] = ptr - sa;
                ptr = sa + lbuk[prev = cur];
            }
            *ptr++ = p;
            if (!Stage) sa[i] = 0;
        }
        ptr = sa + sbuk[prev = 0];
        sbuk_to_lbuk(lbuk, sbuk, n, m);
        for (size_type p, i = n; i-- > 0;) {
            if ((p = ~sa[i]) & mask) continue;
            if ((cur = s[p]) > s[p + 1]) {
                sa[i] = p + 1;
                continue;
            }
            if (cur != prev) {
                sbuk[prev] = ptr - sa;
                ptr = sa + sbuk[prev = cur];
            }
            *--ptr = ~p + 1;
            sa[i] = Stage ? p + 1 : 0;
        }
    }

    template <typename It>
    inline static size_type fill_lms_char(It s, pointer sa, pointer mid,
                                          pointer sbuk, size_type n) {
        using value_type = typename std::iterator_traits<It>::value_type;
        const pointer len = mid;
        pointer pos = mid;
        value_type prev, cur = s[n - 1];
        for (size_type j = n - 1, i = n - 1; i > 0;) {
            do prev = cur;
            while (i > 0 && (cur = s[--i]) >= prev);
            if (cur >= prev) break;
            do prev = cur;
            while (i > 0 && (cur = s[--i]) <= prev);
            if (cur <= prev) break;
            const size_type p = i + 1;
            sa[--sbuk[s[p]]] = p;
            len[p / 2] = j - i;
            *--pos = j = p;
        }
        return mid - pos;
    }

    template <typename It>
    inline static void fill_lms_suffix(It s, pointer sa, const_pointer pos,
                                       pointer sbuk, size_type n, size_type m,
                                       size_type n0) {
        using value_type = typename std::iterator_traits<It>::value_type;
        value_type prev = m, cur;
        size_type j = n;
        for (size_type p, i = n0; i > 0;) {
            if ((cur = s[p = pos[sa[--i]]]) != prev) {
                const size_type b = sbuk[prev = cur];
                while (j > b) sa[--j] = 0;
            }
            sa[--j] = p;
        }
        while (j > 0) sa[--j] = 0;
    }

    template <typename It>
    inline static size_type rename(It s, pointer sa, const_pointer len,
                                   size_type n, size_type m, size_type n0) {
        for (size_type p, j = 0, i = 0; j < n0; ++i) {
            if ((p = sa[i]) != 0) {
                sa[i] = 0;
                sa[j++] = p;
            }
        }
        const pointer sa0 = sa, s0 = sa + n0;
        size_type m0 = 0, plen = 0;
        It ppos = s;
        for (size_type i = 0; i < n0; ++i) {
            const size_type p = sa[i], nlen = len[p / 2];
            if (nlen != plen || !std::equal(ppos, ppos + plen, s + p)) ++m0;
            s0[p / 2] = m0;
            ppos = s + p;
            plen = nlen;
        }
        for (size_type p, j = 0, i = 0; j < n0; ++i)
            if ((p = s0[i]) != 0) s0[j++] = p - 1;
        return m0;
    }

   public:
    template <typename It>
    static void suffix_sort(It s, pointer sa, pointer buf, pointer lbuk,
                            pointer sbuk, size_type n, size_type m) {
        static_assert(
            std::is_same_v<typename std::iterator_traits<It>::iterator_category,
                           std::random_access_iterator_tag>);
        std::fill_n(sa, n, 0);
        get_sbuk(s, sbuk, n, m);
        sbuk_to_lbuk(lbuk, sbuk, n, m);
        const pointer mid = buf + n / 2;
        const size_type n0 = fill_lms_char(s, sa, mid, sbuk, n);
        const pointer len = mid, pos = mid - n0;
        lbuk_to_sbuk(lbuk, sbuk, n, m);
        induced_sort<0>(s, sa, lbuk, sbuk, n, m);
        const size_type m0 = rename(s, sa, len, n, m, n0);
        const pointer sa0 = sa, s0 = sa + n0;
        if (m0 < n0)
            suffix_sort(s0, sa0, mid, sbuk, sbuk + m0, n0, m0);
        else
            for (size_type i = 0; i < n0; ++i) sa0[s0[i]] = i;
        lbuk_to_sbuk(lbuk, sbuk, n, m);
        fill_lms_suffix(s, sa, pos, sbuk, n, m, n0);
        induced_sort<1>(s, sa, lbuk, sbuk, n, m);
    }

   private:
    std::unique_ptr<size_type[]> data;

   public:
    const const_pointer sa, rk, ht;

   public:
    template <typename It>
    SuffixArray(It s, size_type n, size_type m)
        : data(new size_type[3 * n]), sa(data.get()), rk(sa + n), ht(rk + n) {
        const pointer sa = data.get(), rk = sa + n, ht = rk + n;
        const unique_ptr<size_type[]> lbuk(new size_type[m]);
        if (m <= n)
            suffix_sort(s, sa, rk, lbuk.get(), ht, n, m);
        else {
            const unique_ptr<size_type[]> sbuk(new size_type[m]);
            suffix_sort(s, sa, rk, lbuk.get(), sbuk.get(), n, m);
        }
        for (size_type i = 0; i < n; ++i) rk[sa[i]] = i;
        for (size_type k = 0, i = 0; i < n; ++i) {
            if (rk[i] == 0) continue;
            if (k > 0) --k;
            const size_type j = sa[rk[i] - 1];
            const size_type l = n - std::max(i, j);
            for (; k < l; ++k)
                if (s[i + k] != s[j + k]) break;
            ht[rk[i]] = k;
        }
    }

    template <typename S>
    SuffixArray(const S& s, size_type m)
        : SuffixArray(std::data(s), std::size(s), m) {}
};

template <typename T, typename Op>
class SparseTable {
   public:
    using value_type = T;
    using size_type = unsigned;

   private:
    Op op;
    size_type n;
    std::unique_ptr<value_type[]> data;

    static constexpr size_type log2(size_type n) {
        return 31 - __builtin_clz(n);
    }

    static constexpr size_type log(size_type n) {
        return n > 1 ? log2(n - 1) + 1 : n;
    }

    void build() {
        const auto ptr = data.get();
        for (size_type i = 1; (1 << i) < n; ++i) {
            const auto pre = ptr + n * (i - 1);
            const auto cur = ptr + n * i;
            const size_type d = 1 << (i - 1);
            const size_type m = n - (1 << i);
            for (size_type j = 0; j <= m; ++j) cur[j] = op(pre[j], pre[j + d]);
        }
    }

   public:
    template <typename It>
    SparseTable(It s, size_type n, const Op& op = Op{})
        : op(op), n(n), data(std::make_unique<value_type[]>(n * log(n))) {
        const auto ptr = data.get();
        std::copy_n(s, n, ptr);
        build();
    }

    template <typename S>
    SparseTable(const S& s, const Op& op = Op{})
        : SparseTable(std::data(s), std::size(s), op) {}

    value_type query(size_type l, size_type r,
                     const value_type& unitary = value_type{}) const {
        if (r <= l) return unitary;
        const size_type h = log(r - l) - 1;
        const auto row = data.get() + n * h;
        return op(row[l], row[r - (1 << h)]);
    }
};

template <typename It, typename Op>
SparseTable(It, std::size_t, const Op&)
    -> SparseTable<typename std::iterator_traits<It>::value_type, Op>;

template <typename S, typename Op>
SparseTable(const S& s, const Op& op) -> SparseTable<
    typename std::iterator_traits<decltype(std::begin(s))>::value_type, Op>;

class Solution {
   public:
    int deleteString(string s) {
        const int n = s.size();
        int dp[n];
        SuffixArray sa(s, 128);
        SparseTable st(sa.ht, n, [](int x, int y) { return min(x, y); });
        for (int i = n - 1; 0 <= i; --i) {
            dp[i] = 1;
            for (int j = i + 1; 2 * j - i <= n; ++j) {
                const auto [l, r] = minmax(sa.rk[i], sa.rk[j]);
                if (j - i <= st.query(l + 1, r + 1, n))
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return dp[0];
    }
};