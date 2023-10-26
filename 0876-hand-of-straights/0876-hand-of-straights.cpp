class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        int n = hand.size();
        if (n % gs) return false;
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> ump;
        for (int x: hand) ump[x]++;
        for (auto it: ump) pq.push(it.first);

        while (!pq.empty()) {
            int value = pq.top();
            cout<<pq.top()<<endl;
            if (ump.find(value) == ump.end()) {
                pq.pop();
                continue;
            };
            if (ump[value] <= 0) {
                ump.erase(value);
                continue;
            }
            ump[value]--;
            for (int i = 1; i < gs; i++) {
                if (ump.find(value + i) == ump.end()) return false;
                ump[value+i]--;
                if (ump[value+i] <= 0) ump.erase(value+i);
            }
        }
        return true;
    }
};



// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         int n = hand.size();
//         if (n%groupSize != 0) return false;

//         map<int, int> ump2;
//         for (int i=0; i<n; i++) {
//             ump2[hand[i]]++;
//         }
        
//         while (true) {
//             if (ump2.empty()) return true;
//             int value = ump2.begin()->first;
//             for (int j = 1; j<groupSize; j++) {
//                 if (ump2.find(value+j) == ump2.end()) return false;
//                 ump2[value+j]--;
//                 if (ump2[value+j] <= 0) ump2.erase(value+j);
//             }
//             ump2[value]--;
//             if (ump2[value] <= 0) ump2.erase(value);
//         }    
//         return true;
//     }
// };


// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         int n = hand.size();
//         if (n%groupSize != 0) return false;

//         set<int> ust;
//         unordered_map<int, int> ump2;
//         for (int i=0; i<n; i++) {
//             ust.insert(hand[i]);
//             ump2[hand[i]]++;
//         }
        
//         while (true) {
//             if (ust.empty()) return true;
//             int value = *ust.begin();
//             for (int j = 1; j<groupSize; j++) {
//                 if (ust.find(value+j) == ust.end() || ump2.find(value+j) == ump2.end() || ump2[value+j] <= 0) return false;
//                 ump2[value+j]--;
//                 if (ump2[value+j] <= 0) ust.erase(value+j);
//             }
//             ump2[value]--;
//             if (ump2[value] <= 0) ust.erase(value);
//         }    
//         return true;
//     }
// };


// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         int n = hand.size();
//         if (n%groupSize != 0) return false;
//         sort(hand.begin(), hand.end());

//         for (int i=0; i<n; i++) {
//             if (hand[i] != -1) {
//                 int k = 0;
//                 int ref = hand[i];
//                 for (int j=i; j<n && k < groupSize; j++) {
//                     if (hand[j] == ref + k) {
//                         hand[j] = -1;
//                         k++;
//                     }
//                 }
//                 if (k < groupSize) return false;
//             }
//         }
//         for (auto i : hand) if (i != -1) return false;
//         return true;
//     }
// };