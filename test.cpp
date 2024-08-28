#include <iostream>
#include <vector>
using namespace std;

int check_prime(long long n)
{
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;

    for (long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

int main() {
    long long m; cin >> m;
    long long n; cin >> n;
    long long counter = 0;
    vector<long long>result;
    for (long long i = m; i <= n; i++)
    {
        if (check_prime(i))
        {
            result.push_back(i);
            counter++;
        }
    }
    if (counter == 0)
        cout << "Absent" << '\n';
    else
    {
        for (long long i = 0; i < result.size(); i++)
            cout << result[i] << '\n';
    }
    return 0;
}