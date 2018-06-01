//
// Created by James Lansdown on 5/31/18.
//

#ifndef BIGNUMBER_1_BIGNUMBER_H
#define BIGNUMBER_1_BIGNUMBER_H


#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int BASE = 1000000000;
const int BASE_DIGITS = 9;

class BigNumber {

private:
    vector<int> number;
    int sign;

protected:
    //Helper Functions

    //helper constructor
    BigNumber(long long rhs) {
        *this = rhs;
    }


    void operator=(long long v) {
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / BASE)
            number.push_back(v % BASE);
    }


    void operator*=(int rhs) {
        if (rhs < 0)
            sign = -sign, rhs = -rhs;
        for (int i = 0, carry = 0; i < (int) number.size() || carry; ++i) {
            if (i == (int) number.size())
                number.push_back(0);
            long long cur = number[i] * (long long) rhs + carry;
            carry = (int) (cur / BASE);
            number[i] = (int) (cur % BASE);
            //asm("divl %%ecx" : "=number"(carry), "=d"(number[i]) : "A"(cur), "c"(BASE));
        }
        trim();
    }


    friend pair<BigNumber, BigNumber> divMod(const BigNumber& lhs, const BigNumber& rhs) {
        int norm = BASE / (rhs.number.back() + 1);
        BigNumber a = lhs.abs() * norm;
        BigNumber b = rhs.abs() * norm;
        BigNumber q, r;
        q.number.resize(a.number.size());

        for (int i = a.number.size() - 1; i >= 0; i--) {
            r *= BASE;
            r += a.number[i];
            int s1 = r.number.size() <= b.number.size() ? 0 : r.number[b.number.size()];
            int s2 = r.number.size() <= b.number.size() - 1 ? 0 : r.number[b.number.size() - 1];
            int d = ((long long) BASE * s1 + s2) / b.number.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.number[i] = d;
        }

        q.sign = lhs.sign * rhs.sign;
        r.sign = lhs.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }


    void operator/=(int rhs) {
        if (rhs < 0)
            sign = -sign, rhs = -rhs;
        for (int i = (int) number.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = number[i] + rem * (long long) BASE;
            number[i] = (int) (cur / rhs);
            rem = (int) (cur % rhs);
        }
        trim();
    }



    BigNumber operator/(int rhs) const {
        BigNumber res = *this;
        res /= rhs;
        return res;
    }

    int operator%(int rhs) const {
        if (rhs < 0)
            rhs = -rhs;
        int m = 0;
        for (int i = number.size() - 1; i >= 0; --i)
            m = (number[i] + m * (long long) BASE) % rhs;
        return m * sign;
    }

    void operator+=(const BigNumber& rhs) {
        *this = *this + rhs;
    }
    void operator-=(const BigNumber& rhs) {
        *this = *this - rhs;
    }
    void operator*=(const BigNumber& rhs) {
        *this = *this * rhs;
    }
    void operator/=(const BigNumber& rhs) {
        *this = *this / rhs;
    }

    bool operator<(const BigNumber& rhs) const {
        if (sign != rhs.sign)
            return sign < rhs.sign;
        if (number.size() != rhs.number.size())
            return number.size() * sign < rhs.number.size() * rhs.sign;
        for (int i = number.size() - 1; i >= 0; i--)
            if (number[i] != rhs.number[i])
                return number[i] * sign < rhs.number[i] * sign;
        return false;
    }

    bool operator>(const BigNumber& lhs) const {
        return lhs < *this;
    }
    bool operator<=(const BigNumber& lhs) const {
        return !(lhs < *this);
    }
    bool operator>=(const BigNumber& rhs) const {
        return !(*this < rhs);
    }
    bool operator==(const BigNumber& rhs) const {
        return !(*this < rhs) && !(rhs < *this);
    }
    bool operator!=(const BigNumber& rhs) const {
        return *this < rhs || rhs < *this;
    }

    void trim() {
        while (!number.empty() && !number.back())
            number.pop_back();
        if (number.empty())
            sign = 1;
    }

    bool isZero() const {
        return number.empty() || (number.size() == 1 && !number[0]);
    }

    BigNumber operator-() const {
        BigNumber res = *this;
        res.sign = -sign;
        return res;
    }

    BigNumber abs() const {
        BigNumber res = *this;
        res.sign *= res.sign;
        return res;
    }


    friend BigNumber gcd(const BigNumber& lhs, const BigNumber& rhs) {
        return rhs.isZero() ? lhs : gcd(rhs, lhs % rhs);
    }
    friend BigNumber lcm(const BigNumber& lhs, const BigNumber& rhs) {
        return lhs / gcd(lhs, rhs) * rhs;
    }

    void read(const string& str) {
        sign = 1;
        number.clear();
        int pos = 0;
        while (pos < (int) str.size() && (str[pos] == '-' || str[pos] == '+')) {
            if (str[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = str.size() - 1; i >= pos; i -= BASE_DIGITS) {
            int x = 0;
            for (int j = max(pos, i - BASE_DIGITS + 1); j <= i; j++)
                x = x * 10 + str[j] - '0';
            number.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream& stream, BigNumber& rhs) {
        string s;
        stream >> s;
        rhs.read(s);
        return stream;
    }


    static vector<int> convert_base(const vector<int>& rhs, int prev, int newDigits) {
        vector<long long> p(max(prev, newDigits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) rhs.size(); i++) {
            cur += rhs[i] * p[cur_digits];
            cur_digits += prev;
            while (cur_digits >= newDigits) {
                res.push_back(int(cur % p[newDigits]));
                cur /= p[newDigits];
                cur_digits -= newDigits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<long long> longVector;

    static longVector karatsubaMultiply(const longVector& lhs, const longVector& rhs) {
        int n = lhs.size();
        longVector res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += lhs[i] * rhs[j];
            return res;
        }

        int k = n >> 1;
        longVector a1(lhs.begin(), lhs.begin() + k);
        longVector a2(lhs.begin() + k, lhs.end());
        longVector b1(rhs.begin(), rhs.begin() + k);
        longVector b2(rhs.begin() + k, rhs.end());

        longVector a1b1 = karatsubaMultiply(a1, b1);
        longVector a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        longVector r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }


public:

    /**
     * function: BigNumber (Default Constructor)
     * purpose: Initializes every object with default data values
     */
    BigNumber() : sign(1) {
    }


    /**
     * function: BigNumber (string)
     * purpose: Initializes desired object with specified string data
     */
    BigNumber(const string &s) {
        read(s);
    }


    /**
     * function: overloaded =
     * purpose: sets the value of a BigNumber object to abother BigNumber object
     */
    void operator=(const BigNumber &rhs) {
        sign = rhs.sign;
        number = rhs.number;
    }


    /**
     * function: overloaded +
     * purpose: performs addition between two BigNumbers
     */
    BigNumber operator+(const BigNumber &rhs) const {
        if (sign == rhs.sign) {
            BigNumber res = rhs;

            for (int i = 0, carry = 0; i < (int) max(number.size(), rhs.number.size()) || carry; ++i) {
                if (i == (int) res.number.size())
                    res.number.push_back(0);
                res.number[i] += carry + (i < (int) number.size() ? number[i] : 0);
                carry = res.number[i] >= BASE;
                if (carry)
                    res.number[i] -= BASE;
            }
            return res;
        }
        return *this - (-rhs);
    }


    /**
     * function: overloaded -
     * purpose: performs subtraction between two BigNumbers
     */
    BigNumber operator-(const BigNumber &rhs) const {
        if (sign == rhs.sign) {
            if (abs() >= rhs.abs()) {
                BigNumber res = *this;
                for (int i = 0, carry = 0; i < (int) rhs.number.size() || carry; ++i) {
                    res.number[i] -= carry + (i < (int) rhs.number.size() ? rhs.number[i] : 0);
                    carry = res.number[i] < 0;
                    if (carry)
                        res.number[i] += BASE;
                }
                res.trim();
                return res;
            }
            return -(rhs - *this);
        }
        return *this + (-rhs);
    }

    BigNumber operator*(int rhs) const {
        BigNumber res = *this;
        res *= rhs;
        return res;
    }


    /**
     * function: overloaded /
     * purpose: performs division between two BigNumbers
     */
    BigNumber operator/(const BigNumber &rhs) const {
        return divMod(*this, rhs).first;
    }


    /**
     * function: overloaded %
     * purpose: performs modulus between two BigNumbers
     */
    BigNumber operator%(const BigNumber &rhs) const {
        return divMod(*this, rhs).second;
    }


    /**
     * function: overloaded <<
     * purpose: allow user to print out value stored in a BigNumber object
     */
    friend ostream& operator<<(ostream &stream, const BigNumber &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.number.empty() ? 0 : v.number.back());
        for (int i = (int) v.number.size() - 2; i >= 0; --i)
            stream << setw(BASE_DIGITS) << setfill('0') << v.number[i];
        return stream;
    }


    /**
     * function: overloaded *
     * purpose: performs multiplication between two BigNumbers
     */
    BigNumber operator*(const BigNumber& rhs) const {
        vector<int> a6 = convert_base(this->number, BASE_DIGITS, 6);
        vector<int> b6 = convert_base(rhs.number, BASE_DIGITS, 6);
        longVector a(a6.begin(), a6.end());
        longVector b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        longVector c = karatsubaMultiply(a, b);
        BigNumber res;
        res.sign = sign * rhs.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.number.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.number = convert_base(res.number, 6, BASE_DIGITS);
        res.trim();
        return res;
    }
};
#endif //BIGNUMBER_1_BIGNUMBER_H
