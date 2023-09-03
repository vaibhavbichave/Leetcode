class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0, j=0, lastindex=0, n=n1+n2;
        
        vector<int>v(n1+n2,0);
        
        while(i<n1&&j<n2){
            if(nums1[i]<=nums2[j]) v[lastindex++]=nums1[i++];
            else v[lastindex++]=nums2[j++];
        }
        
        while(i<n1) v[lastindex++]=nums1[i++];
        while(j<n2) v[lastindex++]=nums2[j++];
     
        return n%2?v[n/2]:(v[n/2]+v[n/2-1])/2.0;   
    }
};