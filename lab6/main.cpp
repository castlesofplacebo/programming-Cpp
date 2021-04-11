#include <iostream>
#include <vector>
#include <iterator>
#include <set>
using namespace std;

/*Требуется реализовать следующие обобщенные алгоритмы.
2. any_of - возвращает true, если хотя бы один из элементов диапазона
удовлетворяет некоторому предикату. Иначе false

5. is_sorted - возвращает true, если все элементы диапазона находятся в
отсортированном порядке относительно некоторого критерия

9. is_palindrome - возвращает true, если заданная последовательность является
палиндромом относительно некоторого условия. Иначе false.*/

bool func (int x) {
    return x == 0;
}

bool sort (int x, int y) {
    return x < y;
}

bool Equal (int x, int y) {
    return x == y;
}

template <class conIterator, class obj>
bool any_of(conIterator begin, conIterator end, bool (&f) (obj)) {
    for (auto it = begin; it != end; ++it) {
        if (f(*it))
            return true;
    }
    return false;
}

template <class conIterator, class obj>
bool is_sorted(conIterator begin, conIterator end, bool (&f) (obj, obj)) {
    conIterator prev = begin;
    for (auto it = next(begin); it != end; ++it) {
        if (!f(*prev, *it))
            return false;
        prev = it;
    }
    return true;
}

template <class conIterator, class obj>
bool is_palindrome(conIterator begin, conIterator end, bool (&f) (obj, obj)) {
    conIterator first = begin;
    conIterator last = end;
    --last;
    do {
        if (!f(*first, *last))
            return false;
        ++first;
        --last;
    } while (first == last);

    return true;
}

int main() {
    vector<int> array = {1, 2, 3, 4, 4, 3, 2, 1};
    cout << "Any  number == 0 in array : " << any_of(array.begin(), array.end(),func) << endl;

    set <int> setCheck = {5, 4, 1, 2, 0};
    cout << "Any number == 0 in set : " << any_of(setCheck.begin(), setCheck.end(), func) << endl;

    cout << "Numbers in array are sorted : " << is_sorted(array.begin(), array.end(), sort) << endl;
    cout << "Numbers in set are sorted : " << is_sorted(setCheck.begin(), setCheck.end(), sort) << endl;

    cout << "Numbers in array are palindrome : " << is_palindrome(array.begin(), array.end(), Equal) << endl;
    cout << "Numbers in set are palindrome : " << is_palindrome(setCheck.begin(), setCheck.end(), Equal) << endl;

    return 0;
}