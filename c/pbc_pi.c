/*
 * Author: Svitlana Orlova
 * Repository: https://github.com/svitlana-orlova/PI
 * Description:
 *
 * A bit impruved version of the famous PI digits generator
 * https://crypto.stanford.edu/pbc/notes/pi/code.html
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

int pbc_pi(int * dst, int len);

#ifdef SELF_TEST
int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    char const *pp = "\
3141592653589793238462643383279502884197169399375105\
8209749445923078164062862089986280348253421170679821\
4808651328230664709384460955058223172535940812848111\
7450284102701938521105559644622948954930381964428810\
9756659334461284756482337867831652712019091456485669\
2346034861045432664821339360726024914127372458700660\
6315588174881520920962829254091715364367892590360011\
3305305488204665213841469519415116094330572703657595\
9195309218611738193261179310511854807446237996274956\
7351885752724891227938183011949129833673362440656643\
0860213949463952247371907021798609437027705392171762\
9317675238467481846766940513200056812714526356082778\
5771342757789609173637178721468440901224953430146549\
5853710507922796892589235420199561121290219608640344\
1815981362977477130996051870721134999999837297804995\
10597317328160963185";

    int pi[801] = { 0 };
    int siz = 800;

    assert(pbc_pi(pi, siz) == siz);

    for (int i = 0; i < siz; i++) {
        int const t = pp[i] - '0';
        assert(t == pi[i]);
    }

    return 0;
}
#endif

int pbc_pi(int * dst, int len)
{
    int r[2800 + 1];
    int c = 0;
    int di = 0;
    int i, k, b, d;

    assert(len <= 800);

    for (i = 0; i < 2800; i++) {
        r[i] = 2000;
    }

    r[2800] = 0;

    for (k = 2800; k > 0; k -= 14) {
        d = 0;
        i = k;

        for (;;) {
            d += r[i] * 10000;
            b = 2 * i - 1;

            r[i] = d % b;
            d /= b;
            i--;
            if (i == 0) break;
            d *= i;
        }

        {
            int t = c + d / 10000;
            int tmp[4] = { 0 };
            int ti = 0;

            while (t > 0 && ti < 4) {
                tmp[ti] = t % 10;
                t /= 10;
                ti++;
            }

            for (t = 3; t >= 0 && len > 0; --t) {
                dst[di] = tmp[t];
                di++;
                len--;
            }

            if (len <= 0) {
                return di;
            }
        }

        c = d % 10000;
    }

    return di;
}
