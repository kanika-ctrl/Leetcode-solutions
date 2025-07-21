class Solution {
    public:
    int left(int idx){
        return 2*idx+1;
    }
    int right(int idx){
        return 2*idx+2;
    }
    void swap(vector<int>& heap,int i,int j){
        int temp=heap[i];
        heap[i]=heap[j];
        heap[j]=temp;
    }
    void downheap(vector<int> &heap,int idx){
        //downheap method
        int l=left(idx);
        int r=right(idx);
        int i=idx;
        if(l<heap.size()&&heap[l]>heap[i]){
            i=l;
        }
        if(r<heap.size()&&heap[r]>heap[i]){
            i=r;
        }
        if(i!=idx){
            swap(heap,i,idx);
            downheap(heap,i);
        }
    }
        vector<int> minToMaxHeap(vector<int> heap) {
           int n=heap.size();
           for(int i=(n-2)/2;i>=0;i--){
              downheap(heap,i);
           }
           return heap;
        }
    };