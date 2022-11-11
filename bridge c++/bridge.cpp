#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdlib.h>
using namespace std;
vector<int> shellSort(vector<int> vet, int size)
{
    int i, j, value;
    int h = 1;
    while (h < size)
    {
        h = 3 * h + 1;
    }
    while (h > 0)
    {
        for (i = h; i < size; i++)
        {
            value = vet[i];
            j = i;
            while (j > h - 1 && value <= vet[j - h])
            {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = value;
        }
        h = h / 3;
    }
    return vet;
}

int main()
{
    vector<int> v;
    vector<int> vEnd;
    vector<int> vOut;
    int cont = 0;

    int nCases, nPeople, aux;
    cin >> nCases;
    char c;
    // getchar();
    for (int i = 0; i < nCases; i++)
    {
        // cin >> c;
        cin >> nPeople;
        for (int j = 0; j < nPeople; j++)
        {
            cin >> aux;
            v.push_back(aux);
        }
        v = shellSort(v, v.size());
        while (vEnd.size() != nPeople)
        {
            // cout << v[0] << " " << v[1] << endl;
            vOut.push_back(v[0]);
            vOut.push_back(v[1]);
            cont += v[1];
            vEnd.push_back(v[0]);
            vEnd.push_back(v[1]);
            v.erase(v.begin());
            v.erase(v.begin());
            if (!v.empty())
            {
                vEnd = shellSort(vEnd, vEnd.size());
                v.push_back(vEnd[0]);
                // cout << vEnd[0] << endl;
                cont += vEnd[0];
                vOut.push_back(vEnd[0]);
                vEnd.erase(vEnd.begin());
            }
        }
        v.clear();
        vEnd.clear();
        cout << cont << endl;
        while (!vOut.empty())
        {
            cout << vOut[0] << " " << vOut[1] << endl;
            vOut.erase(vOut.begin());
            vOut.erase(vOut.begin());
            if (!vOut.empty())
            {
                cout << vOut[0] << endl;
                vOut.erase(vOut.begin());
            }
        }
        vOut.clear();
    }

    return 0;
}