double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if(nums2Size<nums1Size){
        return findMedianSortedArrays(nums2,nums2Size,nums1,nums1Size);
    }
    int m= nums1Size;
    int n= nums2Size;
    //this is partition ,can be placed at start, between and end (so low=0 and high=m)
    int low=0;
    int high=m;
    while(low<=high){
        int p1=(low+high)/2;
        int p2=(m+n+1)/2-p1;

        //for nums1
        int maxleft1=(p1==0)?INT_MIN:nums1[p1-1];
        int minright1=(p1==m)?INT_MAX:nums1[p1];

        //for nums2
        int maxleft2=(p2==0)?INT_MIN:nums2[p2-1];
        int minright2=(p2==n)?INT_MAX:nums2[p2];

        if(maxleft1 <= minright2 && maxleft2 <= minright1){
            if((m+n)%2!=0){
                return (maxleft1>maxleft2)?maxleft1:maxleft2;
            }
            else{
                int l=(maxleft1>maxleft2)?maxleft1:maxleft2;
                int r=(minright1<minright2)?minright1:minright2;
                return (l+r)/2.0;
            }
        }
        else if(maxleft1 > minright2) {
            high=p1-1;
        }
        else{
            low=p1+1;
        }
    }
    return 0.0;
}