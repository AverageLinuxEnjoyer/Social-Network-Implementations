#include <cassert>
#include <iostream>

#include "../include/Tests.h"
#include "../include/MultiDictionary.h"
#include "../include/Set.h"

void test_multi_dictionary() {
    MultiDictionary<int, int> multi_dictionary;

    multi_dictionary.put(1, 1);
    assert(multi_dictionary.get(1)[0] == 1);
    assert(multi_dictionary.contains(1));
    
    multi_dictionary.put(1, 2);
    assert(multi_dictionary.get(1)[0] == 2);
    assert(multi_dictionary.get(1)[1] == 1);
    assert(multi_dictionary.contains(1));

    assert(multi_dictionary.get(2) == std::vector<int>());

    multi_dictionary.remove(1, 1);
    assert(multi_dictionary.get(1)[0] == 2);

    multi_dictionary.remove(1);
    assert(multi_dictionary.get(1) == std::vector<int>());

    assert(!multi_dictionary.contains(1));

    std::cout << "MultiDictionary tests passed.\n";
}


void test_set() {
    Set<int> set;

    set.add(1);
    assert(set.contains(1));

    set.add(2);
    assert(set.contains(2));

    set.add(1);
    assert(set.contains(1));

    set.remove(5);
    assert(!set.contains(5));

    set.remove(1);
    assert(!set.contains(1));

    assert(set.size() == 1);

    std::cout << "Set tests passed.\n";
}

void tests() {
    test_multi_dictionary();
    test_set();

    std::cout << "All tests passed.\n";
}
