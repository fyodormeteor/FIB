/*  Mass center of particles moving at constant velocity
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<vector>
using namespace std;

void printDouble(double d)
{
    if (d < 1e-7 and d > -1e-7)
        cout << 0.0;
    else
        cout << d;
}

struct Point {
    double x, y, z;
};

struct Particle {
    Point p,v;
    double m;
};

typedef vector<Particle> Vec;

// Pre:
// Post: returns the sum of p1 and p2.
Point sum(Point p1, Point p2)
{
    Point result;
    result.x = p1.x + p2.x;
    result.y = p1.y + p2.y;
    result.z = p1.z + p2.z;
    return result;
}

// Pre:
// Post: returns a times p.
Point mul(double a, Point p)
{
    Point result;
    result.x = a*p.x;
    result.y = a*p.y;
    result.z = a*p.z;
    return result;
}

// Pre:
// Post: returns the mass center "particle" based on the Particle type vector
Particle getMassCenterParticle(Vec& particles, int n)
{
    Point pos;
    Point vel;
    pos.x = pos.y = pos.z = 0.0;
    vel.x = vel.y = vel.z = 0.0;
    double total_mass = 0.0;
    
    for(int i = 0; i < n; ++i)
    {
        total_mass += particles[i].m;

        pos = sum(mul(particles[i].m, particles[i].p), pos);
        vel = sum(mul(particles[i].m, particles[i].v), vel);
    }
    total_mass = 1/total_mass;
    pos = mul(total_mass, pos);
    vel = mul(total_mass, vel);

    Particle mass_center;
    mass_center.p = pos;
    mass_center.v = vel;
    mass_center.m = 0.0; // Mass of the mass center doesn't matter
    return mass_center;
}

// Pre:
// Post: moves a particle by time t and prints its position
void moveParticleAndPrint(Particle& part, double t)
{
    part.p = sum(mul(t, part.v), part.p);

    printDouble(part.p.x);
    cout << ' ';
    printDouble(part.p.y);
    cout << ' ';
    printDouble(part.p.z);
    cout << '\n';
}

// Pre:
// Post: moves all the particles in Particle type vector by time t and prints their position
void moveAllParticlesAndPrint(Vec& particles, int n, double t)
{
    for(int i = 0; i < n; ++i)
    {
        particles[i].p = sum(mul(t, particles[i].v), particles[i].p); // Move particle by v*t

        printDouble(particles[i].p.x);
        cout << ' ';
        printDouble(particles[i].p.y);
        cout << ' ';
        printDouble(particles[i].p.z);
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);    
    cout.setf(ios::fixed);
    cout.precision(5);

    int n, k;
    while(cin >> n >> k)
    {
        // Load particles into a type Particle vector
        Vec particles(n);
        for(int i = 0; i < n; ++i)
        {
            Particle load;
            cin >> load.p.x >> load.p.y >> load.p.z >> load.v.x >> load.v.y >> load.v.z >> load.m;
            particles[i] = load;
        }
        
        Particle mass_center = getMassCenterParticle(particles, n); // Get mass center particle

        // Move mass center by each time value, and after each movement, print the mass center position.
        int total_time = 0;
        for(int i = 0; i < k; ++i)
        {
            int t;
            cin >> t;
            total_time += t;
            moveParticleAndPrint(mass_center, t);
        }
        
        // Move particles by the sum of all times and print final positions
        moveAllParticlesAndPrint(particles, n, total_time);

        cout << '\n';
    }
}