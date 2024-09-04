class NumArray {
public:
    vector<int> st;
    vector<int> A;
    void build(int idx, int l, int r) {
        if (l == r) {
            st[idx] = A[l];
            return;
        }
        int mid = (l+r)/2;
        build(2 * idx, l, mid);
        build(2 * idx+1, mid+1, r);

        st[idx] = st[2*idx] + st[2*idx+1];
    }
    int query(int idx, int tl, int tr, int l, int r) {
        if (r < tl || l > tr) return 0;
        if (l <= tl && r >= tr) return st[idx];

        int mid = (tl + tr) / 2;
        return query(idx*2, tl, mid, l, r) + query(idx*2+1, mid+1, tr, l, r);
    }
    void st_update(int idx, int update_idx, int l, int r, int update_val) {
        if (l == r) {
            // A[update_idx] = update_val;
            st[idx] = update_val;
            return;
        }      

        int mid = (l+r)/2;

        if (update_idx >= l && update_idx <= mid) {
            st_update(idx*2, update_idx, l, mid, update_val);
        }   
        else {
            st_update(idx*2+1, update_idx, mid+1, r, update_val);
        }

        st[idx] = st[idx*2] + st[idx*2+1];
    }
    NumArray(vector<int>& nums) {
        int n = nums.size();
        st.resize(4*n+1);
        for (auto i: nums) A.push_back(i);

        build(1,0,n-1);
    }
    
    void update(int index, int val) {
        st_update(1 ,index, 0, A.size()-1, val);
    }
    int sumRange(int l, int r) {
        return query(1, 0, A.size()-1, l, r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */