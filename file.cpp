#include <bits/stdc++.h>
using namespace std;

int globaltime = 0; // global time
int n = 0; // no of planes

class Plane
{
    int id;
    int no_of_flights;
    int planetime;

public:
    Plane()
    {
        this->id = ++(::n);
        planetime = 0;
        no_of_flights = 0;
    }

    int fly(int t)
    {
        if ((planetime + t) > 1080)
        {
            return -1;
        }
        cout << "Plane " << this->id << " " << "flied for " << t << " minutes\n";
        planetime += t + 60;
        no_of_flights++;
        return planetime;
    }

    void wait(int t) {
        cout << "Plane " << this->id << " " << "waited for " << t << " minutes\n";
        planetime += t;
    }

    int get_curr_time() {
        return this -> planetime;
    }

    bool is_cool_off_required()
    {
        return (no_of_flights >= 3) ? true : false;
    }

    void cool_off()
    {
        planetime += 60;
        no_of_flights = 0;
    }
};

class Airline
{

private:
    int speed;
    vector<Plane> v;
    vector<vector<int>> dist;
    vector<vector<int>> time;
    vector<vector<int>> traffic;

public:
    Airline()
    {
        speed = 10;
        // v.resize(n, 0);
        dist.resize(n, vector<int>(n, -1));
        time.resize(n, vector<int> (n, 0));
        traffic.resize(n, vector<int>(n, -1));

        // initializing distance values
        dist[0][1] = 1000;
        dist[0][3] = 900;
        dist[0][4] = 2000;
        dist[0][6] = 2600;

        dist[1][0] = 1000;
        dist[1][2] = 1200;

        dist[2][1] = 1200;
        dist[2][6] = 2600;

        dist[3][6] = 2000;
        dist[4][5] = 400;
        dist[4][6] = 2600;

        dist[5][4] = 400;

        dist[6][0] = 2500;
        dist[6][2] = 2600;
        dist[6][3] = 2000;
        dist[6][4] = 2600;

        // initialize traffic

        // itnitialize time values

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][j] != -1)
                {
                    time[i][j] = (dist[i][j] / speed);
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][j] != -1)
                    cout << time[i][j] << "    ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // Airline obj;

    Plane *p1 = new Plane();

    p1 -> fly(100);
    p1 -> wait(200);
    cout << p1 -> is_cool_off_required() << endl;
    cout << p1 -> get_curr_time();

    delete(p1);



}