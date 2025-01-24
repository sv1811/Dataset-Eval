class Solution {
public:
    int trap(vector<int>& arr) {
        int maxi=INT_MIN; int first=-1;int last=-1;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]>maxi)
            {
                maxi=arr[i]; first=i; last=i;
            }
            else if(arr[i]==maxi) last=i;
        }
        int ans=0;
        int cur=arr[0];
        for(int i=1;i<=first;i++)
        {
            if(cur>=arr[i]) ans+=abs(arr[i]-cur);
            else cur=arr[i];
        }
        cur=arr[n-1];
        for(int i=n-2;i>=last;i--)
        {
            if(cur>=arr[i]) ans+=abs(arr[i]-cur);
            else cur=arr[i];
        }
        if(first==last) return ans;
        else
        {
            cur=arr[first];
            for(int i=first+1;i<=last;i++)
            {
                if(cur>=arr[i]) ans+=abs(arr[i]-cur);
                else cur=arr[i];
            }
            return ans;
        }
    }
};
