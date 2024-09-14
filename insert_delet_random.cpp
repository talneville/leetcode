#include <stdlib.h>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
    private:
        unordered_map<int, int> u_map;
        vector<int> vec;

    public:
        RandomizedSet() {}

        bool insert(int val) {
            if (u_map.find(val) != u_map.end()) {
                return false; 
            }
            vec.push_back(val); 
            u_map[val] = vec.size() - 1; 
            return true;
        }

        bool remove(int val) {
            if (u_map.find(val) == u_map.end()) {
                return false; 
            }
            int val_position = this->u_map[val];
            this->vec[val_position] = this->vec.back();
            this->u_map[this->vec.back()] = val_position;
            vec.pop_back(); 
            u_map.erase(val);

            return true;
        }

        int getRandom() {
            int random = rand() % (this->vec.size());
            return this->vec[random];
        }
};