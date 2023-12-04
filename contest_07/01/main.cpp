#include<vector>

class Clock : public IClock, public IRunnable {
public:
    std::vector<IRunnable*> arr;
    std::vector<Time> arr_t;
    bool next() {
        if (arr.size() == 0) return false;
        return true;
    }
    void add(IRunnable* client, Time time) {
        arr.push_back(client);
        arr_t.push_back(time);
    }
    void run() {
        int i = 0;
        while (next()) {
            if (arr_t[i].hours < 10) std::cout << 0;
            std::cout << arr_t[i].hours << ':';
            if (arr_t[i].minutes < 10) std::cout << 0;
            std::cout << arr_t[i].minutes << ':';
            if (arr_t[i].seconds < 10) std::cout << 0;
            std::cout << arr_t[i].seconds << ' ';
            arr[i]->run();
            arr.erase(arr.begin());
            arr_t.erase(arr_t.begin());
        }
    }
};

class OSUpdater : public IRunnable {
public:
    void run() {
        std::cout << "OSUpdater\n";
    }
};

class Alarm : public IRunnable {
public:
    void run() {
        std::cout << "Alarm\n";
    }
};

class ActivityChecker : public IRunnable {
public:
    void run() {
        std::cout << "ActivityChecker\n";
    }
};
