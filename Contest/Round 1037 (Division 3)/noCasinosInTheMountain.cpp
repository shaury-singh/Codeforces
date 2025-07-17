#include <iostream>
#include <vector>

using namespace std;

int noCasinosInTheMountain(vector<int>& weather, int k) {
    int n = weather.size();
    int badDays = 0;
    int result = 0;
    for (int i = 0; i < k; ++i) {
        if (weather[i] == 1) badDays++;
    }

    for (int i = 0; i <= n - k;) {
        if (badDays == 0) {
            result++;
            i += k + 1; 
            badDays = 0;
            for (int j = 0; j < k && i + j < n; ++j) {
                if (weather[i + j] == 1) badDays++;
            }
        } else {
            if (weather[i] == 1) badDays--;
            if (i + k < n && weather[i + k] == 1) badDays++;
            i++;
        }
    }

    return result;
}


int main(){
    // vector<int> weather = {0,1,0,1};
    // int k = 2;
    int testCases;
    cin >> testCases;
    for (int i=0; i<testCases; i++){
        vector<int> weather = {};
        int size;
        cin >> size;
        int k;
        cin >> k;
        for (int i=0; i<size; i++){
            int weatherE;
            cin >> weatherE;
            weather.push_back(weatherE);
        }
        cout << noCasinosInTheMountain(weather,k) << endl;
    }
    return 0;
}