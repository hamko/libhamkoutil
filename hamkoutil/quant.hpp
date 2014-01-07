#include <hamkoutil.hpp>

template <class T, class LAMBDA>
bool forall(T b, T e, LAMBDA l) {
    int faf = 1;
    for (T it = b; it != e; it++) {
        if (!l(it)) {
            faf = 0;
            break;
        }
    }
    return faf;
}
template <class T, class LAMBDA>
bool thereexists(T b, T e, LAMBDA l)
{
    return !forall(b, e, [l](T it) {return !l(it);});
}
