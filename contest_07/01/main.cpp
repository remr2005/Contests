#include <iostream>

struct Time{
    short hours;
    short minutes;
    short seconds;
    
    void addSeconds(short count){
        seconds += count;
        if (seconds >= 60){
            count = seconds / 60;
            seconds %= 60;
        } else return;
        
        minutes += count;
        if (minutes >= 60){
            count = minutes / 60;
            minutes %= 60;
        } else return;
        
        hours += count;
        if (hours >= 60)
            hours = minutes = seconds = 0;
    }
};

bool operator==(const Time& lhs, const Time& rhs){
    return lhs.hours == rhs.hours &&
           lhs.minutes == rhs.minutes &&
           lhs.seconds == rhs.seconds;
}

bool operator!=(const Time& lhs, const Time& rhs){
    return not (lhs == rhs);
}

bool operator<(const Time& lhs, const Time& rhs){
    return lhs.hours * 3600 + lhs.hours * 60 + lhs.seconds < rhs.hours * 3600 + rhs.hours * 60 + rhs.seconds;
}

class IRunnable{
public:
    virtual void run() = 0;
};

class IClock{
public:
    virtual void add(IRunnable* client, Time time) = 0;
    virtual bool next() = 0;
};

#include<vector>

class Clock : public IClock, public IRunnable{
public:
    std :: vector<IRunnable*> arr;
    std :: vector<Time> arr_t;
    bool next(){
        if (arr.size() == 0) return false;
        return true;
    }
    void add(IRunnable* client, Time time){
        arr.push_back(client);
        arr_t.push_back(time);
    }
    void run(){
        int i = 0;
        while (next()){
            if (arr_t[i].hours <10) std :: cout << 0;
            std:: cout << arr_t[i].hours << ':';
            if (arr_t[i].minutes <10) std :: cout << 0;
            std:: cout << arr_t[i].minutes << ':';
            if (arr_t[i].seconds <10) std :: cout << 0;
            std:: cout << arr_t[i].seconds << ' ';
            arr[i]->run();
            arr.pop();
        }
    }
};

class OSUpdater : public IRunnable{
public:
    void run(){
        std :: cout << "OSUpdater\n";
    }    
};

class Alarm : public IRunnable{
public:
    void run(){
        std :: cout << "Alarm\n";
    }    
};

class ActivityChecker:  public IRunnable{
public:
    void run(){
        std :: cout << "ActivityChecker\n";
    }    
};

int main(){
    int monentum;
    std::cin >> monentum;
    srand(monentum);  // Фиксируем случайность
    
    IClock* clock = new Clock;
    IRunnable* timer = (Clock*)clock;
    
    Time t = {0, 0, 0}, midnight = {0, 0, 0};
    
    do{
        int type = rand() % 3;
        if (type == 0) clock->add(new OSUpdater, t);
        else if (type == 1) clock->add(new Alarm, t);
        else if (type == 2) clock->add(new ActivityChecker, t);
        t.addSeconds(3600 + rand() % 3600);
    }while(t != midnight);
    
    timer->run();
}