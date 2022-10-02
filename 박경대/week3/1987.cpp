// 시간초과 코드
// #include<iostream>
// #include<vector>
// using namespace std;
// int R,C;
// char map[20][20];
// int dy[4] = {-1,1,0,0}; //위 아래 좌 우
// int dx[4] = {0,0,-1,1}; //위 아래 좌 우
// int max_ = 0;
// vector<char> alphabets;
// void dfs(int current_y, int current_x, int count){
//     for(int i=0;i<4;i++){
//         bool duplicate = false;
//         int nexty = current_y + dy[i];
//         int nextx = current_x + dx[i];
//         if(nexty>=0 && nexty<R && nextx>=0 && nextx<C){
//             for(int j=0;j<alphabets.size();j++){
//                 if(alphabets[j]==map[nexty][nextx]){
//                     duplicate = true;
//                     break;
//                 }
//             }
//             if(!duplicate){
//                 alphabets.push_back(map[nexty][nextx]);
//                 dfs(nexty,nextx,count+1);
//                 alphabets.pop_back(); 
//             }
//         }
//     }
//     if(max_ < count){
//         max_ = count;
//         return;
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie();
//     cout.tie(); 
//     cin>>R>>C;
//     for(int y=0;y<R;y++){
//         for(int x=0;x<C;x++){
//             cin>>map[y][x]; 
//         }
//     }
//     int count = 1;
//     alphabets.push_back(map[0][0]);
//     dfs(0,0,count);
//     cout<<max_;
// }

#include<iostream>
#include<vector>
using namespace std;
int R,C;
char map[20][20];
int dy[4] = {-1,1,0,0}; //위 아래 좌 우
int dx[4] = {0,0,-1,1}; //위 아래 좌 우
int max_ = 0;
bool visited[26];
void dfs(int current_y, int current_x, int count){
    for(int i=0;i<4;i++){
        bool duplicate = false;
        int nexty = current_y + dy[i];
        int nextx = current_x + dx[i];
        if(nexty>=0 && nexty<R && nextx>=0 && nextx<C){
            if(!visited[map[nexty][nextx] - 'A']){
                visited[map[nexty][nextx] - 'A'] = true;
                dfs(nexty,nextx,count+1);
                visited[map[nexty][nextx] - 'A']=false;
            }
        }
    }
    if(max_ < count){
        max_ = count;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie(); 
    cin>>R>>C;
    for(int y=0;y<R;y++){
        for(int x=0;x<C;x++){
            cin>>map[y][x]; 
        }
    }
    int count = 1;
    visited[map[0][0]-'A'] = true;
    dfs(0,0,count);
    cout<<max_;
}