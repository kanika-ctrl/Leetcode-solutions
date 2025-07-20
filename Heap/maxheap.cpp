int parent(int index){
    return (index-1)/2;
}
int left(int index){
    return 2*index+1;
}
int right(int index){
    return 2*index+2;
}
void swap(vector<int> heap,int i,int j){
    int temp=heap[i];
    heap[i]=heap[j];
    heap[j]=temp;
}
void bottom_up(vector<int>&heap,int index){
    if(index==0) return;
    int p=parent(index);
    if(heap[p]>heap[index]){
        swap(heap,p,index);
        bottom_up(heap,p);
    }
}


int parent(int index){
    return (index-1)/2;
}
int left(int index){
    return 2*index+1;
}
int right(int index){
    return 2*index+2;
}
void swap(vector<int> heap,int i,int j){
    int temp=heap[i];
    heap[i]=heap[j];
    heap[j]=temp;
}
void bottom_up(vector<int>&heap,int index){
    if(index==0) return;
    int p=parent(index);
    if(heap[p]<heap[index]){
        swap(heap,p,index);
        bottom_up(heap,p);
    }
}


