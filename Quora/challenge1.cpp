#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

void fly(vector<int> array, int k)
{
    if(k == 1)
    {
        for(int i = 0;i < array.size();i++)
            cout << 0 << endl;
        return;
    }
    
    vector<long long int> up(array.size(), 0);
    vector<long long int> down(array.size(), 0);
    up[0] = 1; down[0] = 1;
    unordered_map<int, int> upm;
    unordered_map<int, int> dpm;
    int count = 1;
    
    /*
     * calculate up, running time is O(n)
     * because each upm and up is assigned only once.
     */
    for(int i = 1;i < array.size();i++)
    {
        if(array[i] >= array[i-1])
        {
            count++;
            if(count == k && i < array.size() - 1)
            {
                upm[i - k + 1] = i;
                count--;
                up[i] = k;
            } else if(i == array.size()-1) {
                for(int j = 0; j < count;j++)
                {
                    upm[i - count + j + 1] = i;
                    up[i] = min(up[i-1]+1,(long long int)k);
                }
            } else {
                up[i] = up[i-1]+1;
            }
        } else {
            for(int j = 0; j < count;j++)
                upm[i - count + j] = i - 1;
            up[i] = 1;
            count = 1;
            if(i == array.size()-1)
                upm[i] = i;
        }
    }
    
    //calculate down
    count = 1;
    for(int i = 1;i < array.size();i++)
    {
        if(array[i] <= array[i-1])
        {
            count++;
            if(count == k && i < array.size() - 1)
            {
                dpm[i - k + 1] = i;
                count--;
                down[i] = k;
            } else if(i == array.size()-1) {
                for(int j = 0; j < count;j++)
                {
                    dpm[i - count + j + 1] = i;
                    down[i] = min(down[i-1]+1,(long long int)k);
                }
            } else {
                down[i] = down[i-1]+1;
            }
        } else {
            for(int j = 0; j < count;j++)
                dpm[i - count + j] = i - 1;
            down[i] = 1;
            count = 1;
            if(i == array.size()-1)
                dpm[i] = i;
        }
    }
    
    /*
     for(int i = 0;i < array.size();i++)
     {
     cout << up[i] << " " << upm[i] << " " << down[i] << " " << dpm[i] << endl;
     }*/
    
    int i(0);
    long long int count1(0),count2(0);
    while(i < k)
    {
        int u = min(upm[i],k-1);
        count1 += up[u]*(up[u]-1)/2;
        i = u+1;
        cout << count1 << endl;
    }
    i = 0;
    while(i < k)
    {
        int u = min(dpm[i],k-1);
        count2 += down[u]*(down[u]-1)/2;
        i = u+1;
    }
    //cout << count1 << " ";cout << count2 << endl;
    cout << count1 - count2 << endl;
    
    for(i = 1;i <= array.size() - k;i++)
    {
        int v = up[upm[i-1]];
        count1 -= (v-1);
        up[upm[i-1]]--;
        int nextindex = i + k - 1;
        count1 += up[nextindex]-1;
        //cout << count1 << " ";
        v = down[dpm[i-1]];
        count2 -= (v-1);
        down[dpm[i-1]]--;
        count2 += down[nextindex]-1;
        //cout << count2 << endl;
        cout << count1 - count2 << endl;
    }
    
}


int main()
{
    int N,K; cin >> N >> K;
    vector<int> v(N,0);
    for(int i = 0;i < N;i++)
        cin >> v[i];
    fly(v, K);
    return 0;
}
