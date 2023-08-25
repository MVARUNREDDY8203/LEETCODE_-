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
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas=0,total_cost=0;
        int curr_gas=0, starting_point=0;
        for(int i=0;i<n;i++)
        {
            //these two variable are to check if no case is possible
            total_gas+=gas[i];
            total_cost+=cost[i];
            //for checking the total present gas at index i
            curr_gas+=gas[i]-cost[i];
            if(curr_gas<0)
            {
               //there is a breakdown....so we will start from next point or index
                starting_point=i+1;
                //reset our fuel 
                curr_gas=0;
            }
        }
        return (total_gas<total_cost)?-1:starting_point;     
    }
};