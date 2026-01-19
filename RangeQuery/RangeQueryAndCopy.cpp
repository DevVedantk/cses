#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct Node{
   int sum=0;
   Node* left=NULL;
   Node* right=NULL;
};

vector<Node*>Nodes_list;

Node* buildt(int l,int r,vector<int>&arr){
     if(l==r){
         Node* leaf=new Node();
         leaf->sum=arr[l];
         return leaf;
     }
     
     Node* node=new Node();
     
     int mid=(l+r)/2;
     Node* leftn=buildt(l,mid,arr);
     Node* rightn=buildt(mid+1,r,arr);
     node->sum=leftn->sum+rightn->sum;
     node->left=leftn;
     node->right=rightn;
     return node;
}

int query(int l,int r,int st,int en,Node* node){
   if(st>r || l>en) return 0;
   if(l>=st && r<=en) return node->sum;
   
   int mid=(l+r)/2;
   int left_sum=query(l,mid,st,en,node->left);
   int right_sum=query(mid+1,r,st,en,node->right);
   return (left_sum + right_sum);
}
Node* update(Node* past,int l,int r,int idx,int val){
     if(l==r){
         Node* leaf=new Node();
         leaf->sum=val;
         return leaf;
     }
     
     int mid=(l+r)/2;
     Node* node=new Node();
     if(idx<=mid){
         //go left;
         node->left=update(past->left,l,mid,idx,val);
         node->right=past->right;
         node->sum=(node->left->sum+node->right->sum);
         return node;
     } else{
         //go right
         node->right=update(past->right,mid+1,r,idx,val);
         node->left=past->left;
          node->sum=(node->left->sum+node->right->sum);
          return node;
     }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    
    Node* root=buildt(0,n-1,arr);
    Nodes_list.push_back(root);
    
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==1){
         int k,idx,val;
         cin >> k >> idx >> val;
         idx--;
         k--;
         Node* past_node=Nodes_list[k];
         Node* new_node=update(past_node,0,n-1,idx,val);
         Nodes_list[k]=new_node;
        } else if(t==2){
            int k,a,b;
            cin >> k >> a >> b;
            a--;b--;k--;
            cout << query(0,n-1,a,b,Nodes_list[k]) << endl;
        } else{
            int k;
            cin >> k;
            k--;
            Node* node=Nodes_list[k];
            Nodes_list.push_back(node);
        }
    }
    
}