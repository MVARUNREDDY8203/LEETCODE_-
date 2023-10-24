class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currGas = 0, totalGas = 0, n = gas.size(), ans = 0;
        for (int i=0; i<n; i++) {
            totalGas += gas[i] - cost[i];
            currGas += gas[i] - cost[i];
            if (currGas < 0) {
                ans = i+1;
                currGas = 0;
            }
        }
        return totalGas >= 0 ? ans: -1;
    }
};


// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         if (n < 1) return 0;
//         if (n == 1) {
//             return gas[0] < cost[0] ? -1 : 0;
//         }
//         for (int i=0; i<n; i++) {
//             // if (gas[i] >= cost[i]) {
//             if (gas[i] == cost[i]) continue;
//             int k = 0;
//             int tank = 0;
//             for (int j=i; k < n; j++) {
//                 tank += gas[j%n] - cost[j%n];
//                 if (tank < 0) break;
//                 k++;
//             }
//             if (k == n && tank >= 0) return i;
//             // }
//         }
//         return -1;
//     }
// };








// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         if(n < 1) return n;
//         if(n == 1) return gas[0]<cost[0] ? -1: 0;
//         for(int i=0; i<n; i++){
//             int rem_fuel = 0;
//             if(gas[i] == cost[i]) continue;
//             bool round_trip = true;
//             for(int j=0; j<n; j++){
//                 rem_fuel += gas[(i+j)%n];
//                 rem_fuel -= cost[(i+j)%n];
//                 //after the trip 
//                 if(rem_fuel < 0){
//                     round_trip = false;
//                     break;
//                 }
//             }
//             if(round_trip) return i;
//         }
//         return -1;
//     }
// };