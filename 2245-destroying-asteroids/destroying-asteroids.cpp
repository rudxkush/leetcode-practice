class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(), asteroids.end());
        int count = 0;
        long long blah = mass;
        for (int i = 0; i < n; i++) {
            if (blah >= asteroids[i]) {
                count++;
                blah += asteroids[i];
            }
        }
        return count == n ? true : false;
    }
};
/*
    mass_of_a_planet = 10
    asteroids = [3, 9, 19, 5, 21], asteroids[i] rep. the mass of ith asteroid

    if mass_of_a_planet >= asteroids[i]:
        getsDestroyed(asteroids[i]);
        mass_of_a_planet += asteroids[i];
    else:
        mass_of_a_planet = -1;
        return false;

    return true;

    3, 5, 9, 19, 21
    add all the elements that are lesser or equal to mass_of_a_planet

    5
    13+9-> 22
    4, 4, 9, 23

*/