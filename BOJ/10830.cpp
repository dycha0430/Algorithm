#include <iostream>
#include <memory.h>

using namespace std;

typedef long long ll;
ll* pow(ll b);
ll* mul(ll* mat1, ll* mat2);
void printMatrix(ll* mat);
ll N, B;
ll matrix[25];
int main(int argc, char const *argv[])
{
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i*N + j];
        }
    }

    ll* answer = pow(B);
    printMatrix(answer);
    
    return 0;
}

void printMatrix(ll* mat) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << mat[i * N + j] % 1000 << " ";
        }
        cout << endl;
    }
}

ll* pow(ll b) {
    if (b == 1) return matrix;
    else if (b%2 == 0) {
        long long* tmp = pow(b/2);
        ll* ret = mul(tmp, tmp);
        return ret;
    } else {
        ll* tmp = pow(b/2);
        ll* ret = mul(mul(tmp, tmp), matrix);
        return ret;
    }
}

ll* mul(ll* mat1, ll* mat2) {
    ll* ret = (ll*)malloc(sizeof(ll)*25);
    memset(ret, 0, sizeof(ll) * 25);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                ret[i * N + j] += mat1[i * N + k] * mat2[k * N + j];
                ret[i * N + j] %= 1000;
            }
        }
    }

    return ret;
}