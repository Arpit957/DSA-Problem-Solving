class SmallestInfiniteSet {
public:
  set<int> st;
    SmallestInfiniteSet() {
        for(int i =1;i<=1000;i++) st.insert(i);
    }
    
    int popSmallest() {
        int a = *st.begin();
        st.erase(a);
        return a;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};
