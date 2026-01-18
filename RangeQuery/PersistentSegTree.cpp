#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct Node{
    int val=0;
    Node* left=NULL;
    Node* right=NULL;
};

vector<Node*>all;


Node* buildt(int l,int r){
    if(l==r){
       Node* leaf=new Node();
       leaf->val=0;
       return leaf;
    }
    
    Node* node=new Node();
    int mid=(l+r)/2;
    // node.val=arr[mid];
    
    Node* leftN=buildt(l,mid);
    Node* rightN=buildt(mid+1,r);
    node->val=leftN->val+rightN->val;
    node->left=leftN;
    node->right=rightN;
    return node;
}

Node* update(int idx,int l,int r,int new_val,Node* last_segtree){
    if(l==r){
        Node* leaf=new Node();
        leaf->val=new_val;
        return leaf;
    }
    
    Node* node=new Node();
    int mid=(l+r)/2;
    if(idx<=mid){
       //left
       Node* leftN=update(idx,l,mid,new_val,last_segtree->left);
       Node* rightN=last_segtree->right;
       node->val=leftN->val+rightN->val;
       node->left=leftN;
       node->right=rightN;
       return node;
    } else{
        Node* rightN=update(idx,mid+1,r,new_val,last_segtree->right);
        Node* leftN=last_segtree->left;
       node->val=leftN->val+rightN->val;
       node->left=leftN;
       node->right=rightN;
       return node;
    }
}

int query(Node* past,Node* curr,int l,int r,int k){
    
    if(l==r){
        return l;
    } else{
        int mid=(l+r)/2;
        int myseg=curr->left->val - past->left->val;
        if(k<=myseg) return query(past->left,curr->left,l,mid,k);
        else return query(past->right,curr->right,mid+1,r,k-myseg);
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    
    //persistent seg tree implementation
    int n,q;
    cin >> n >> q;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    
    

    Node* root=buildt(0,n-1);
     all.push_back(root);  
    
    vector<pair<int,int>>sorted;
    for(int i=0;i<n;i++){
        sorted.push_back({i,arr[i]});
    }
   sort(sorted.begin(), sorted.end(), [](const pair<int,int>& a,
                                      const pair<int,int>& b){
    return a.second < b.second;
});
    
    vector<int>treeidx(n);
    for(int i=0;i<n;i++){
        treeidx[sorted[i].first]=i;
    }
     
     for(int i=0;i<n;i++){
           int size=all.size();
         Node* root=update(treeidx[i],0,n-1,1,all[size-1]);
         all.push_back(root);
     }
     
   //query
    for(int i=0;i<q;i++){
        int a,b,val;
        cin >> a >> b >> val;
        a--;b--;
        int size=all.size();
      
        int ans=query(all[a],all[b+1],0,n-1,val);
        cout << sorted[ans].second << endl;
    }
    
    // cout << "hello" << endl;
    
}