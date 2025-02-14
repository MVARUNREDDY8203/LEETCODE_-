class ProductOfNumbers {
public:
    int stream[40002];
    int prod_stream[40002];
    int zeros = -1;
    int idx = 1;
    ProductOfNumbers() {
        prod_stream[0] = 1;
        stream[0] = -1;
    }
    
    void add(int num) {
        stream[idx] = num;
        if (num == 0) {
            zeros = (idx);
            prod_stream[idx] = 1;
        } else {
            prod_stream[idx] = prod_stream[idx-1] * stream[idx];
        }
        idx++;
    }
    
    int getProduct(int k) {
        int n = idx-1;
        int first_idx = n - k + 1;
        if (zeros >= first_idx) return 0;

        return prod_stream[n] / prod_stream[n-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */