#include<bits/stdc++.h>
using namespace std;
/*Good approach using max heap:
TC=O(N+NlogN+result)
SC=O(N+N)*/
int leastInterval(vector<char>& tasks, int n) {
    ios_base::sync_with_stdio(false);
    unordered_map<char,int> mp;
    for(char c:tasks) mp[c]++;//O(N)
    priority_queue<int> pq;
    for(auto it:mp) pq.push(it.second);//O(NlogN)
    int result=0;
    while(!pq.empty())//O(result)
    {
        int time=0;
        vector<int> temp;
        for(int i=0;i<n+1;i++)
        {
            if(!pq.empty())
            {
                temp.push_back(pq.top()-1);
                pq.pop();
                time++;
            }
        }
        for(auto it:temp)
        {
            if(it) pq.push(it);
        }
        result+=(pq.empty())?time:n+1;
    }
    return result;
}

/*Optimal Approach=>
TC=O(N)
SC=O(N)

----------------------------------Explaination---------------------------------------------------------
fre-1 isliye kiya hai kyonki maanlo for example AB_AB_A  hai to A 3 times aaraha hai to humne sirf
2 A ke dibbo ko count kiya hai, A ko mila ke n+1 size ke hojaayenge woh dibbe:
i) 1-> AB_ 
   2-> AB_

aur aakhir mwin ans ko add kiya hai kyonki humne bas last A ko add kardiya
Humne last A ka dibba isliye nahi liya kyonki uske baad idle spaces ka kya karenge kyonki saare toh 
tab tak bhar hi diye honge

Aur maanlo ki Aakhir A ke baad bhi daalne ki zaroorat pad rahi hai, toh aisa tab hi ho sakta hai
jab hamare paas bohot saare tasks ho alag alag, uss case mein tasks.size() hi time ho jaayega
kyonki hamare paas select karne ko bohot choices this n gap waale samay ke liye

Example AB_AB_AB
toh do dibbe liye aur aakhir mein ans =2 add kiya kyonki AB baaki the.
Ek baar khud chala le dekho_________ samjh aajayega.

Nahi toh yeh document poora padhlo dimaag laga ke, samjh aajyega
link of document: https://ericwannn.github.io/2018/06/26/leetcode-task-scheduler/  */
int leastInterval1(vector<char>& tasks, int n) {
    ios_base::sync_with_stdio(false);
    unordered_map<char,int> mp;
    int fre=0,ans=0;
    for(auto t:tasks) fre=max(fre,++mp[t]);//map mein daalne ka O(1)
    for(auto it:mp) if(it.second==fre) ans++;
    return max((int)tasks.size(),ans+((fre-1)*(n+1)));
}
int main() {
    // Sample inputs
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'C'};
    int n = 2;

    // Call leastInterval function
    int result = leastInterval1(tasks, n);

    // Output the result
    cout << "Minimum intervals required: " << result << endl;

    return 0;
}
