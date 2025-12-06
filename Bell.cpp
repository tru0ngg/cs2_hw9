#include <iostream>
#include <string>
using namespace std;

void print_indent(int d){
        for (int i = 0; i < d; i++){
                cout << "|   ";
        }
}

int stirling(int n, int k, int depth){
        print_indent(depth);
        cout << "-> Computing S(" << n << "," << k << ")" << endl;

        int result;

        if (n == k){
                result = 1;
        } else if (k == 0 && n > 0){
                result = 0;
        } else if (n == 0 && k > 0){
                result = 0;
        } else {
                int term1 = k * stirling(n - 1, k, depth + 1);
                int term2 = stirling(n - 1, k - 1, depth + 1);
                result = term1 + term2;
        }
        print_indent(depth);
        cout << "<- S(" << n << "," << k << ") = " << result << endl;

        return result;
}
int main() {
        string type;
        cin >> type;

        if (type == "Stirling"){
                int n, k;
                cin >> n >> k;
                stirling(n, k, 0);
        } else if (type == "Bell"){
                int n;
                cin >> n;
                int bell;
                if (n == 0){
                        bell = 0;
                } else {
                        for (int k = 0; k <= n; k++){
                                bell += stirling(n,k,0);
                        }
                }
                cout << "Bell " << n << " = " << bell << endl;
        } else {
                return 0;
        }
        return 0;
}
