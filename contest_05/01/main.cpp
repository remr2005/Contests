#include <iostream>
#include <stdlib.h>
#include <time.h>

class Cat {
public:
    int live{ -1 };
    bool is_alive() {
        if (live == 0) return true;
        else return false;
    }
}
;
class Box {
public:
    Cat cat;
    Cat open() {
        if (cat.live < 0) cat.live = rand() % 2;
        return cat;
    }
}
;