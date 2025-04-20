#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_tab(int **tab, int w, int k) {
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < k; j++)
            cout << tab[i][j] << ' ';
        cout << endl;
    }
    //cout << endl;
}

void rotate(vector<int>& v) {
    if(!v.empty())
        rotate(v.begin(), v.end() - 1, v.end());
}

void copy_circuit(vector<int>& v, int **t, int x, int y) {
    for(int i = 0; i < x - 1; i++)
        v.push_back(t[i][0]);
    
    for(int i = 0; i < y - 1; i++)
        v.push_back(t[x - 1][i]);
    
    for(int i = x - 1; i >= 0; i--)
        v.push_back(t[i][y - 1]);

    for(int i = y - 2; i > 0; i--)
        v.push_back(t[0][i]);
}

void paste_circuit(vector<int>& v, int **t, int x, int y) {
    for(int i = 0; i < x - 1; i++) {
        t[i][0] = v.front();
        v.erase(v.begin());
    }

    for(int i = 0; i < y - 1; i++) {
        t[x - 1][i] = v.front();
        v.erase(v.begin());
    }
    
    for(int i = x - 1; i >= 0; i--) {
        t[i][y - 1] = v.front();
        v.erase(v.begin());
    }
            
    for(int i = y - 2; i > 0; i--) {
        t[0][i] = v.front();
        v.erase(v.begin());
    }
}

int main() {
    int n;
    cin >> n;
    int ***T = new int **[n];
    int *sizes_x = new int[n]; 
    int *sizes_y = new int[n]; 

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        
        if (x < 2 || y < 2) {
            T[i] = nullptr;
            sizes_x[i] = 0;
            sizes_y[i] = 0;
            continue;
        }

        sizes_x[i] = x;
        sizes_y[i] = y;
        
        int** t = new int*[x];

        for(int j = 0; j < x; j++)
            t[j] = new int[y];

        for(int j = 0; j < x; j++)
            for(int k = 0; k < y; k++)
                cin >> t[j][k];
        
        vector<int> v;
        copy_circuit(v, t, x, y);
        rotate(v);
        paste_circuit(v, t, x, y);
        
        if (T[i] != nullptr) {
            for(int j = 0; j < sizes_x[i]; j++)
                delete[] T[i][j];
            delete[] T[i];
        }
        T[i] = t;

        print_tab(T[i], x, y);
    // cout << endl;
    }

    for(int i = 0; i < n; i++) {
        if (T[i] != nullptr) {
            print_tab(T[i], sizes_x[i], sizes_y[i]);
        }
    }

    for(int i = 0; i < n; i++) {
        if (T[i] != nullptr) {
            for(int j = 0; j < sizes_x[i]; j++)
                delete[] T[i][j];
            delete[] T[i];
        }
    }
    delete[] T;
    delete[] sizes_x;
    delete[] sizes_y;

    return 0;
}