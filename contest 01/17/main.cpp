#include <iostream>
#include <vector>
int main() {
	long long n;
	long long local_max = 0;
	long long sum = 0;
	long long maxs = 0;
	long long maxs_i = 0;
	std::cin >> n;
	std::vector<long long> arr(n);
	for (int i = 0;i < n;i++) {
		std :: cin >> arr[i];
		if (arr[i] >= maxs){
		    maxs = arr[i];
		    maxs_i = i;
		}
	}
	local_max = arr[0];
	for (int i = 0; i < maxs_i;i++) {
		if(arr[i] > local_max){
		    local_max = arr[i];
		}
		sum+= local_max - arr[i]; 
	}
	local_max = arr[n-1];
	for (int i = n-1;maxs_i<i;i--) {
		if(arr[i] > local_max){
		    local_max = arr[i];
		}
		sum+= local_max - arr[i]; 
	}
	std::cout << sum;
}