class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        Node* curr = head;
        while(curr != NULL){
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr != NULL){
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }

        curr = head;
        return mp[curr];
    }
};


// class Solution {
// public:
//     int depth_finder(Node* curr, Node* target){
//         if(target == NULL) return 2000;
//         if(curr == target) return 0;
//         return 1 + depth_finder(curr->next, target);
//     }
//     Node* copyRandomList(Node* head) {
//         if(head == NULL) return head;

//         //creating a ll copy with head 2
//         Node* curr = head;
//         Node* head2 = new Node(head->val);
//         Node* prev = head2;
//         curr = curr->next;
//         vector<pair<Node*, int>> dir;
//         dir.push_back({head2,-1});
//         int n = 1;

//         while(curr != NULL){
//             Node* temp = new Node(curr->val);
//             prev->next  = temp;
//             dir.push_back({temp, -1});
//             prev = temp;
//             curr = curr->next;
//             n++;
//         }

//         //finding random ptrses pointing addrs
//         curr = head;
//         int index = 0;
//         while(curr != NULL){
//             dir[index].second = depth_finder(head, curr->random);
//             curr = curr->next;
//             index++;
//         }
        
//         Node* temp3 = head2;
//         for(int i=0; i<dir.size(); i++){
//             if(dir[i].second != 2000) temp3->random = dir[dir[i].second].first;
//             else temp3->random = NULL;
//             temp3 = temp3->next;
//         }
//         return head2;
//     }
// };