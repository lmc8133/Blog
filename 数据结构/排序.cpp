#include<vector>
#include<algorithm>
#include<iostream>
#include<random>
#include<cstdlib>
#include<ctime>
using namespace std;

void bubble_sort(vector<int>num){
    int n=num.size();
    int flag;
    for(int i=n-1; i>=0; --i){
        flag=0;
        for(int j=0; j<i; ++j){
            if(num[j+1]<num[j]){
                swap(num[j],num[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
    cout<<"Bubble_Sort"<<endl;
    for(int i=0; i<n; ++i){
        cout<<num[i]<<" ";
    }
    cout<<endl<<endl;
    return;
}

void selection_sort(vector<int>num){
    int n=num.size();
    for(int i=0; i<n; ++i){
        int min=num[i], p=i;
        for(int j=i+1; j<n; ++j){
            if(num[j]<min){
                min=num[j];
                p=j;
            }
        }
        swap(num[i],num[p]);
    }
    cout<<"Selection_Sort"<<endl;
    for(int i=0; i<n; ++i){
        cout<<num[i]<<" ";
    }
    cout<<endl<<endl;
    return;
}

void insert_sort(vector<int>num){
    int n=num.size();
    for(int i=0; i<n; ++i){
        int t=num[i],p=i-1;
        for(; p>=0; --p){
            if(num[p]>t){
                num[p+1]=num[p];
            }
            else{
                break;
            }
        }
        num[p+1]=t;
    }
    cout<<"Insert_Sort"<<endl;
    for(int i=0; i<n; ++i){
        cout<<num[i]<<" ";
    }
    cout<<endl<<endl;
    return;
}

void quickSort(vector<int>&num, int l, int r){
    if(l<r){
        srand(time(NULL));
        int p=(int)rand()%(r-l+1)+l;
        // cout<<"p: "<<p<<endl;
        swap(num[l],num[p]);
        int pivot=num[l];
        int i=l,j=r;
        while(i<j){
            while(i<j&&num[j]>pivot){
                --j;
            }
            if(i<j){
                num[i]=num[j];
                ++i;
            }
            while(i<j&&num[i]<pivot){
                ++i;
            }
            if(i<j){
                num[j]=num[i];
                --j;
            }
        }
        num[i]=pivot;
        quickSort(num,l,i-1);
        quickSort(num,i+1,r);
    }
}

void quick_sort(vector<int>num){
    int n=num.size();
    quickSort(num,0,n-1);
    cout<<"Quick_Sort"<<endl;
    for(int i=0; i<n; ++i){
        cout<<num[i]<<" ";
    }
    cout<<endl<<endl;
    return;
}

void merge(vector<int>&num, int l, int m, int r){
    vector<int>t(r-l+1);
    int i=l,j=m+1,k=0;
    while(i<=m&&j<=r){
        if(num[i]<num[j]){
            t[k]=num[i];
            ++i;
        }
        else{
            t[k]=num[j];
            ++j;
        }
        ++k;
    }
    while(i<=m){
        t[k]=num[i];
        ++i;
        ++k;
    }
    while(j<=r){
        t[k]=num[j];
        ++j;
        ++k;
    }
    for(int i=0; i<k; ++i){
        num[l+i]=t[i];
    }
}

void mergeSort(vector<int>&num, int l, int r){
    if(l>=r){
        return;
    }
    int m=(r-l)/2+l;
    mergeSort(num,l,m);
    mergeSort(num,m+1,r);
    merge(num,l,m,r);
}

void merge_sort(vector<int>num){
    int n=num.size();
    mergeSort(num,0,n-1);
    cout<<"Merge_Sort"<<endl;
    for(int i=0; i<n; ++i){
        cout<<num[i]<<" ";
    }
    cout<<endl<<endl;
    return;
}

int main(){
    vector<int>demo;
    int num;
    while(cin>>num){
        demo.emplace_back(num);
    }
    bubble_sort(demo);
    selection_sort(demo);
    insert_sort(demo);
    quick_sort(demo);
    merge_sort(demo);
    return 0;
}
