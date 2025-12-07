#include <iostream>
#include <string>
#include <cmath>
using namespace std;


const int max_N = 15;
int price[max_N];
int taxed_price[max_N];
int total;
int N;

bool item[max_N];

bool item_taxed(int index, int sum){
        if (sum > total){
                return false;
        }
        if (index == N){
                return (sum == total);
        }
        item[index] = false;
        if (item_taxed(index + 1, sum + price[index])){
                return true;
        }
        item[index] = true;
        if (item_taxed(index + 1, sum + taxed_price[index])){
                return true;
        }

        return false;
}


int main(){
        cin >> N;
        for (int i = 0; i < N; i++){
                cin >> price[i];
        }
        cin >> total;

        for (int i = 0; i <= N; i++){
                taxed_price[i] = round(price[i] * 1.0625);
        }

        if (!item_taxed(0,0)){
                cout << "impossible" << endl;
                return 0;
        }

        bool should_print = false;
        for (int i = 0; i <= N; i++){
                if (item[i]){
                        if (should_print){
                                cout << " ";
                        }
                        cout << i + 1;
                        should_print = true;
                }
        }
        if (should_print == true){
                cout << endl;
        }
        return 0;
}
