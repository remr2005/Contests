#include<iostream>
#include "json.hpp"
#include "fstream" 
using json = nlohmann::json;

int main() {
	int ID, sums;
	sums = 0;
	std::cin >> ID;
	std::ifstream f("data.json");
	json data = json::parse(f);
	for (auto i : data) {
		for (auto j : i["tasks"]) {
			if (j["user_id"] == ID and j["completed"]) {
				sums += 1;
			}
		}
	}
	std::cout << sums;
}