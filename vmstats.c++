#include <bits/stdc++.h>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>
#define MAX_SIZE 10000

using namespace std;



vector<int> arr;



void print_vector(vector<int> &cache,int i,int frames){
    cout<<arr[i]<<": [";
    int s=cache.size();
    int c=0;
    for(int j=0;j<s;j++){
        if(c==frames-1){
            if(cache[j]<10){
                cout<<" "<<cache[j]<<"]  F"<<endl;
            }else{
                cout<<cache[j]<<"]  F";
            }
        }else{
            if(cache[j]<10){
                cout<<" "<<cache[j]<<"|";
            }else{
                cout<<cache[j]<<"|";
            }
        }

        
        c++;
    }
    int temp = frames - c -1;
    
    for(int j=0;j<temp;j++){
        cout<<"  "<<"|";
    }
    if(c<frames)
        cout<<"  ]  F"<<endl;
}

float opt(int frames) {
     int count = arr.size();
    vector<int> cache;
    int hit=0;
    int miss=0;
    int c=0;
    int i;
    for(i=0;i<count && c<frames;i++){
        auto it = find(cache.begin(),cache.end(),arr[i]);
        if(it == cache.end()){
            cache.push_back(arr[i]);
            c++;
        }
        //print_vector(cache,i,frames);
        
    }

    for(i;i<count;i++){
        auto it = find(cache.begin(),cache.end(),arr[i]);
        if(it != cache.end()){
            hit++;
            //print_vector(cache,i,frames);
        }else{
            miss++;
             auto far = arr.begin();
            int s = cache.size();
            for(int j=0;j<s;j++){
                auto it1 = find(arr.begin()+i,arr.end(),cache[j]);
                if(it1==arr.end()){
                    far = cache.begin() + j;
                    break;
                }
                if(far<it1){
                    far=cache.begin()+j;
                }
                   // far=it1;
            }
            cache.erase(far);
            cache.push_back(arr[i]);
           // print_vector(cache,i,frames);
        }
    }
    float miss_rate = 100*((float)miss)/(count-frames);
    cout<<"Miss rate = "<<miss<<"/"<<count-frames<<" = "<<miss_rate<<" %"<<endl;
    return miss_rate;
}

float lru(int frames) {
    int count = arr.size();
    vector<int> cache;
    int hit=0;
    int miss=0;
    int i,c=0;
    for(i=0;i<count && c<frames;i++){
        auto it = find(cache.begin(),cache.end(),arr[i]);
        if(it == cache.end()){
            cache.push_back(arr[i]);
            c++;
        }
        //print_vector(cache,i,frames);
        
    }

    for( i;i<count;i++){
        auto it = find(cache.begin(),cache.end(),arr[i]);
        if(it != cache.end()){
            hit++;
            cache.erase(it);
            cache.push_back(arr[i]);
            //print_vector(cache,i,frames);
        }else{
            miss++;
            cache.erase(cache.begin());
            cache.push_back(arr[i]);
            //print_vector(cache,i,frames);
        }
    }
    float miss_rate = 100*((float)miss)/(count-frames);
    cout<<"Miss rate = "<<miss<<"/"<<count-frames<<" = "<<miss_rate<<" %"<<endl;
    return miss_rate;
}



float fifo(int frames) {
    int count = arr.size();
    vector<int> cache;
    int hit=0;
    int miss=0;
    int i,c=0;
    for(i=0;i<count && c<frames;i++){
        auto it = find(cache.begin(),cache.end(),arr[i]);
        if(it == cache.end()){
            cache.push_back(arr[i]);
            c++;
        }
       // print_vector(cache,i,frames);
        
    }

    for( i;i<count;i++){
        auto it = find(cache.begin(),cache.end(),arr[i]);
        if(it != cache.end()){
            hit++;
           // print_vector(cache,i,frames);
        }else{
            miss++;
            cache.erase(cache.begin());
            cache.push_back(arr[i]);
           // print_vector(cache,i,frames);
        }
    }
    float miss_rate = 100*((float)miss)/(count-frames);
    cout<<"Miss rate = "<<miss<<"/"<<count-frames<<" = "<<miss_rate<<" %"<<endl;
    return miss_rate;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        cout << "USAGE: invalid arguments!!:number of argument" << endl;
        exit(1);
    }
    int min_frames,max_frames,inc;
    min_frames = atoi(argv[1]);
    max_frames = atoi(argv[2]);
    inc = atoi(argv[3]);
    char *file_name, *algo;
    file_name = argv[4];
    
    
    if (max_frames > 100) {
        cout << "USAGE: invalid arguments!!:max frames" << endl;
        exit(1);
    }
    if (min_frames < 2) {
        cout << "USAGE: invalid arguments!!:min frames" << endl;
        exit(1);
    }
    if (max_frames < 0) {
        cout << "USAGE: invalid arguments!!:inc" << endl;
        exit(1);
    }

   

    ifstream file(file_name);
    if (!file.is_open()) {
        cout << "USAGE: The file is not opened. enter correct file name." << endl;
        exit(1);
    }

    int number;
    while (file >> number) {
        arr.push_back(number);
    }
    ofstream outfile;
    outfile.open("vmrates.dat");
    if (!outfile.is_open()) {
        cout << "The file is not opened. The program will now exit." << endl;
        exit(0);
    }

    for(int i=min_frames;i<max_frames;i+=inc){
        outfile << i << " ";
    }
    outfile<<"\n";
    for(int i=min_frames;i<max_frames;i+=inc){
        cout<<"opt, "<<i<<" frames:";
        outfile << opt(i) << " ";
    }
     outfile<<"\n";
    for(int i=min_frames;i<max_frames;i+=inc){
        cout<<"lru, "<<i<<" frames:";
        outfile << lru(i) << " ";
    }
     outfile<<"\n";
    for(int i=min_frames;i<max_frames;i+=inc){
        cout<<"fifo, "<<i<<" frames:";
        outfile << fifo(i) << " ";
    }
    file.close();
    return 0;
}
