class Water {
public:
    int temperature;
    Water() {
        temperature = 0;
    }
    Water(int a) {
        temperature = a;
    }
};

class Teapot {
public:
    Water water;
    bool is_boiling() {
        if (water.temperature >= 100) return true;
        return false;
    }
    void heat_up(int a) {
        water.temperature += a;
    }
    Teapot(Water a) {
        water = a;
    }
};