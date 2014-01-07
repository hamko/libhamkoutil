#include <hamkoutil.hpp>

main()
{
    vi a = {3, 6, 9, 12};

    // for all it in a there exists j in [4, 5], *it can divided by j -> 0
    cout <<
        forall(all(a), [](vit it) {
            return thereexists(4, 5, [it](int j) {
                return !(*it % j);
            });
        })
    << endl;

    cout << forall(2, 3, [](int it) {return it > 2;}) << endl; // 0
    cout << forall(3, 4, [](int it) {return it > 2;}) << endl; // 1
    cout << forall(all(a), [](vit it) {return !(*it % 2);}) << endl; // 0
    cout << forall(all(a), [](vit it) {return !(*it % 3);}) << endl; // 1
    cout << thereexists(all(a), [](vit it) {return !(*it % 5);}) << endl; // 0
    cout << thereexists(all(a), [](vit it) {return !(*it % 12);}) << endl; // 1
}
