#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Car
{
public:
    int idx;
    int dis;

    Car(int idx, int dis)
    {

        this->idx = idx;
        this->dis = dis;
    }

    bool operator<(const Car &obj) const
    {

        return this->dis > obj.dis;
    }
};

void NearestCar(vector<pair<int, int>> pos, int k)
{

    int n = pos.size();
    vector<Car> cars;

    for (int i = 0; i < n; i++)
    {
        int dis = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        cars.push_back(Car(i, dis));
    }

    priority_queue<Car> pq(cars.begin(), cars.end());

    for (int i = 0; i < k; i++)
    {
        cout << "cars" << pq.top().idx << endl;
        pq.pop();
    }
}

int main()
{

    vector<pair<int, int>> pos;

    pos.push_back(make_pair(3, 3));
    pos.push_back(make_pair(5, -1));
    pos.push_back(make_pair(-2, 4));

    int k = 2;

    NearestCar(pos, k);

    return 0;
}