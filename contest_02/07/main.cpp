Student make_student(std::string a) {
    Student res;
    int i = 0;
    a += ";";
    std::string str = "";
    Course cour;
    for (auto s : a) {
        if (s == ';') {
            if (i == 0) {
                res.name = str;
            }
            else if (i == 1) {
                res.group = str;
            }
            else if (i % 3 == 2) {
                cour.name = str;
            }
            else if (i % 3 == 0) {
                cour.semester = std::stoi(str);
            }
            else {
                if (str == "1") cour.finished = true;
                if (str == "0") cour.finished = false;
                res.courses.push_back(cour);
            }
            str = "";
            i += 1;
        }
        else str += std::string(1, s);
    }
    return res;
}

bool is_upper(Student a, Student b) {
    if (a.group == b.group) {
        std::vector<std::string> c{ a.name,b.name };
        std::sort(c.begin(), c.end());
        if (c[0] == b.name) return false;
        return true;
    }
    else {
        std::vector<std::string> c{ a.group,b.group };
        std::sort(c.begin(), c.end());
        if (c[0] == b.group) return false;
        return true;
    }
}

bool is_debtor(Student a, int cur, int max) {
    int sum = 0;
    for (int i = 0; i < a.courses.size();i++) {
        if ((a.courses[i].semester < cur) && (a.courses[i].finished == false)) sum += 1;
    }
    if (sum <= max) return false;
    return true;
}

void print(std::vector<Student> a) {
    if (a.empty()) { std::cout << "Empty list!"; }
    else {
        std::cout << a[0].group << '\n';
        for (int i = 0;i < a.size();i++) {
            std::cout << "- " << a[i].name << '\n';
            if (i == a.size() - 1) break;
            if (a[i].group != a[i + 1].group) std::cout << a[i + 1].group << '\n';
        }
    }
}