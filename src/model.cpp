#include "model.h"
#include "types.h"

double mass(person &s)
{
    double m = 0;
    for (double c : s)
        m += c;

    return m;
}

double dist(person &s1 ,person &s2)
{
    double d = 0;
    if (s1.size() != s2.size())
        return -1;

    int size = s1.size();

    for (int i = 0; i < size; ++i)
        d += (s1[i] - s2[i])*(s1[i] - s2[i]);

    return sqrt(d);
}

double force(person &s1, person &s2)
{
    return (mass(s1)*mass(s2))/(dist(s1,s2)*dist(s1,s2));
}
