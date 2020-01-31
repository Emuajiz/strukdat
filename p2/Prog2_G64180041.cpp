#include <bits/stdc++.h>
using namespace std;

int what(vector <int> v, int n)
{
    int i;
    int m = v[0];
    for (i = 1; i < n; i++)
    if (v[i] > m)
    m = v[i];
    return m;
}
int main()
{
    int n, tmp;
    vector<int> v;
    cout << "masukkan jumlah vector:";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "masukkan nilai ke " << i+1 << ":" << endl;
        cin >> tmp;
        v.push_back(tmp);
    }
    cout << "Hasilnya adalah : "
    << what(v, n);
    return 0;
}