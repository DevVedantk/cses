class Solution {
  public:

vector<int>fen;

void update(int idx,int x,int n){
    while(idx<=n){
        fen[idx]+=x;
        idx+=(idx&-idx);
    }
}

int sum(int idx){
    int s=0;
    while(idx>0){
        s+=fen[idx];
        idx-=(idx&-idx);
    }
    return s;
}  
  
    int inversionCount(vector<int> &arr) {
        int n=arr.size();
    // vector<int>arr(n);
    int maxe=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        maxe=max(maxe,arr[i]);
    }
    
    int size=maxe+1;
    fen.assign(size,0);
    
    
    
    for(int i=0;i<n;i++){
        cnt+=(sum(maxe)-sum(arr[i]));
        update(arr[i],1,maxe);
    }
    return cnt;
        
    }
};