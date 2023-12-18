#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class FoodRatings {
    unordered_map<string, int>food_rating;
    unordered_map<string, set<pair<int,string>>>cuisine_ratingFood;
    unordered_map<string, string>food_cuisine;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;++i){
            string f = foods[i];
            int r = ratings[i];
            string c = cuisines[i];

            food_rating[f] = r;
            food_cuisine[f] = c;
            cuisine_ratingFood[c].insert({-r,f});
        }
    }
    
    void changeRating(string food, int newRating) {
        int o = food_rating[food];
        food_rating[food] = newRating;

        string c = food_cuisine[food];
        cuisine_ratingFood[c].erase({-o,food});
        cuisine_ratingFood[c].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return cuisine_ratingFood[cuisine].begin()->second; 
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}